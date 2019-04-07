#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "generation.h"
#include "loading.h"
#include "arguments.h"
#include <getopt.h>
#include "saving_txt.h"
#include "saving_png.h"
#include <getopt.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>



int main(int argc, char **argv){

    char *png_name = "generation";
    char png_title[50];
    const char *png_format = ".png";
    char number[10];
    arguments_t args = arguments(argument_handling(argc, argv));


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
    strcpy(png_title, png_name);
    strcat(png_title, "0.png");
    save_to_png(current, png_title);
    for (int i = 1; i <= args.n; i++){
        next_generation (current, new);
        printf ("Created generation number %d\n", i);

        temporary = current;
        current = new;
        new = temporary;

        sprintf(number, "%d", i);
        strcpy(png_title, png_name);
        strcat(png_title, number);
        strcat(png_title, png_format);
        save_to_png(current, png_title);

    }
    if (args.txt_file_name ) {
        save_to_txt(current, args.txt_file_name);
    }


    free_gen(new);
    free_gen(current);

    return 0;
}

