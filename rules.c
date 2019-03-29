//
// Created by julia on 28.03.19.
//


#include "rules.h"
#include "cell.h"



cell_st rules (int alive_neighbour_count, cell_st previous_state){
    if (previous_state == ALIVE){
        if (alive_neighbour_count > 3 || alive_neighbour_count < 2){
            return DEAD;
        } else return ALIVE;
    } else {
        if (alive_neighbour_count == 3){
            return ALIVE;
        } else return DEAD;
    }
}