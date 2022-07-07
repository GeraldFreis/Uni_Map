#include <stdint.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image.h"

int main() {
    int width, height, bpp, row = 1, column = 0;

    uint8_t* rgb_image = stbi_load("Pathway.png", &width, &height, &bpp, 3); // loading the image as uint8 type
    uint8_t **image_matrix =  new uint8_t*[height];
    for(int i = 0; i < width; i++){image_matrix[i] = new uint8_t[width];}

    for(int i = 0; i < width*height; i++){
        if(i == (row * width) - 1){
            image_matrix[row-1][column] = rgb_image[i];
            column = 0;
            row++;
        }
        else {
            image_matrix[row-1][column] = rgb_image[i];
            column++;
        }
    }   

    int counter = 0;
    for(int r = 0; r < width; r++){
        for(int c = 0; c < width; c++){
            if(image_matrix[r][c] == 0){
                std::cout << image_matrix[r][c] << "\n";
            }
        }
    }
    // std::cout << counter;

    stbi_image_free(rgb_image);

    for(int i = 0; i < width; i++){delete [] image_matrix[i];}
    delete [] image_matrix;
    
    return 0;
}