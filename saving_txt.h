//
// Created by mdg on 30.03.19.
//

#ifndef GAMEOFLIFE_SAVING_TXT_H
#define GAMEOFLIFE_SAVING_TXT_H

#include <stdio.h>
#include "generation.h"
#include "cell.h"

void save_to_txt(generation_t *board, char *file);

#endif //GAMEOFLIFE_SAVING_TXT_H
