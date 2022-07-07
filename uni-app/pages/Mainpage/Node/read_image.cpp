#include <stdint.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image.h"
#include <cmath>

int main() {
    int width, height, bpp, counter=0;
    int W_H = [];


    uint8_t* rgb_image = stbi_load("Pathway.png", &width, &height, &bpp, 3); // loading the image as uint8 type
    uint8_t matrix[width][height];

    for(int i = 0; i < width*height; i++){
       if (i > (1500-1)*height){
        height++;
       }
       std::cout<<matrix[width][height];
    }

    stbi_image_free(rgb_image);
    return 0;
}