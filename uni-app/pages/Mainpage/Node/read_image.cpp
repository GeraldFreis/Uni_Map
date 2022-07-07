#include <stdint.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image.h"
#include <fstream>
#include <istream>

int* rgb_image_size(){
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("Pathway.png", &width, &height, &bpp, 3); // loading the image as uint8 type
    stbi_image_free(rgb_image);

    int *arr = new int[2];
    arr[0] = width;
    arr[1] = height;

    return arr;
}

uint8_t **opening_image(uint8_t** image_matrix){
    int width, height, bpp, row = 1, column = 0;

    uint8_t* rgb_image = stbi_load("Pathway.png", &width, &height, &bpp, 3); // loading the image as uint8 type

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
                std::cout << r << " " << c << "\n";
            }
        }
    }
    stbi_image_free(rgb_image);
    return image_matrix;
}

void writingtodoc(uint8_t** image_matrix, int width, int height){

    std::ofstream MyFile("co_ordinates.txt");

  // Write to the file
  for(int i = 0; i < width; i++){
    for(int j  = 0; j < height; j++){

        if(image_matrix[i][j] == 255){
            MyFile << i << ' ' << j << '\n';
        }
    }
  }

  // Close the file
  MyFile.close();
}

