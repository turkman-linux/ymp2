all: clean build

build:
	meson setup build && \
	ninja -C build

clean:
	rm -rvf build docs/html docs/latex