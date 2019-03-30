#include <stdio.h>
#include "cell.h"
#include "rules.h"
#include "generation.h"
#include "neighbourhood.h"


int main() {
    // creating the next generation-- test on one cell
    generation_t* p = create_generation( 100, 100);
    cell_t *c = cell (p, 10, 7);
    cell_t *d = cell (p, 10, 8);
    cell_t *e = cell (p, 10, 9);
    change_state (c, rules ( 3, get_state(c)));
    change_state (d, rules ( 3, get_state(c)));
    change_state (e, rules ( 3, get_state(c)));


    generation_t* n = create_generation( 100, 100);
    next_generation(p, n);
    cell_t *check = cell (n, 9, 8);


    printf("c = %d\n", (int) c->state);
    printf("d = %d\n", (int) d->state);
    printf("e = %d\n", (int) e->state);

    printf("check's cell state = %d\n", (int) check->state);

    free_gen(p);

    return 0;
}

