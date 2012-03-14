
all:

get_leros:
	git clone git://github.com/schoeberl/leros.git

update_leros:
	cd leros && git pull

tools:
	cd leros && make tools

compile:
#	cd leros/LerosMuviumSDK && makeTest.bat
#	cd leros && make java_app -e JAPP=TestNoc
	cd leros && make java_app -e TARGET_SRC=../noc/src JAPP=Test

assemble:
	cd leros && make rom -e APP=../asm/muvium

build:
	cd leros && make rom -e APP=io
#	cd leros && make java_app -e JAPP=Test
#	cd leros && make rom -e APP=muvium

sim:
	cd noc && make base
	cd noc && make sim

