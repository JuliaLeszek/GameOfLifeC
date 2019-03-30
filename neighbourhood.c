//
// Created by julia on 29.03.19.
//

#include "neighbourhood.h"
#include "generation.h"

int alive_neighbour_count(generation_t* grid, int i, int j){
    int m, n, count = 0;
    for (m = i - 1; m <= i + 1; m++) {
        if (m < 0 || m >= grid->height){
            continue;
        }
        for (n = j - 1; n <= j + 1; n++){
            if (n < 0 || n >= grid->width || (m == i && n == j)){
                continue;
            }
            if (get_state(cell(grid, m, n)) == ALIVE){
                count++;
            }
        }
    }
    return count;
}