currDir:=$(PWD)
buildDir:=$(currDir)/build
testsDir:=$(currDir)/../tests
.PHONY: all clean run buildtest test profile pack doc help
all:
	if [ ! -d "$(buildDir)" ]; then mkdir "$(buildDir)"; fi
	cd "$(buildDir)" && qmake ..
	cd "$(buildDir)" && make
tests:
	cd "$(testsDir)" && cmake .
	cd "$(testsDir)" && make
clean:
	rm -r "$(buildDir)"
run:
	cd "$(buildDir)" && ./GuiCalculator
