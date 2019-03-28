//
// Created by julia on 28.03.19.
//

#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H

typedef enum{
    DEAD, ALIVE //  zmiana kolejności żeby 0 zonaczało DEAD
} cell_st;

typedef struct {
    cell_st state;
} cell_t;


#endif //GAMEOFLIFE_CELL_H
