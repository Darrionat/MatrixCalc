cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp Matrix.cpp Matrix.h Vector.cpp Vector.h)