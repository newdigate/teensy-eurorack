cmake_minimum_required(VERSION 3.10)
project(array)

set(CMAKE_CXX_STANDARD 11)

include(../../../teensy.options.cmake.in)
include(../../../teensy.build.cmake.in)

set(SOURCEFILES
        01_DAC_AD5754.cpp
        ../../../src/input_output_spi.cpp)

import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../src)
teensy_add_executable(dac_ad5754_raw ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)