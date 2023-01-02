//
//  UIObject.cpp
//  Totem
//
//  Created by Stan Weerman on 1/1/23.
//

#include "UIObject.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <string>
#include "vars.hpp"
#include <iostream>
#include "Camera.hpp"
#include "GameObject.hpp"

using namespace std;

UIObject::UIObject(vector2d* p, vector2d* s, SDL_Texture* t){
    position = p;
    size = s;
    texture = t;
}

UIObject::~UIObject(){
  delete size;
  delete position;
}

void UIObject::draw(){
    SDL_SetRenderDrawColor(gRenderer, 54, 25, 59, 255);
    //SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    some_rect.x = position->x;
    some_rect.y = position->y;
    some_rect.w = size->x *4;
    some_rect.h = size->y * 4;
    
    //Camera::rectToCamera(some_rect);
    SDL_RenderCopy(gRenderer, texture, NULL, &some_rect);
}

void UIObject::update(double deltaTime){
    
}
