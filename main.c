#include <stdio.h>
#include "cell.h"
#include "rules.h"
#include "generation.h"
#include "neighbourhood.h"


int main(int argc, char **argv) {

    // creating the next generation-- test on one cell

    FILE *file_in;
    file_in = fopen("immortal.txt", "r");
    if (file_in == NULL){
        printf("bon iver");
        return 0;
    }


    generation_t* p = load_file(file_in);
    cell_t *a= cell (p, 50, 62);
    cell_t *b = cell (p, 50, 63);
    cell_t *c= cell (p, 50, 64);

    printf("a's cell state = %d\n", (int) a->state);
    printf("b's cell state = %d\n", (int) b->state);
    printf("c's cell state = %d\n", (int) c->state);

//    generation_t* n;
//    cell_t *check = cell (n, 9, 8);
//    printf("check's cell state = %d\n", (int) check->state);
//    next_generation(p, n);


//    printf("check's cell state = %d\n", (int) check->state);

    free_gen(p);

    return 0;
}

