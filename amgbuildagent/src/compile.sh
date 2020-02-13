#!/bin/bash
###############################################################################
## Name        : make                                                         #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Helps build project package on a non-Windows system          #
###############################################################################

APP_ROOT=$(dirname "$0")
DEBUG="$1"
if [ "$DEBUG" == "" ]; then
    DEBUG="0"
fi
ENABLE64="$2"
rm -fR $APP_ROOT/../bin/*
if [ "$DEBUG" != "-clean" ]; then
	if [ "$ENABLE64" == "1" ]; then
		cd $APP_ROOT/../bin && cmake -DCMAKE_GENERATOR_PLATFORM=x64 ../
	else
		cd $APP_ROOT/../bin && cmake ../
	fi
	cd $APP_ROOT/../bin && make

	if [ "$DEBUG" -ne "1" ]; then 
    	rm $APP_ROOT/../bin/*.cmake
    	rm -fR $APP_ROOT/../bin/CMakeFiles
    	rm $APP_ROOT/../bin/Makefile
    	rm $APP_ROOT/../bin/CMake*.txt
	fi
fi
