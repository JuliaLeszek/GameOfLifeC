#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "cell.h"
#include "rules.h"
#include "generation.h"
#include "neighbourhood.h"



int main(int argc, char **argv){ // wskaźnik na wskażnik na literę

    // argument handling

    FILE *file_in;
    int n;

    if (argc > 2 && !strcmp(argv[1], "-f")){
        file_in = fopen(argv[2], "r");
    } else {
        file_in = fopen("immortal.txt", "r");
        printf ("Couldn't open file. Opening default configuration file.");
    }

    if (file_in == NULL){
        printf ("Could not open file. Terminating.");
        return 0;
    }

    if (argc > 4 && !strcmp(argv[3], "-n")){
        n = atoi(argv[4]);
        if (n < 0){
            printf ("Number of iterations must be positive. Terminating.");
            return 0;
            }
    } else {
        printf ("Number of iterations needed. Terminating.");
        return 0;
    }

//    if (argc > 6 && !strcmp(argv[5], "-g")){
//                                                      // miejsce na flagę generowania plikow png
//    } else {
//        printf ("Number of iterations needed. Terminating.");
//        return 0;
//    }


    // creating next generations

    generation_t *current = load_file (file_in);
    generation_t *new = create_generation (current->height, current->width);

    for (int i = 0; i < n; i++){
        next_generation (current, new);
        printf ("check %d\n", i);
        copy_generation (current, new);
    }



    free_gen(new);
    free_gen(current);

    return 0;
}

