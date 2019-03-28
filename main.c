#include <stdio.h>
#include "cell.h"
#include "rules.h"



int main() {
    cell_t c;
    change_state ( &c, rules ( 3, DEAD));
    printf("c = %d\n", c.state);


    return 0;
}

