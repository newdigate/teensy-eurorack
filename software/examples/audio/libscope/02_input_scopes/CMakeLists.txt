cmake_minimum_required(VERSION 3.10)
project(input_scopes)

set(CMAKE_CXX_STANDARD 11)

include(../../../../teensy.options.cmake.in)
include(../../../../teensy.build.cmake.in)

set(SOURCEFILES 02_input_scopes.cpp)
import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} Audio)
import_arduino_library(${DEPSPATH} Audio/utility)
import_arduino_library(${DEPSPATH} teensy-audio-libtftscope/src) # https://github.com/newdigate/teensy-audio-libtftscope
import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../../src)
teensy_add_executable(input_scopes ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)