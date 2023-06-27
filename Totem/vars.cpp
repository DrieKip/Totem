//
//  vars.cpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#include "vars.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <string>

using namespace std;

vector2d::vector2d(){
    x = 0;
    y = 0;
}

vector2d::vector2d(double xx, double yy){
  x = xx;
  y = yy;
}

void vector2d::operator+=(const vector2d& other){
    x += other.x;
    y += other.y;
}
vector2d vector2d::operator+(const vector2d& other){
    return vector2d(x + other.x, y + other.y);
}
vector2d vector2d::operator*(const vector2d& other){
    return vector2d(x * other.x, y * other.y);
}
