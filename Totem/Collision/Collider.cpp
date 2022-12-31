//
//  Collider.cpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#include "Collider.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <string>
#include "vars.hpp"
#include "GameObject.hpp"

Collider::Collider() {
    
}
Collider::Collider(vector2d* p, vector2d* s, GameObject* o){
    bounds.x = p->x;
    bounds.y = p->y;
    bounds.w = s->x * 4;
    bounds.h = s->y * 4;
    obj = o;
}
Collider::~Collider() {
}
void Collider::setPosition(vector2d* p) {
    bounds.x = p->x;
    bounds.y = p->y;
}

bool Collider::operator==(const Collider& c) const{
    return (bounds.x == c.bounds.x && bounds.y == c.bounds.y && bounds.w == c.bounds.w && bounds.h == c.bounds.h);
}

