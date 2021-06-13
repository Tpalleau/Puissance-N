cmake_minimum_required(VERSION 3.17)
project(puissance_N C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(puissance_N
        main.c grid.c menu_func.c function.h play_func.c save_func.c)
