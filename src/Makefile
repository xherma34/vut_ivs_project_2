currDir:=$(PWD)
buildDir:=$(currDir)/build
testsDir:=$(currDir)/../tests
.PHONY: all download tests clean run runtests cleantests doc docrun docclean profile pack help
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
	sudo apt-get install -y doxygen
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
cleantests:
	cd "$(testsDir)" && rm CMakeCache.txt cmake_install.cmake c_test Makefile
	cd "$(testsDir)" && rm -r CMakeFiles
doc:
	cd .. && doxygen doxyConfigFile
docrun:
	cd ../dokumentace/html/ && firefox index.html
docclean:
	cd ../dokumentace/ && rm -r html
