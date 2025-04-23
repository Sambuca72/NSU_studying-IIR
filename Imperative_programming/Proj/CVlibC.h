#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/*
    TODO
        convolution func
        padding function

*/

static int conv_matrix_multiply(int *matrix_a, int *matrix_b, int size){
    int sum = 0;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            sum+=matrix_a[i*size+j]*matrix_b[i*size+j];
        }
    }

    return sum;
}

static int create_area()

void convolution(void *image, int* width, int* height, int* channels, 
                int *kernel, int kernel_size, int padding){
    
    int beg_x = padding;
    int beg_y = padding;
    int end_x = beg_x + (width - kernel_size + 1);
    int end_y = beg_y + (height - kernel_size + 1);

    int x;
    int y;
    
    for (int y = beg_y; y < end_y; y++){
        for(int x = beg_x; x < end_x; x++){
            int idx = (y * width + x) * channels;
            int area[]=
            image[idx] = conv_matrix_multiply(area, kernel, kernel_size);
        }
    }

    

    width = (width - kernel_size + 2 * padding) + 1;
    height = (height - kernel_size + 2 * padding) + 1;
    

}