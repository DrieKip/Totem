//
//  GameObject.cpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#include "GameObject.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <string>
#include "vars.hpp"

using namespace std;

SDL_Renderer* gRenderer = 0;

GameObject::GameObject(){
  position->x=0;
  position->y=0;
  size->x=0;
  size->y=0;
}

GameObject::GameObject(vector2d* p, vector2d* s, SDL_Texture* texture){
  position = p;
  size = s;
  tex = texture;
}

GameObject::~GameObject(){
  delete size;
  delete position;
}

void GameObject::draw(){
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    some_rect.x = position->x;
    some_rect.y = position->y;
    some_rect.w = size->x;
    some_rect.h = size->y;
    SDL_RenderCopy(gRenderer, tex, NULL, &some_rect);
    SDL_RenderPresent(gRenderer);
}

void GameObject::update(){
    
}
