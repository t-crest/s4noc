#
#	Makefile for s4noc ModelSim simulation
#


S4NOCDIR=./vhdl
LEROSDIR=../leros/vhdl
OPTIONS=-2008 -quiet
QUIET=@
N=4

ifeq ($(OS),)
	WINE=$(QUIET)wine
	S=:
else
	WINE=$(QUIET)
	S=\;
endif

all: clean base sim

base: leros
	@echo Building Base...
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/generic_noc_types.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/noc_N.vhd
#	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/noc_types.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/serdes.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/generated/bt$(N)x$(N)/router_ST.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/generated/bt$(N)x$(N)/ni_ST.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/dp_ram.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/ni_ram.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/ni_ram_single.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/outnode.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/router.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/tile.vhd
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/tile_top.vhd


leros:
	@echo Building Leros...
	$(WINE) vlib work
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/core/leros_types.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/io/uart.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/generated/leros_rom.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/core/leros_im.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/core/leros_decode.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/core/leros_fedec.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/core/leros_ex.vhd
	$(WINE) vcom $(OPTIONS) $(LEROSDIR)/core/leros.vhd

sim: 
	@echo Starting simulation...
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/simulation/tb_noc.vhd
	$(WINE) vsim -i -do $(S4NOCDIR)/simulation/noc_sim.do tb_noc

clean:
	-rm transcript
	-rm *.wlf
	-rm -r work
