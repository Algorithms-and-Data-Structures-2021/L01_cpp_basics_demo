cmake_minimum_required(VERSION 3.2)

project(L01_cpp_basics_demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pointers src/pointers.cpp)
add_executable(static_arrays src/static_arrays.cpp)
add_executable(references src/references.cpp)
add_executable(mem_management src/memory_management.cpp)
add_executable(dynamic_arrays src/dynamic_arrays.cpp)
add_executable(functions src/functions.cpp)
