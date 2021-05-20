cmake_minimum_required(VERSION 3.17)
project(puissance_N C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(puissance_N
        main.c grid.h menu_func.h play_func.h)
