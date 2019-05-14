cmake_minimum_required(VERSION 3.14)
project(Gauss C)

set(CMAKE_C_STANDARD 11)

add_executable(Gauss main.c Functions.h Functions.c)