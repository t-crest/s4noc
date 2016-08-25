PROJNAME = skeleton
MAIN = skeleton.Skeleton
MODULE ?= MAIN

HWBUILDDIR ?= $(CURDIR)/hwbuild
BOARD ?= altde2-115
CHISELSRC = $(shell find chisel -name '*.scala')
SBT = sbt

all: verilog

verilog: $(CHISELSRC)
	$(SBT) "run-main $(MAIN) --targetDir $(HWBUILDDIR) --backend v"

synth: verilog
	quartus_map quartus/$(BOARD)/$(PROJNAME)
	quartus_fit quartus/$(BOARD)/$(PROJNAME)
	quartus_asm quartus/$(BOARD)/$(PROJNAME)
	quartus_sta quartus/$(BOARD)/$(PROJNAME)

config:
	scripts/config_altera -b USB-Blaster quartus/$(BOARD)/$(PROJNAME).sof

clean:
	rm -rf $(HWBUILDDIR)

distclean: clean
	rm -rf project target
	find quartus/$(BOARD) -type f ! -name '*.qpf' -and ! -name '*.qsf' -exec rm {} \;
	find quartus/$(BOARD) -mindepth 1 -type d | xargs rm -rf

modtest:
	$(SBT) "run-main $(MODULE) --cse --backend c --compile --vcd --test --genHarness --targetDir $(HWBUILDDIR)"

modcomp:
	$(SBT) "run-main $(MODULE) --cse --backend v --compile --vcd --targetDir $(HWBUILDDIR)"

view:
	gtkwave $(HWBUILDDIR)/$(MODULE).vcd $(HWBUILDDIR)/$(MODULE).gtkw
