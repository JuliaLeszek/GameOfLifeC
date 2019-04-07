//
// Created by SONY on 02.04.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <png.h>
#include "saving_png.h"

void save_to_png(generation_t *grid, char *file){
    int x, y, i, j;
    int width, height;
    FILE *fp = NULL;
    png_byte color_type;
    png_byte bit_depth;
    png_structp png_ptr;
    png_infop info_ptr;
    png_bytep *row_pointers;

    bit_depth = 8;
    width = 8 * grid->width;
    height = 8 * grid->height;

    color_type = PNG_COLOR_TYPE_GRAY;
    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
    for (y = 0; y < height; y++){
        row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);
    }
    for (y = 0; y < height; y += 8){
        for (x = 0; x < width; x += 8){
            if (get_state(cell(grid, y/8, x/8)) == ALIVE){
                for (i = 0; i < 8; i++){
                    for (j = 0; j < 8; j++){
                        row_pointers[y + j][x + i] = 255;
                    }
                }
            } else {
                for (i = 0; i < 8; i++){
                    for (j = 0; j < 8; j++){
                        row_pointers[y + j][x + i] = 0;
                    }
                }
            }
        }
    }

    fp = fopen(file, "wb");
    if (!fp){
        printf("File %s can't be open", file);
    }
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    info_ptr = png_create_info_struct(png_ptr);
    png_init_io(png_ptr,fp);
    png_set_IHDR(png_ptr, info_ptr, width, height, bit_depth, color_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(png_ptr, info_ptr);
    png_write_image(png_ptr, row_pointers);
    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    for (y = 0; y < height; y++){
        free(row_pointers[y]);
    }
    free(row_pointers);
    fclose(fp);
}
