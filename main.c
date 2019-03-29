#include <stdio.h>
#include "cell.h"
#include "rules.h"
#include "generation.h"


int main() {

    generation_t* p = create_generation( 100, 100);
    cell_t *c = cell (p, 10, 7);
    change_state (c, rules ( 3, get_state(c)));
    printf("c = %d\n", (int) c->state);
    free_gen(p);

    return 0;
}

