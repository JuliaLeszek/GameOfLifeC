#include <stdio.h>
#include "cell.h"
#include "rules.h"



int main() {

    cell_st a = rules ( 3, DEAD);
    printf("a = %d\n", a);


    return 0; //hurray
}

