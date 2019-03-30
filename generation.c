//
// Created by julia on 28.03.19.
//

#include <stdlib.h>
#include "generation.h"
#include "rules.h"
#include "neighbourhood.h"


// pointer and space for the generation_t
generation_t *create_generation( int height, int width){
    generation_t *new_gen = (generation_t*) malloc(sizeof(generation_t));
    if (!new_gen){
        return NULL;
    }

    new_gen->generation = (cell_t*) calloc((height*width), sizeof(cell_t)); //
    if (!(new_gen->generation)){
        free(new_gen);
        return NULL;
    }
    new_gen->width = width;
    new_gen->height = height;

    return new_gen;
}


// pointer for the single cell

cell_t *cell(generation_t *grid, int i, int j){
    if((i >= 0 && i <= grid->height) && (j >= 0 && j <= grid->width)){
        return grid->generation + i*grid->width + j;
    } return NULL;
}

// creation of the new generation

void next_generation (generation_t *current, generation_t *new){
    int i,j;
    for (i = 0; i < current->height; i++){
        for (j = 0; j < current->width; j++){
            change_state(cell(new, i, j), rules(alive_neighbour_count(current, i, j) , get_state(cell(current, i, j))));
        }
    }
}



// memory management

void free_gen (generation_t *grid){
    free(grid);
}