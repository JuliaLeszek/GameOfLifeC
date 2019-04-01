//
// Created by julia on 01.04.19.
//

#include "loading.h"
#include "generation.h"

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