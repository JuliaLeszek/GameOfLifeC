#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "generation.h"
#include "loading.h"


int main(int argc, char **argv){ // wskaźnik na wskażnik na literę

    // argument handling

    FILE *file_in;
    int n;

    if (argc > 2 && !strncmp(argv[1], "-f", 2)){
        file_in = fopen(argv[2], "r");
    } else {
        file_in = fopen("immortal.txt", "r");
        printf ("Couldn't open file. Opening default configuration file.\n");
    }

    if (file_in == NULL){
        printf ("Could not open file. Terminating.\n");
        return 0;
    }

    if (argc > 4 && !strcmp(argv[3], "-n")){
        n = atoi(argv[4]);
        if (n < 0){
            printf ("Number of iterations must be positive. Terminating.\n");
            return 0;
            }
    } else {
        printf ("Number of iterations needed. Terminating.\n");
        //return 0;
        n = 10;
    }

//    if (argc > 6 && !strcmp(argv[5], "-g")){
//                                                      // miejsce na flagę generowania plikow .png
//    } else {
//        printf ("Number of iterations needed. Terminating.");
//        return 0;
//    }


    // creating next generations

    generation_t *current = load_file (file_in);
    generation_t *new = create_generation (current->height, current->width);
    generation_t *temporary;

    for (int i = 1; i <= n; i++){
        next_generation (current, new);
        printf ("Created generation number %d\n", i);

        temporary = current;
        current = new;
        new = temporary;
    }



    free_gen(new);
    free_gen(current);

    return 0;
}

