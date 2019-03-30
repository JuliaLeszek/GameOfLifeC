//
// Created by mdg on 30.03.19.
//

#ifndef GAMEOFLIFE_SAVING_H
#define GAMEOFLIFE_SAVING_H

#include <stdio.h>
#include "generation.h"
#include "cell.h"

void save_to_txt(generation_t *grid, char *file);

void save_to_png(generation_t *grid, char *file);

#endif //GAMEOFLIFE_SAVING_H
