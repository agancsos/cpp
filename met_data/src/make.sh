#!/bin/bash
APP_ROOT=$(dirname "$0")
##echo $APP_ROOT
##echo $1
g++ $APP_ROOT/*.cpp \
	$APP_ROOT/AMGString/*.cpp \
	$APP_ROOT/AMGSystem/*.cpp \
	$APP_ROOT/METPerson/*.cpp \
	$APP_ROOT/METStudent/*.cpp \
    $APP_ROOT/AMGExtractor/*.cpp \
	-o $APP_ROOT/../bin/$1 \


