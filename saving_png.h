//
// Created by SONY on 02.04.2019.
//

#ifndef GAMEOFLIFE_SAVING_PNG_H
#define GAMEOFLIFE_SAVING_PNG_H

#include <stdio.h>
#include "generation.h"
#include "cell.h"

void save_to_png(generation_t *grid, char *file);

#endif //GAMEOFLIFE_SAVING_PNG_H
