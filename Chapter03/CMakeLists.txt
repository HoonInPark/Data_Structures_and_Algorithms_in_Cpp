cmake_minimum_required(VERSION 3.5.0)
project(Chapter03 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Array Array.cpp)
add_executable(InsertSortArr InsertSortArr.cpp)
add_executable(Tic_Tac_Toe Tic_Tac_Toe.cpp)
add_executable(CircularLinkedList CircularLinkedList.cpp)
add_executable(vEnglichRuler EnglichRuler.cpp)

include(CTest)
enable_testing()

