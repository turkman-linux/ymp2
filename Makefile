SHELL=/bin/bash -e
all: clean build

build:
	CFLAGS="-g3 -O2" meson setup build && \
	ninja -C build

test:
	for example in $(wildcard build/docs/examples/*) ; do \
	    [ ! -f $$example ] || $$example ;\
	done

clean:
	rm -rvf build docs/html docs/latex