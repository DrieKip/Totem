//
//  TileObject.cpp
//  Totem
//
//  Created by Rens Weerman on 1/1/23.
//

#include "TileObject.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
#include <iostream>
#include "Collider.hpp"
#include "GameObjectLoader.hpp"
#include <SDL2/SDL.h>
using namespace std;

TileObject::TileObject(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, vector2d srcPos) :
GameObject(p, s, texture, hasCol) {
    p->x *= 4;
    p->y *= 4;
    s->x *= 1;
    s->y *= 1;
    src = new SDL_Rect;
    src->x = srcPos.x;
    src->y = srcPos.y;
    src->w = 16;
    src->h = 16;
    //cout << endl << "YEP";
    if (hasCol) {
        col->setPosition(p);
    }
}
TileObject::~TileObject() {
    
}
void TileObject::draw() {
    SDL_SetRenderDrawColor(gRenderer, 139, 210, 241, 255);
    //SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    some_rect.x = position->x;
    some_rect.y = position->y;
    some_rect.w = size->x * 4;
    some_rect.h = size->y * 4;
    
    Camera::rectToCamera(some_rect);
    SDL_RenderCopyEx(gRenderer, tex, src, &some_rect, 0, NULL, flipType);
}
void TileObject::update(double deltaTime) {
    
}
void TileObject::onCollision(GameObject* otherObj) {
    
}
