currDir:=$(PWD)
buildDir:=$(currDir)/build
testsDir:=$(currDir)/../tests
.PHONY: all clean run buildtest test profile pack doc help
all:
	if [ -d "$(buildDir)" ]; then make clean; fi
	if [ ! -d "$(buildDir)" ]; then mkdir "$(buildDir)"; fi
	cd "$(buildDir)" && qmake ..
	cd "$(buildDir)" && make
download:
	sudo apt-get update -y
	sudo apt-get install -y qt5-qmake
	sudo apt-get update -y
	sudo apt install -y qt5-default
tests:
	cd "$(testsDir)" && cmake .
	cd "$(testsDir)" && make
clean:
	rm -r "$(buildDir)"
run:
	cd "$(buildDir)" && ./GuiCalculator
