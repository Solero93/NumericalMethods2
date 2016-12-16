cmake_minimum_required(VERSION 3.6)
project(UB_NumericalMethods2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp jacobi.cpp jacobi.h gauss-seidel.cpp gauss-seidel.h sor.cpp sor.h linearSolver.cpp linearSolver.h steepest-descent.cpp steepest-descent.h)
add_executable(UB_NumericalMethods2 ${SOURCE_FILES})