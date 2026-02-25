# README - Assessment 3

## Overview

This project creates a simulation of disks randomly travelling within an enclosed space, where the disks can't overlap. To generate the simulation, multiple c++ programs and some headers associated with them are used. When these programs are compiled and ran, the attached Jupyter Notebook can be used to display the generated programs.
Included in the repo is a Makefile that can be used to compile and run the program. Further explanation of the Makefile is further through this document.

## Repository Structure

Assessment3/
│
├── source/
│   ├── main.cpp
│   ├── system.cpp
│   ├── disk.cpp
│
├── include/
│   ├── system.h
│   ├── disk.h
│
├── view.ipynb
├── Makefile
├── .gitignore
└── README.md

## Modifications/Improvements

### disk.h and disk.cpp

- Recreated disk.h header from the code given in a reference file.
- Completed disk.cpp file by adding distance calculation into the distance method.
- Changed privacy of multiple attributes within disk.h to private, improving the encapsulation of the disk class. Created getter methods in disk.h to allow child classes to access attribute values.
- Defined some attributes as constant to protect them from being interfered with.
- Edited access modifiers within the disk.cpp program to match changes made in the header file.

### system.h and system.cpp

- Recreated system.h header from the downloaded file.
- Added disk.h and system.h include statements to the beginning of the code.
- Created the uniform method in the system class, which generates a random number between two values given as parameters by using the c++ random library.
- Altered the access modifiers of attributes in system.h to be private and improve encapsulation. Also identified some attributes as constant as done with disk.h.
- Corrected the attributes in system.cpp to fit the definitions given in both disk.h and system.h. To access the private variables defined in system.h, the constructor in system is altered, removing the this-> syntax and replacing it with an initialiser list.

### main.cpp

- Finished the include statements by connecting system.h to main.cpp.

## Git structure

### .gitignore

I excluded any files relating to these names:

confs/
.DS_Store
*.o
simulation

as they clutter up the repo without adding any value to the programs.

### git commits

Throughout the project, I used clear commit messages to explain what in the repo was altered with each commit. 
I also made use of branches to split the workflow into clear sections of improvement, with the branches being named accordingly to keep the clarity on how the repository was developed.

## How to operate the files

To build the cpp files, either:

'make'
or
'g++ -std=c++17 main.cpp system.cpp disk.cpp -o simulation'

can be entered into the terminal, resulting in a file named 'simulation'.

By running simulation via 

'make run'
or
'./simulation'

in the terminal, the confs folder will fill with a number of result files, the amount determined by how many steps are declared in the cpp files.

To see the output from simulation, open 
view.ipynb
and run all cells from the top. This will begin a simulation in the output cell of the disks moving randomly within a box.

To clear files that have been created to run the project, use 
'make clean'
which removes any compiled files

## Author
William Chandler
Assessment 3 
