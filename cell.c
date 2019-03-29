//
// Created by julia on 28.03.19.
//

#include <stdio.h>
#include "cell.h"

void change_state (cell_t *cell, cell_st new_state){
    cell -> state = new_state;
}

cell_st get_state (cell_t *cell){
    return cell->state;
}