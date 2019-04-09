//
// Created by julia on 09.04.19.
//

#include "rules.h"

int main(){

    cell_t test_cell;
    cell_t *p_test_cell = &test_cell;
    p_test_cell->state = rules (3, DEAD);
    if (test_cell.state == ALIVE){
        return 0;
    } else return 1;
}