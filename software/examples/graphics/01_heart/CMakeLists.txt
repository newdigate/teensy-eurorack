cmake_minimum_required(VERSION 3.10)
project(heart)

set(CMAKE_CXX_STANDARD 11)

include(../../../teensy.options.cmake.in)
include(../../../teensy.build.cmake.in)

set(SOURCEFILES 01_heart.cpp)

import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} teensy-libcurve/src) # https://github.com/newdigate/teensy-libcurve
import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../src)
teensy_add_executable(heart ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)