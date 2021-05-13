cmake_minimum_required(VERSION 3.10)
project(cv_output)

set(CMAKE_CXX_STANDARD 11)

include(../../../../teensy.options.cmake.in)
include(../../../../teensy.build.cmake.in)

set(SOURCEFILES 01_cv_output.cpp)
import_arduino_library(${DEPSPATH} Audio)
import_arduino_library(${DEPSPATH} Audio/utility)
import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../../src)
teensy_add_executable(cv_output ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)