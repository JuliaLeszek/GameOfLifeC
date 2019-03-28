//
// Created by julia on 28.03.19.
//

#include <stdlib.h>
#include "generation.h"


// space for the generation_t
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
