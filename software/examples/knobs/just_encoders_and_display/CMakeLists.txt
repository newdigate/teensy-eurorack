cmake_minimum_required(VERSION 3.10)
project(just_encoders_and_display)

set(CMAKE_CXX_STANDARD 11)

include(../../../teensy.options.cmake.in)
include(../../../teensy.build.cmake.in)

set(SOURCEFILES just_encoders_and_display.cpp)
import_arduino_library(${DEPSPATH} ST7735_t3)
import_arduino_library(${DEPSPATH} Bounce2/src) # https://github.com/thomasfredericks/Bounce2
import_arduino_library(${DEPSPATH} Encoder) # https://github.com/PaulStoffregen/Encoder.git
import_arduino_library(${DEPSPATH} Encoder/utility) # https://github.com/PaulStoffregen/Encoder.git
import_arduino_library_absolute(${CMAKE_CURRENT_SOURCE_DIR}/../../../src)
teensy_add_executable(just_encoders_and_display ${SOURCEFILES})

set(CMAKE_VERBOSE_MAKEFILE 1)