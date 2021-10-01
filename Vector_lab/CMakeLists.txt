cmake_minimum_required(VERSION 3.1)
add_library(lib_1 "Vector.cpp" "Vector.h")
add_executable("Vector_lab_main" "main.cpp" "Vector.cpp")