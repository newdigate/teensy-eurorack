cmake_minimum_required(VERSION 3.10)
project(audio_pitch)

set(CMAKE_CXX_STANDARD 11)

include(../../../../teensy.options.cmake.in)
include(../../../../teensy.build.cmake.in)

set(SOURCEFILES 01_knob_pitch.cpp)

import_arduino_library(${DEPSPATH} ResponsiveAnalogRead)

import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../../src)
teensy_add_executable(audio_pitch ${SOURCEFILES})