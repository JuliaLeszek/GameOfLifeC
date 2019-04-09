//
// Created by julia on 09.04.19.
//

#include <stdio.h>
#include "cell.h"

int main ()
{

    cell_t test_cell;
    cell_t * p_test_cell = &test_cell;
    p_test_cell->state = ALIVE;

    change_state (p_test_cell, DEAD);
    if (p_test_cell->state == ALIVE && (get_state(p_test_cell)) == ALIVE){
        return 0;
    }
}