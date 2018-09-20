#!/bin/bash
###############################################################################
## Name        : make                                                         #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Helps build project package on a non-Windows system          #
###############################################################################

APP_ROOT2=$(dirname "$0")
CMAKE_PATH="/Users/computerfox/Downloads/cmake-3.12.0-rc2/Bootstrap.cmk"

rm -fR $APP_ROOT2/../bin/*
cd $APP_ROOT2/../bin && $CMAKE_PATH/cmake ../
cd $APP_ROOT2/../bin && make

rm $APP_ROOT2/../bin/*.cmake
rm -fR $APP_ROOT2/../bin/CMakeFiles
rm $APP_ROOT2/../bin/Makefile
rm $APP_ROOT2/../bin/CMake*.txt
