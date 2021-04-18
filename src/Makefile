currDir:=$(PWD)
buildDir:=$(currDir)/build
.PHONY: all clean run buildtest test profile pack doc help
all:
	cd "$(buildDir)" && qmake ..
	cd "$(buildDir)" && make
clean:
	rm -r "$(buildDir)"
	mkdir build
run:
	cd "$(buildDir)" && ./GuiCalculator