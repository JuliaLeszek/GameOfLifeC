//
// Created by julia on 01.04.19.
//

#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include "arguments.h"



arguments_t argument_handling(int argc, char **argv){
    int opt;
    arguments_t args;
    args.save_txt = 0;
    args.new_directory = "output";

    while (( opt = getopt(argc, argv, "f:n:s:")) != -1){
        switch(opt){
            case 'f':
                args.file_in = fopen(optarg, "r");
                break;
            case 'n':
                args.n = atoi(optarg);
                if (!args.n){
                    args.n = 10;
                    printf ("Number of iterations needed. Setting n = 10\n");
                }
                break;
            case 's':
                args.txt_file_name = optarg;
                args.save_txt = 1;
                break;
        }

    } return args;

}

arguments_t arguments(arguments_t args){

    if (!args.file_in){
        args.file_in = fopen("immortal.txt", "r");
        printf ("Couldn't open file. Opening default configuration file.\n");
    }
    if (!args.n){
        args.n = 10;
        printf ("Number of iteration is needed. Setting number of generation to 10.\n");
    } return args;
}


