currDir:=$(PWD)
buildDir:=$(currDir)/build
testsDir:=$(currDir)/../tests
.PHONY: all download tests clean run runtests testsclean profile pack doc help
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
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
tests:
	cd "$(testsDir)" && cmake .
	cd "$(testsDir)" && make
clean:
	rm -r "$(buildDir)"
run:
	cd "$(buildDir)" && ./GuiCalculator
runtests:
	cd "$(testsDir)" && ./c_test
testsclean:
	cd "$(testsDir)" && rm CMakeCache.txt cmake_install.cmake c_test Makefile
	cd "$(testsDir)" && rm -r CMakeFiles
