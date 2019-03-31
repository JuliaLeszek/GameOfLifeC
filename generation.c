//
// Created by julia on 28.03.19.
//

#include <stdlib.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include "generation.h"
#include "rules.h"
#include "neighbourhood.h"


// pointer and space for the generation_t
generation_t *create_generation( int height, int width){
    generation_t *new_gen = (generation_t*) malloc(sizeof(generation_t));
    if (!new_gen){
        return NULL;
    }

    new_gen->generation = (cell_t*) calloc(((size_t)(height*width)), sizeof(cell_t));
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

// creating initial generation from file

generation_t *load_file (FILE *file_in){
    int i, j, m, n;
    if (fscanf(file_in, "%d %d", &m, &n) != 2){
        return NULL;
    }
    generation_t *new = create_generation(m, n);

    while (fscanf(file_in, "%d %d", &i, &j) == 2){

        if (i > 0 && i <= m && j > 0 && j <= n ) {
            if ((get_state(cell(new, i, j))) != ALIVE) {

                change_state(cell(new, i, j), ALIVE);
            } else {
                printf("Cell with these coordinates was already alive: %d, %d\n, skipping line", i, j);
            }
        }
    }

    return new;
}

// rewriting generation from new to current

void copy_generation (generation_t *current, generation_t *new){
    for (int i = 0; i < current->height; i++){
        for (int j = 0; j < current->width; j++){
            change_state(cell(current, i, j), get_state(cell(new, i, j)));
        }
    }
}



// memory management

void free_gen (generation_t *grid){
    free(grid);
}