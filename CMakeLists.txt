cmake_minimum_required(VERSION 3.21)
project(tad03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(tad03
        list.c
        list.h
        prog.c)
