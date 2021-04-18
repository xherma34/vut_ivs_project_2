currDir:=$(PWD)
buildDir:=$(currDir)/build
testsDir:=$(currDir)/../tests
.PHONY: all clean run buildtest test profile pack doc help
all:
	cd "$(buildDir)" && qmake ..
	cd "$(buildDir)" && make
tests:
	cd "$(testsDir)" && cmake .
	cd "$(testsDir)" && make
clean:
	cd "$(testsDir)" && rm CMakeCache.txt cmake_install.cmake c_test Makefile 
	cd "$(testsDir)" && rm -r CMakeFiles
	rm -r "$(buildDir)"
	mkdir build
run:
	cd "$(buildDir)" && ./GuiCalculator
