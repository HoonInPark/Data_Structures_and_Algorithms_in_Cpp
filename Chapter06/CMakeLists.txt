cmake_minimum_required(VERSION 3.5.0)
project(Chapter06 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(NodeSeq NodeSeq.cpp)
add_executable(VecNotCopy 
VecNotCopy.h
main.cpp)

include(CTest)
enable_testing()

