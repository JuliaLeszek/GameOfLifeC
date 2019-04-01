//
// Created by julia on 01.04.19.
//

#ifndef GAMEOFLIFE_ARGUMENTS_H
#define GAMEOFLIFE_ARGUMENTS_H

#include <bits/types/FILE.h>
#include <stdbool.h>

typedef struct{
    FILE *file_in;
    int n;
    bool does_generate;
} arguments_t;

arguments_t argument_handling(int argc, char **argv);

#endif //GAMEOFLIFE_ARGUMENTS_H
