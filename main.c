#include <stdio.h>
#include "cell.h"
#include "rules.h"
#include "generation.h"
#include "neighbourhood.h"


int main() {

    generation_t* p = create_generation( 100, 100);
    cell_t *c = cell (p, 10, 7);
    cell_t *e = cell (p, 10, 9);
    change_state (c, rules ( 3, get_state(c)));
    change_state (e, rules ( 3, get_state(c)));
    int d = alive_neighbour_count(p, 10, 8);
    printf("c = %d\n", (int) c->state);
    printf("d = %d\n", d);  // zlicza! <3
    free_gen(p);

    return 0;
}

