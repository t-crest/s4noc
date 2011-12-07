
all:

get_leros:
	git clone git@github.com:schoeberl/leros.git

build:
	cd leros && make tools
	cd leros && make rom -e APP=blink
