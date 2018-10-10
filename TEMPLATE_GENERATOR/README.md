# README
## ABOUT
* NAME       : TEMPLATE_GENERATOR
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## SYNOPSIS
This project helps generate the file structure for a new programming project.

## Assumptions
* There is a need to generate the same file structure for multiple programs.
* Programming languages can vary, but the file structure is the same.
* Program file structure requires a library folder.
* Program file structure requires a binary folder.
* Program file structure requires a source folder.
* Projects that will be build using CPP will require a CMakeLists.txt file.
* All projects require a README file.

## Implemenation description

## FLAGS
* -name    : Name of the project
* -lang    : Name of the project langauge. Default is CPP
* -base    : Full path of the base folder where to create the project
* -version : Display version information

## Configuration

## PREREQUISITES
### G++ compiler
#### Windows
Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++
#### Mac
Should come with XCode command-line tools
#### Linux
Should be installable using internal package installer
### CMake
#### Windows
Should come with Visual Studio 2017
#### Mac
Can be installed from https://cmake.org/download/
#### Linux
Can be installed from https://cmake.org/download/
## Build
This can be built either using one of the compile scripts or manually using the following instructions
