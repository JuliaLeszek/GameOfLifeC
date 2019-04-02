#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "generation.h"
#include "loading.h"
#include "arguments.h"
#include <getopt.h>
#include "saving_txt.h"
#include <getopt.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>



int main(int argc, char **argv){


    arguments_t args = argument_handling(argc, argv);


    // creating next generations

    generation_t *current = load_file (args.file_in);
    generation_t *new = create_generation (current->height, current->width);
    generation_t *temporary;

    if (mkdir(args.new_directory, S_IRWXU | S_IRGRP | S_IXGRP) != 0){
        if (errno == EEXIST) {
            if (chdir(args.new_directory) != 0) {
                perror("Error during moving to new directory!\n");
            }
        } else {
            perror("Error during moving to new directory!\n");
        }
    } else if (chdir(args.new_directory) != 0) {
        perror("Error during moving to new directory!\n");
    }

    for (int i = 1; i <= args.n; i++){
        next_generation (current, new);
        printf ("Created generation number %d\n", i);

        if (i == args.n && args.save_txt == 1) {
            save_to_txt(new, args.txt_file_name);
        }

        temporary = current;
        current = new;
        new = temporary;
    }




    free_gen(new);
    free_gen(current);

    return 0;
}

