cmake_minimum_required(VERSION 3.10)
project(audio_thru_with_scope)

set(CMAKE_CXX_STANDARD 11)

include(../../../teensy.options.cmake.in)
include(../../../teensy.build.cmake.in)

set(SOURCEFILES audio_thru_with_scope.cpp)
import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} Audio)
import_arduino_library(${DEPSPATH} Audio/utility)

import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../src)
teensy_add_executable(midi_out ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)