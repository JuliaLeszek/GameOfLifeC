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
    int save_txt;
    char *txt_file_name;
    const char *new_directory;
} arguments_t;

arguments_t argument_handling(int argc, char **argv);

arguments_t arguments(arguments_t args);

#endif //GAMEOFLIFE_ARGUMENTS_H
