#!/bin/bash

APP_ROOT=$(dirname "$0")
g++ $APP_ROOT/*.cpp \
	$APP_ROOT/AMGString/*.cpp \
	$APP_ROOT/AMGSystem/*cpp \
	$APP_ROOT/AMGPreparer/*cpp \
	-o $APP_ROOT/../bin/prepare
