
all:

get_leros:
	git clone git://github.com/schoeberl/leros.git

tools:
	cd leros && make tools

compile:
#	cd leros/LerosMuviumSDK && makeTest.bat
	cd leros && make java_app -e JAPP=TestNoc

asemble:
	cd leros && make rom -e APP=../asm/muvium

build:
	cd leros && make rom -e APP=io
#	cd leros && make java_app -e JAPP=Test
#	cd leros && make rom -e APP=muvium

sim:
	cd noc && make base
	cd noc && make sim

