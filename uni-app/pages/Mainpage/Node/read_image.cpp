#include <stdint.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image.h"

int main() {
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("Pathway.png", &width, &height, &bpp, 3);
    std::cout << width << "\n" << height << '\n';
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(rgb_image[i] == 0){
                std::cout << i << " ";
            }
        }
    }
    stbi_image_free(rgb_image);

    return 0;
}