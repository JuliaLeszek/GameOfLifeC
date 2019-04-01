#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "generation.h"
#include "loading.h"
#include "arguments.h"
#include <getopt.h>




int main(int argc, char **argv){


    arguments_t args = argument_handling(argc, argv);


    // creating next generations

    generation_t *current = load_file (args.file_in);
    generation_t *new = create_generation (current->height, current->width);
    generation_t *temporary;

    for (int i = 1; i <= args.n; i++){
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

