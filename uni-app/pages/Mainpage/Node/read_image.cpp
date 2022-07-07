#include <stdint.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image.h"

int main() {
    int width, height, bpp, counter=0;

    uint8_t* rgb_image = stbi_load("Pathway.png", &width, &height, &bpp, 3); // loading the image as uint8 type
    for(int i = 0; i < width*height; i++){
        if(rgb_image[i] == 0){
            std::cout <<  "Worked" << i << "\n";
        }
    }
    stbi_image_free(rgb_image);
    return 0;
}