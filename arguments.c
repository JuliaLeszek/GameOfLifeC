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

    while (( opt = getopt(argc, argv, "f:n:g")) != -1){
        switch(opt){
            case 'f':
                args.file_in = fopen(optarg, "r");
                if (!args.file_in){
                    args.file_in = fopen("immortal.txt", "r");
                    printf ("Couldn't open file. Opening default configuration file.\n");
                }
                break;
            case 'n':
                args.n = atoi(optarg);
                if (!args.n){
                    args.n = 10;
                    printf ("Number of iterations needed. Setting n = 10\n");
                }
                break;
            case 'g':
                args.does_generate = atoi(optarg);
                if (!args.does_generate){
                    args.does_generate = 1;
                }
                break;
        }
    } return args;
}
