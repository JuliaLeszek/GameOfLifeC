//W module
// Created by julia on 28.03.19.
//

#ifndef GAMEOFLIFE_GENERATION_H
#define GAMEOFLIFE_GENERATION_H

#include "cell.h"
#include <stdio.h>

typedef struct {
    cell_t *generation;
    int height;
    int width;
} generation_t;


generation_t *create_generation( int height, int width);

cell_t *cell(generation_t *grid, int i, int j);

void next_generation (generation_t *current, generation_t *new);

void free_gen (generation_t *grid);

#endif //GAMEOFLIFE_GENERATION_H
