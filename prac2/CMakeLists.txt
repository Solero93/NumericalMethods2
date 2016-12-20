cmake_minimum_required(VERSION 3.6)
project(NewtonMethod)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp function-ex12.cpp function-ex12.h)
add_executable(NewtonMethod ${SOURCE_FILES})