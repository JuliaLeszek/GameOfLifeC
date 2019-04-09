//
// Created by julia on 09.04.19.
//

#include <stdio.h>
#include "cell.h"

int main ()
{

    cell_t test_cell;
    cell_t * p_test_cell = &test_cell;
    test_cell.state = ALIVE;

    change_state (p_test_cell, DEAD);
    if (test_cell.state == DEAD && (get_state(p_test_cell)) == DEAD) {
        return 0;
    } else return 1;
}