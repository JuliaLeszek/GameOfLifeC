cmake_minimum_required(VERSION 3.13)
project(GameOfLife C)

set(CMAKE_C_STANDARD 99)

add_executable(GameOfLife main.c rules.c rules.h cell.c cell.h generation.c generation.h neighbourhood.c neighbourhood.h loading.c loading.h arguments.c arguments.h saving_txt.c saving_txt.h saving_png.c saving_png.h)