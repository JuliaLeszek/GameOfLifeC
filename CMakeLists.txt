cmake_minimum_required(VERSION 3.13)
project(GameOfLife C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_LIBRARIES -lpng)

add_executable(GameOfLife main.c rules.c rules.h cell.c cell.h generation.c generation.h neighbourhood.c neighbourhood.h loading.c loading.h arguments.c arguments.h saving_txt.c saving_txt.h saving_png.c saving_png.h)
add_executable(CellTest CellTest.c cell.c cell.h)
add_executable(RulesTest RulesTest.c rules.c rules.h)
add_executable(NeighbourhoodTest NeighbourhoodTest.c neighbourhood.c neighbourhood.h ArgumentsTest.c)
add_executable(ArgumentsTest ArgumentsTest.c arguments.c arguments.h)