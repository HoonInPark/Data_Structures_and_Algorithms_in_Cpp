cmake_minimum_required(VERSION 3.5.0)
project(Chapter06 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(BubbleSort 
main.cpp
BubbleSort.hpp)

include(CTest)
enable_testing()

