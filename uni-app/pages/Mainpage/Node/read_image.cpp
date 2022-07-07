#include <stdint.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image.h"
#include <fstream>
#include <istream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../../../node_modules/stb/stb_image_write.h"

// retrieving the image size (returns two element array containing width and height)
int* rgb_image_size(){
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("map.png", &width, &height, &bpp, 1); // loading the image as uint8 type
    stbi_image_free(rgb_image);

    int *arr = new int[2]; 
    arr[0] = width;
    arr[1] = height;

    return arr;
}

// getting the pixel data from the map image and transferring that into a 2D array
uint8_t **opening_image(uint8_t** image_matrix){
    int width, height, bpp, row = 1, column = 0;

    uint8_t* rgb_image = stbi_load("map.png", &width, &height, &bpp, 1); // loading the image as uint8 type

    for(int i = 0; i < width*height; i++){
        if(i == (row * width) - 1){ // if the current index is a multiple of the width - 1 we have to reset the index values
            image_matrix[row-1][column] = rgb_image[i];
            column = 0; // resetting the column to zero everytime we hit the column total
            row++; // incrementing the row everytime we hit a multiple of 1500 as that should be a new row
        }
        else {
            image_matrix[row-1][column] = rgb_image[i];
            column++;
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

        if(image_matrix[i][j] <=10){
            MyFile << i << ' ' << j << '\n';
        }
    }
  }

  // Close the file
  MyFile.close();
}

void get_image(int width, int height, uint8_t** image_matrix){
    for (int r = 0; r < width; r++){
        for (int c = 0; c<height; c++){
            if (image_matrix[r][c] <= 10){
                image_matrix[r][c] = 128;
            }
        }
    }

    uint8_t *One_D_array= new uint8_t [2250000];

    for (int r = 0; r < 1500; r++){
        for (int c = 0; c<1500; c++){
            One_D_array[r+c] = image_matrix[r][c];
        }
    }

    stbi_write_png("Change_Way.png", width/2, height/3, 2, One_D_array, 3*width);
 

}
