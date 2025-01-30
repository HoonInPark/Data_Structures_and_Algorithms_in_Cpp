cmake_minimum_required(VERSION 3.5.0)
project(Array VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Array Array.cpp)

include(CTest)
enable_testing()

