## CALCULATOR OPERATING GUIDE:
## Starting the program:

### To build the program type: $make
This create build folder and link everything up and create the executible for you.
### To start the program type $make run
This will open and run the built executible.
### To clean everything up type: $make clean
This will destroy the build folder which links all libraries and header files together.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Other functions:
The program was developed using test driven development and has gtests included aswell as documentation created via doxygen.
To make sure everything will run properly follow this guide:

### To download all essentials type: $make download
This will download all necessary programs our tests and documentation is using.
### To build gtests type: $make tests
This will create all necessary files for the execution of the tests aswell as the executible.
### To run the tests type: $make runtests
This will execute the executible for you
### To clean everything up type: $make cleantests
This will delete all stuff created via $make tests such as header files, executable etc.
### To create documentation type: $make doc
This will create entire documentation to directory 'dokumentace'.
### To open documentation type: $make docrun
This will open documentation via firefox browser.
### To clean documentation type: $make docclean
This will clean entire documentation in directory 'dokumentace'.
### To run profiling type: $make profile
This will run profiling. After this follow instructions in terminal.
### To clean profiling type: $profileclean
This will clean files created by $make profile.
