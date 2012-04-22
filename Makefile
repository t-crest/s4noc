
# USB=true is only for the special dspio (and similar boards)
# with the FTDI chip for download
USB=false
# Altera FPGA configuration cable
#BLASTER_TYPE=ByteBlasterMV
BLASTER_TYPE=USB-Blaster

ifeq ($(WINDIR),)
	USBRUNNER=./USBRunner
	S=:
else
	USBRUNNER=USBRunner.exe
	S=\;
endif

# The VHDL project for Quartus
QPROJ=tile_test_alt

# start from scratch including checkout of Leros
all: get_leros build_all

get_leros:
	git clone git://github.com/schoeberl/leros.git

# build everything, Leros is already in place
build_all: tools compile assemble
	make s4nocusb
	make config

update_leros:
	cd leros && git pull

tools:
	cd leros && make tools

compile:
#	cd leros/LerosMuviumSDK && makeTest.bat
#	cd leros && make java_app -e JAPP=TestNoc
	cd leros && make java_app -e TARGET_SRC=../noc/src JAPP=Noc_test

assemble:
#	cd leros && make rom -e APP=../asm/muvium
	cd leros && make rom -e APP=../../noc/src/Noc_test

build:
	cd leros && make rom -e APP=io
#	cd leros && make java_app -e JAPP=Test
#	cd leros && make rom -e APP=muvium

sim:
	cd noc && make base
	cd noc && make sim

	
# configure the FPGA
config:
ifeq ($(USB),true)
	make config_usb
else
ifeq ($(XFPGA),true)
	make config_xilinx
else
	make config_altblaster
endif
endif

directories:
	-mkdir rbf

s4nocusb: directories
	@echo $(QPROJ)
	for target in $(QPROJ); do \
		make qsyn -e QBT=$$target || exit; \
		cd noc/quartus/$$target && quartus_cpf -c $(QPROJ).sof ../../../rbf/$$target.rbf; \
	done

#
#	Quartus build process
#		called by jopser, jopusb,...
#
qsyn:
	echo $(QBT)
	echo "building $(QBT)"
	-rm -rf noc/quartus/$(QBT)/db
	-rm -f noc/quartus/$(QBT)/$(QPROJ).sof
	-rm -f jbc/$(QBT).jbc
	-rm -f rbf/$(QBT).rbf
	quartus_map noc/quartus/$(QBT)/$(QPROJ)
	quartus_fit noc/quartus/$(QBT)/$(QPROJ)
	quartus_asm noc/quartus/$(QBT)/$(QPROJ)
	quartus_sta noc/quartus/$(QBT)/$(QPROJ)

config_altblaster:
	cd noc/quartus/$(QPROJ) && quartus_pgm -c $(BLASTER_TYPE) -m JTAG tile_test_alt.cdf

# this is only for a very special board, the dspio
config_usb:
	cd rbf && ../$(USBRUNNER) $(QPROJ).rbf
