cmake_minimum_required(VERSION 3.5)
project(teensy_eurorack C CXX)
set(teensy_eurorack 1.0.0)

include(../teensy.options.cmake.in)
include(../teensy.build.cmake.in)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        input_output_spi.cpp)

set(HEADER_FILES
        ad5754.h
        input_output_spi.h
        teensy_eurorack.h
        teensy_eurorack_audio.h
        teensy_eurorack_pins.h
)

teensy_add_library(
        teensy_eurorack
        ${HEADER_FILES}
        ${SOURCE_FILES}
)
