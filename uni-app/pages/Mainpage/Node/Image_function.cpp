#include <iostream>
extern uint8_t **opening_image(uint8_t**);
extern int* rgb_image_size();
extern void writingtodoc(uint8_t**, int, int);

int main() {
    int *arr = rgb_image_size(); int width = arr[0]; int height = arr[1];

    uint8_t **image_matrix =  new uint8_t*[height];
    for(int i = 0; i < width; i++){image_matrix[i] = new uint8_t[width];}

    image_matrix = opening_image(image_matrix);

    writingtodoc(image_matrix, width, height);

    for(int i = 0; i < width; i++){delete [] image_matrix[i];}
    delete [] image_matrix;

}