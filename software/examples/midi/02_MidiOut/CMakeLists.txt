cmake_minimum_required(VERSION 3.10)
project(midi_out)

set(CMAKE_CXX_STANDARD 11)

include(../../../teensy.options.cmake.in)
include(../../../teensy.build.cmake.in)

set(SOURCEFILES 02_MidiOut.cpp)
import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} arduino_midi_library/src) # https://github.com/FortySevenEffects/arduino_midi_library
import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../src)
teensy_add_executable(midi_out ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)