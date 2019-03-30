cmake_minimum_required(VERSION 3.13)
project(GameOfLife C)

set(CMAKE_C_STANDARD 99)

add_executable(GameOfLife main.c rules.c rules.h cell.c cell.h generation.c generation.h neighbourhood.c neighbourhood.h saving.h saving.c)