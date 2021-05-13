cmake_minimum_required(VERSION 3.10)
project(audio_to_cv)

set(CMAKE_CXX_STANDARD 11)

include(../../../../teensy.options.cmake.in)
include(../../../../teensy.build.cmake.in)

set(SOURCEFILES 01_audio_to_cv.cpp)

import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../../src)
teensy_add_executable(audio_to_cv ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)