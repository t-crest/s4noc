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
	$(WINE) vsom $(OPTIONS) $(S4NOCDIR)/router_ST.vhd
	$(WINE) vsom $(OPTIONS) $(S4NOCDIR)/ni_ST.vhd
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

tools:
	cd src && make
	
schedule:
	cd vhdl/generated/bt2x2 && ../../../src/STgen.exe 4 bt2x2.shd
	cd vhdl/generated/bt3x3 && ../../../src/STgen.exe 9 bt3x3.shd
	cd vhdl/generated/bt4x4 && ../../../src/STgen.exe 16 bt4x4.shd
	cd vhdl/generated/bt5x5 && ../../../src/STgen.exe 25 bt5x5.shd
	cd vhdl/generated/bt6x6 && ../../../src/STgen.exe 36 bt6x6.shd
	cd vhdl/generated/bt7x7 && ../../../src/STgen.exe 49 bt7x7.shd
	cd vhdl/generated/bt8x8 && ../../../src/STgen.exe 64 bt8x8.shd
	cd vhdl/generated/bt9x9 && ../../../src/STgen.exe 81 bt9x9.shd
	cd vhdl/generated/bt10x10 && ../../../src/STgen.exe 100 bt10x10.shd
	
sim: 
	@echo Starting simulation...
	$(WINE) vcom $(OPTIONS) $(S4NOCDIR)/simulation/tb_noc.vhd
	$(WINE) vsim -i -do $(S4NOCDIR)/simulation/noc_sim.do tb_noc

clean:
	-rm transcript
	-rm *.wlf
	-rm -r work
