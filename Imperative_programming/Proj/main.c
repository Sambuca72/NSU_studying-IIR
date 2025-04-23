#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


/*TODO
    Median filter
	Gaussian filter
	Edge detection
	Convolution
    smth else from Opencv
*/

/*
    main.c:
    including header with functions or compiling with static lib
    main gets argv from console and calling functions 
*/



int main(int argc, char *argv[]) {
    
    if(argc < 3){
        fprintf(stderr, "Not enough parameters in input!");
    }
   
    //Parameters from input
    char *operation;
    char *path_input;
    char *path_output;
    char *additional_parameters;

    if(argc == 3){
        path_input = argv[0];
        operation = argv[1];
        path_output = argv[2];
    }else if(argc == 4){
        path_input = argv[0];
        operation = argv[1];
        additional_parameters = argv[2];
        path_output = argv[3];
    }

    int height, width, channels;
    unsigned char *img = stbi_load(path_input, &width, &height, &channels, 0);
    if (img) {
        printf("Image loaded: %dx%d, %d channels\n", width, height, channels);
    }

    printf("pep\n");
    fflush(stdout);
    

    stbi_write_jpg(path_output,width, height, channels, img, 100);

    


    // printf("%ld\n",strlen(img));
    stbi_image_free(img);
    return 0;
}