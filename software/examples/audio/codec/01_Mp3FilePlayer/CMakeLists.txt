cmake_minimum_required(VERSION 3.10)
project(mp3play)

set(CMAKE_CXX_STANDARD 11)

include(../../../../teensy.options.cmake.in)
include(../../../../teensy.build.cmake.in)

set(SOURCEFILES 01_Mp3FilePlayer.cpp)
import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} Arduino-Teensy-Codec-lib)  # https://github.com/FrankBoesing/Arduino-Teensy-Codec-lib.git

import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../../src)
teensy_add_executable(mp3play ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)