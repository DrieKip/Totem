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
#include <iostream>
#include "Collisions.hpp"

using namespace std;

SDL_Renderer* gRenderer = 0;

GameObject::GameObject(){
  position->x=0;
  position->y=0;
  size->x=0;
  size->y=0;
    //col = NULL;
}

GameObject::GameObject(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol){
    position = p;
    size = s;
    tex = texture;
    flipType = SDL_FLIP_NONE;
    if (hasCol) {
        cout << endl << "EEDAEDADADADADAED";
        col = new Collider(position, size, this);
        Collisions::AddCollider(*col);
        
    }
}

GameObject::~GameObject(){
  delete size;
  delete position;
    delete col;
}

void GameObject::draw(){
    SDL_SetRenderDrawColor(gRenderer, 166, 255, 243, 255);
    //SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    some_rect.x = position->x;
    some_rect.y = position->y;
    some_rect.w = size->x *4;
    some_rect.h = size->y * 4;
    
    
    SDL_RenderCopyEx(gRenderer, tex, NULL, &some_rect, 0, NULL, flipType);
}

void GameObject::update(double deltaTime){
}
void GameObject::onCollision(GameObject* otherObj) {
    std::cout << "WELP";
}
