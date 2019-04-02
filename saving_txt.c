//
// Created by mdg on 30.03.19.
//

#include <stdio.h>
#include <stdlib.h>

#include "saving_txt.h"

void save_to_txt(generation_t *board, char *file) {
    int i, j;
    FILE *out = NULL;
    strcat(file, ".txt");
    out = fopen(file, "w");
    if (out == NULL) {
        fprintf(stderr, "Saving the last generation to TXT was unsuccessful.\n");
        return;
    }
    fprintf(stdout, "Generating TXT file...\n");
    fprintf(out, "%d %d\n", board->width, board->height);
    for (i = 0; i < board->width; i++) {
        for (j = 0; j < board->height; j++) {
            if (get_state(cell(board, i, j)) == ALIVE) {
                fprintf(out, "%d %d\n", i + 1, j + 1);
            }
        }
    }
    fprintf(stdout, "TXT file generation complete.\n");
    fclose(out);
}