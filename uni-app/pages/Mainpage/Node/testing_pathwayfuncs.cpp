#include <iostream>
#include "pathway_funcs.cpp"
extern uint8_t **opening_image(uint8_t**);
extern int* rgb_image_size();
extern void writingtodoc(uint8_t**, int, int);
extern void get_image(int,int,uint8_t**);

int main() {
    int *arr = rgb_image_size(); int width = arr[0]; int height = arr[1];
    width =1500; height = 1500;
    
    uint8_t **image_matrix =  new uint8_t*[height];
    for(int i = 0; i < width; i++){image_matrix[i] = new uint8_t[width];}

    image_matrix = opening_image(image_matrix);

    // writingtodoc(image_matrix, width, height);

    // get_image(width, height, image_matrix);
    // end_point = 6, 1008, initial_point = 1, 1011
    Point end_point(6, 1008);
    Point current_point(1, 1011);
    std::cout << end_point.x << " " << end_point.y << "\n";
    
    Point middle_point = middle_point_calc(&end_point, &current_point);
    std::cout <<middle_point.x << " " << middle_point.y << "\n";

    std::string direction = direction_to_middle_p(image_matrix, &middle_point, &current_point);
    std::cout << direction << "\n";

    bool ifblk = if_black(image_matrix, &middle_point, &current_point);
    if(ifblk == false){
        std::cout << "false" << "\n";
    }
    else {
        std::cout << "true" << "\n";
    }



    for(int i = 0; i < width; i++){delete [] image_matrix[i];}
    delete [] image_matrix;

}