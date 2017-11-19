#!/bin/bash
APP_ROOT=$(dirname "$0")
##echo $APP_ROOT
g++ $APP_ROOT/*.cpp \
	$APP_ROOT/AMGString/*.cpp \
	$APP_ROOT/AMGETL/*.cpp \
	$APP_ROOT/AMGSystem/*.cpp \
    $APP_ROOT/AMGSQLite/*.cpp \
    $APP_ROOT/AMGData/*.cpp \
    $APP_ROOT/ETL/*.cpp \
	-o $APP_ROOT/../bin/$1 \
	-l sqlite3

