#include <cmath>
#include <iostream>
#include <vector>

/*
Point structure to represent pixels
-> has attrs: int x, y
-> has functions:
    - '-' operator overloaded to find midpoint between point 1 and point 2
*/
struct Point {
  int x;
  int y;

  // constructors
  Point(int _x, int _y) {
    y = _x;
    x = _y;
  }
  Point() {
    x = 0;
    y = 0;
  }

  // creating a vector between two points
  Point operator-(const Point &p) {
    Point newpoint;
    newpoint.x = p.x - this->x;
    newpoint.y = p.y - this->y;
    return newpoint;
  }

    // testing if two points are equivalent
  bool operator==(const Point &last_point) {
    if(this->x == last_point.x && this->y == last_point.y){
        return true;

    }
    return false;
  }
  Point operator=(const Point &last_point){
    Point newpoint;
    newpoint.x = last_point.x; newpoint.y = last_point.y;
    return newpoint;
  }

  bool operator!=(const Point &last_point){
    if(this->x != last_point.x || this->y != last_point.y){
        return false;
    }
    else {
        return true;
    }
  }

  // calculating the middlepoint between two points / pixels
  Point calcmiddle(const Point *p) {
    Point newpoint;
    newpoint.x = p->x - 0.03125 * (p->x - this->x) / 2;
    newpoint.y = p->y - 0.03125 * (p->y - this->y) / 2;
    return newpoint;
  }
};

/*
Function: creates a middle point to be evaluated against between the current
pixel and end pixel Preconditions -> current pixel (x,y) & end pixel (x,y)
Postconditions -> returns a vector {index 0 = x, index 1 = y}
*/
Point middle_point_calc(Point *end_point, Point *current_point) {
  // finding the middle point using vectorization of points
  Point middle_of_vector = end_point->calcmiddle(current_point);
  return middle_of_vector;
}

/* finding the direction of the current point to middle point
Preconditions -> reference to pixel_matrix, reference to middle_point, reference
to current_point Postcondition -> returns a string either 'L', 'R', 'U', 'D' to
signify the direction of middle point from current point
*/
std::string direction_to_middle_p(uint8_t **pixel_matrix, Point *middle_point,
                                  Point *current_point, Point* end_point) {
  int current_x = current_point->x;
  int current_y = current_point->y;
  int middle_x = middle_point->x;
  int middle_y = middle_point->y;

  // finding distances to the middle point
  int distance_right =
      sqrt(pow(middle_x - (current_x - 1), 2) + pow(middle_y - (current_y), 2));
  int distance_left =
      sqrt(pow(middle_x - (current_x + 1), 2) + pow(middle_y - (current_y), 2));
  int distance_up =
      sqrt(pow(middle_x - (current_x), 2) + pow(middle_y - (current_y - 1), 2));
  int distance_down =
      sqrt(pow(middle_x - (current_x), 2) + pow(middle_y - (current_y + 1), 2));
   int distance_left_to_final = sqrt((pow(end_point->x-(current_x - 1),2))+(pow(end_point->y-(current_y),2)));
   int distance_down_to_final = sqrt((pow(end_point->x-current_x,2))+(pow(end_point->y-(current_y+1),2)));

   int distance_right_to_final = sqrt((pow(end_point->x-(current_x+1),2))+(pow(end_point->y-(current_y),2)));
   int distance_up_to_final = sqrt((pow(end_point->x-(current_x),2))+(pow(end_point->y-(current_y-1),2)));
  


  if (distance_left > distance_right && distance_left > distance_down &&
      distance_left > distance_up) {
        // std::cout << distance_left << " " << distance_right << " " << distance_down << " "<< distance_up << "\n";
    return "L";

  } else if (distance_right > distance_left && distance_right > distance_down &&
             distance_right > distance_up) {
            // std::cout << distance_left << " " << distance_right << " " << distance_down << " "<< distance_up << "\n";
    return "R";

  } else if (distance_down > distance_left && distance_right < distance_down &&
             distance_down > distance_up) {
            // std::cout << distance_left << " " << distance_right << " " << distance_down << " "<< distance_up << "\n";
    return "D";

  } else if (distance_up > distance_left && distance_up > distance_right &&
             distance_down < distance_up) {
            // std::cout << distance_left << " " << distance_right << " " << distance_down << " "<< distance_up << "\n";
    return "U";
  }
  // maybe change this as we do not always want to choose left or right
  else if (distance_left == distance_up || distance_left == distance_down) {
    if (distance_left_to_final < distance_down_to_final && distance_left_to_final < distance_up_to_final){
        return "L";
    }
    else if(distance_up_to_final < distance_down_to_final && distance_up_to_final < distance_left_to_final){
        return "U";
    }
    else if(distance_down_to_final < distance_left_to_final && distance_down_to_final < distance_up_to_final){
        return "D";
    }
    else {
        return "L";
    }
  } else if (distance_right == distance_up || distance_right == distance_down) {
    if (distance_right_to_final < distance_up_to_final && distance_right_to_final < distance_down_to_final){
        return "R";
    }
    else if(distance_down_to_final<distance_right_to_final && distance_down_to_final<distance_up_to_final){
        return "D";
    }
    else if(distance_up_to_final<distance_right_to_final && distance_up_to_final<distance_down_to_final){
        return "U";
    }
    else{
        return "R";
    }

  } else {
    return "Some values were equal";
  }
}

/*
Checking if at least one pixel towards the middlepoint between current point and
end point is black Preconditions -> reference to pixel matrix, reference to
current point, reference to middle point Postconditions -> returns bool
*/
bool if_black(uint8_t **pixel_matrix, Point *middle_point,
              Point *current_point, Point *end_point) {

  int current_x = current_point->x;
  int current_y = current_point->y;
  int middle_x = middle_point->x;
  int middle_y = middle_point->y;

  std::string direction = direction_to_middle_p(pixel_matrix, middle_point, current_point,end_point);
//   std::cout << direction << "\n";
  if (direction == "Some values were equal") {
    return false;
  }
  // checking if any pixels in the direction returned were / are black
  if (direction == "D") {
    if (pixel_matrix[current_y + 1][current_x] <= 10 ||
        pixel_matrix[current_y + 1][current_x + 1] <= 10 ||
        pixel_matrix[current_y + 2][current_x + 1] <=10 ||
        pixel_matrix[current_y + 2][current_x - 1] <=10 ||
        pixel_matrix[current_y + 2][current_x + 2] <=10 ||
        pixel_matrix[current_y + 2][current_x - 2] <=10 ||
        pixel_matrix[current_y + 1][current_x - 1] <= 10 ||
        pixel_matrix[current_y + 2][current_x] <= 10){
      return true;
    }
  }

  else if (direction == "U") {
        if ((pixel_matrix[current_y - 1][current_x] <= 10 ||
            pixel_matrix[current_y - 1][current_x - 1] <= 10 ||
            pixel_matrix[current_y - 1][current_x + 1] <= 10 ||
            pixel_matrix[current_y - 2][current_x - 1] <= 10 ||
            pixel_matrix[current_y - 2][current_x + 1] <= 10 ||
            pixel_matrix[current_y - 2][current_x - 2] <= 10 ||
            pixel_matrix[current_y - 2][current_x + 2] <= 10 ||
            pixel_matrix[current_y - 2][current_x] <= 10)){
        return true;
        }
    }

  else if (direction == "R") {
    if (pixel_matrix[current_y][current_x - 1] <= 10 ||
        pixel_matrix[current_y - 1][current_x - 1] <= 10 ||
        pixel_matrix[current_y - 1][current_x - 2] <= 10 ||
        ((current_y-2>=0) && (pixel_matrix[current_y - 2][current_x - 2] <= 10 )) ||
        pixel_matrix[current_y][current_x - 2] <= 10 ||
        pixel_matrix[current_y + 1][current_x - 2] <=10 ||
        pixel_matrix[current_y + 1][current_x - 1] <= 10 ||
        pixel_matrix[current_y+2][current_x-2] <= 10) {
    return true;
    }
  }

  else if (direction == "L") {
        if (pixel_matrix[current_y][current_x + 1] <= 10 ||
            pixel_matrix[current_y + 1][current_x + 1] <= 10 ||
            (current_y-2>=0 && (pixel_matrix[current_y-2][current_x+2] <= 10))||
            pixel_matrix[current_y+2][current_x+2] <= 10 ||
            pixel_matrix[current_y-1][current_x+2] <= 10 ||
            pixel_matrix[current_y+1][current_x+2] <= 10 ||
            pixel_matrix[current_y - 1][current_x + 1] <= 10 ||
            pixel_matrix[current_y][current_x+2] <= 10) {
        return true;
        }

  } else {
    std::cout << "exception should have been caught (if_black function)"
              << "\n";
  }
  return false;
}



/*
Function that updates the current point to the point closest to the middle point between the current point and end point
Preconditions -> pixel matrix, current point, direction
Postconditions -> a point (this will be the new point)
*/
Point moving_to_closest_pixel(uint8_t **pixel_matrix, Point *current_point, std::string direction){
    
    Point changed_point;
    int current_x = current_point->x; int current_y = current_point->y;

    if(current_x >= 0 && current_y >= 0){

        if(direction  == "L"){
            if(pixel_matrix[current_point->y][current_point->x-1] <= 10){ 
                changed_point.y = current_point->y; changed_point.x = current_point->x-1;
            }
            else if(pixel_matrix[current_point->y-1][current_point->x-1] <= 10) {
                changed_point.y = current_point->y - 1; changed_point.x = current_point->x - 1;
            }
            else if(pixel_matrix[current_point->y+1][current_point->x-1] <= 10) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x - 1;
            }

            else if(pixel_matrix[current_point->y][current_point->x-2] <= 10){ 
                changed_point.y = current_point->y; changed_point.x = current_point->x-2;
            }
            else if(pixel_matrix[current_point->y-1][current_point->x-2] <= 10) {
                changed_point.y = current_point->y - 1; changed_point.x = current_point->x - 2;
            }
            else if(pixel_matrix[current_point->y+1][current_point->x-2] <= 10) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x - 2;
            }

            else if(pixel_matrix[current_point->y-2][current_point->x-2] <= 10) {
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x - 2;
            }
            else if(pixel_matrix[current_point->y+2][current_point->x-2] <= 10) {
                changed_point.y = current_point->y + 2; changed_point.x = current_point->x - 2;
            }

            else if(pixel_matrix[current_point->y+1][current_point->x] <= 10) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x;
            }

            else {
                std::cout << "Left should not have been called (moving_to_closest_pixel)" << "\n";
            }
        }

        else if(direction  == "R"){
            // changed_point.x = current_point->x + 1; changed_point.y = current_point->y;
            if(pixel_matrix[current_point->y][current_point->x+1] <= 10){ 
                changed_point.y = current_point->y; changed_point.x = current_point->x+1;
            }
            else if(pixel_matrix[current_point->y-1][current_point->x+1] <= 10) {
                changed_point.y = current_point->y - 1; changed_point.x = current_point->x + 1;
            }
            else if(pixel_matrix[current_point->y+1][current_point->x+1] <= 20 ) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x + 1;
            }

            else if(pixel_matrix[current_point->y][current_point->x+2] <= 10){ 
                changed_point.y = current_point->y; changed_point.x = current_point->x+2;
            }
            else if(pixel_matrix[current_point->y-1][current_point->x+2] <= 10) {
                changed_point.y = current_point->y - 1; changed_point.x = current_point->x + 2;
            }
            else if(pixel_matrix[current_point->y+1][current_point->x+2] <= 20 ) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x + 2;
            }
            
            else if(pixel_matrix[current_point->y-2][current_point->x+2] <= 10) {
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x + 2;
            }
            else if(pixel_matrix[current_point->y+2][current_point->x+2] <= 20 ) {
                changed_point.y = current_point->y + 2; changed_point.x = current_point->x + 2;
            }
            else {
                std::cout << "Right should not have been called (moving_to_closest_pixel)" << "\n";
            }
        }

        else if(direction  == "D"){
            // changed_point.x = current_point->x; changed_point.y = current_point->y + 1;
            if(pixel_matrix[current_point->y+1][current_point->x] <= 10){ 
                changed_point.y = current_point->y+1; changed_point.x = current_point->x;
            }
            else if(pixel_matrix[current_point->y+1][current_point->x-1] <= 10) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x - 1;
            }
            else if(pixel_matrix[current_point->y+1][current_point->x+1] <= 10) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x + 1;
            }

            else if(pixel_matrix[current_point->y+2][current_point->x] <= 10){ 
                changed_point.y = current_point->y+2; changed_point.x = current_point->x;
            }
            else if(pixel_matrix[current_point->y+2][current_point->x-1] <= 10) {
                changed_point.y = current_point->y + 2; changed_point.x = current_point->x - 1;
            }
            else if(pixel_matrix[current_point->y+2][current_point->x+1] <= 10) {
                changed_point.y = current_point->y + 2; changed_point.x = current_point->x + 1;
            }

            else if(pixel_matrix[current_point->y+2][current_point->x-2] <= 10) {
                changed_point.y = current_point->y + 2; changed_point.x = current_point->x - 2;
            }
            else if(pixel_matrix[current_point->y+2][current_point->x+1] <= 10) {
                changed_point.y = current_point->y + 2; changed_point.x = current_point->x + 2;
            }

            else {
                std::cout << "Down should not have been called (moving_to_closest_pixel)" << "\n";
            }
        }

        else if(direction  == "U"){
            // changed_point.x = current_point->x; changed_point.y = current_point->y - 1;
            if(pixel_matrix[current_point->y-1][current_point->x] <= 10){ 
                changed_point.y = current_point->y - 1; changed_point.x = current_point->x;
            }
            else if(pixel_matrix[current_point->y-1][current_point->x-1] <= 10) {
                changed_point.y = current_point->y - 1; changed_point.x = current_point->x - 1;
            }
            else if(pixel_matrix[current_point->y-1][current_point->x+1] <= 10) {
                changed_point.y = current_point->y + 1; changed_point.x = current_point->x + 1;
            }

            else if(pixel_matrix[current_point->y-2][current_point->x] <= 10){ 
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x;
            }
            else if(pixel_matrix[current_point->y-2][current_point->x-1] <= 10) {
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x - 1;
            }
            else if(pixel_matrix[current_point->y-2][current_point->x+1] <= 10) {
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x + 1;
            }

            else if(pixel_matrix[current_point->y-2][current_point->x-1] <= 10) {
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x - 2;
            }
            else if(pixel_matrix[current_point->y-2][current_point->x+1] <= 10) {
                changed_point.y = current_point->y - 2; changed_point.x = current_point->x + 2;
            }
            else {
                std::cout << "Up should not have been called (moving_to_closest_pixel)" << "\n";
            }
        }
        else {
            std::cout << "Invalid direction" << "\n";
            changed_point.x = 0; changed_point.y = 0;
        }
    }
    return changed_point;
}
