//
// Created by julia on 28.03.19.
//

#ifndef GAMEOFLIFE_GENERATION_H
#define GAMEOFLIFE_GENERATION_H

#include "cell.h"

typedef struct {
    cell_st *generation;
    int height;
    int width;
} generation_t;


generation_t *create_generation( int height, int width);

cell_t *cell(generation_t *grid, int i, int j);

void free_gen (generation_t *grid);

#endif //GAMEOFLIFE_GENERATION_H
