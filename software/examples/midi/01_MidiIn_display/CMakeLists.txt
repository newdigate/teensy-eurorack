cmake_minimum_required(VERSION 3.10)
project(midi_in_display)

set(CMAKE_CXX_STANDARD 11)

include(../../../teensy.options.cmake.in)
include(../../../teensy.build.cmake.in)

set(SOURCEFILES 01_MidiIn_display.cpp)
import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} arduino_midi_library/src) # https://github.com/FortySevenEffects/arduino_midi_library
import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../src)
teensy_add_executable(midi_in_display ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)