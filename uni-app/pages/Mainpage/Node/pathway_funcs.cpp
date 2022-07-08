#include <iostream>
#include <vector>

/*
Point structure to represent pixels
-> has attrs: int x, y
-> has functions:
    - '-' operator overloaded to find midpoint between point 1 and point 2
*/
struct Point
 {
    int x;
    int y;

    // creating a vector between two points
    Point operator-(const Point& p){
        Point newpoint;
        newpoint.x = p.x - this->x;
        newpoint.y = p.y - this->y;
        return newpoint;
    }

    // calculating the middlepoint between two points / pixels
    Point calcmiddle(const Point *p){
        Point newpoint;
        newpoint.x = 0.5 * (p->x - this->x);
        newpoint.y = 0.5 * (p->y - this->y);
        return newpoint;
    }
};

/*
Function: creates a middle point to be evaluated against between the current pixel and end pixel
Preconditions -> current pixel (x,y) & end pixel (x,y)
Postconditions -> returns a vector {index 0 = x, index 1 = y}
*/
Point middle_point_calc(Point *end_point, Point *current_point){
    // finding the middle point using vectorization of points
    Point middle_of_vector = end_point->calcmiddle(current_point);
    return middle_of_vector;
} 

/*
Checking if at least one pixel towards the middlepoint between current point and end point is black
Preconditions -> reference to pixel matrix, reference to current point, reference to middle point
Postconditions -> returns bool
*/

bool if_black(uint8_t **pixel_matrix, Point *middle_point_calc, Point *current_point){
    int current_x = current_point->x; int current_y = current_point->y;
}

