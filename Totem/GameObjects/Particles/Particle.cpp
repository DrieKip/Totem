//
//  Particle.cpp
//  Totem
//
//  Created by Rens Weerman on 6/25/23.
//

#include "Particle.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
#include <iostream>
#include "Collider.hpp"
#include "GameObjectLoader.hpp"
#include <SDL2/SDL.h>
using namespace std;

Particle::Particle(vector2d* p, vector2d s, SDL_Texture* texture, bool hasCol, vector2d srcPos, vector2d sizeChange, vector2d speed, vector2d speedChange, vector2d sizeRange, ParticleEffect* particleEffect) : GameObject(p, &s, texture, hasCol) {
    /*p->x *= 4;
    p->y *= 4;
    s->x *= 1;
    s->y *= 1;
    src = new SDL_Rect;
    src->x = srcPos.x;
    src->y = srcPos.y;
    src->w = 8;
    src->h = 8;*/
    //cout << endl << "YEP";
    /*if (hasCol) {
        col->setPosition(position);
    }*/
    //srand(time(0));
    cout << sizeChange.x << endl;
    position = new vector2d(p->x + rand() % 25 - 12, p->y + rand() % 20 - 10);
    size = new vector2d(s.x + rand() % 10 / 10.0, s.y + rand() % 10 / 10.0 );
    this->sizeChange = sizeChange;
    this->speed = speed * vector2d(rand() % 100 / 100.0, rand() % 100 / 100.0);
    this->speedChange = speedChange;
    this->particleEffect = particleEffect;
   // this->sizeRange = new sizeRange
    
}
Particle::Particle(vector2d* p, vector2d s, SDL_Texture* texture, SDL_Texture* texture2, bool hasCol, vector2d srcPos, vector2d sizeChange, vector2d speed, vector2d speedChange, vector2d sizeRange, ParticleEffect* particleEffect) : GameObject(p, &s, texture, hasCol) {
    /*p->x *= 4;
    p->y *= 4;
    s->x *= 1;
    s->y *= 1;
    src = new SDL_Rect;
    src->x = srcPos.x;
    src->y = srcPos.y;
    src->w = 8;
    src->h = 8;*/
    //cout << endl << "YEP";
    /*if (hasCol) {
        col->setPosition(position);
    }*/
    //srand(time(0));
    tex2 = texture2;
    cout << sizeChange.x << endl;
    position = new vector2d(p->x + rand() % 25 - 12, p->y + rand() % 20 - 10);
    size = new vector2d(s.x + rand() % 10 / 10.0, s.y + rand() % 10 / 10.0 );
    this->sizeChange = sizeChange;
    this->speed = speed * vector2d(rand() % 100 / 100.0, rand() % 100 / 100.0);
    this->speedChange = speedChange;
    this->particleEffect = particleEffect;
   // this->sizeRange = new sizeRange
    
}

Particle::~Particle() {
    
}
void Particle::draw() {
    GameObject::draw();
    /*SDL_SetRenderDrawColor(gRenderer, 68, 43, 72, 255);
    //SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    some_rect.x = position->x;
    some_rect.y = position->y;
    some_rect.w = size->x * 4;
    some_rect.h = size->y * 4;
    
    Camera::rectToCamera(some_rect);
    SDL_RenderCopyEx(gRenderer, tex, NULL, &some_rect, 0, NULL, flipType);*/
}
void Particle::drawOutline() {
    GameObject::draw();
    SDL_SetRenderDrawColor(gRenderer, 139, 210, 241, 255);
    //SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    some_rect.w = (size->x + 2)  * 4;
    some_rect.h = (size->y + 2) * 4;
    some_rect.x = position->x - (some_rect.w  / 4);
    some_rect.y = position->y - (some_rect.h / 4);
    
    Camera::rectToCamera(some_rect);
    SDL_RenderCopyEx(gRenderer, GameObjectLoader::outline, NULL, &some_rect, 0, NULL, flipType);
}
bool Particle::boolUpdate(double deltaTime) {
    loop += deltaTime;
    if (loop > 1000) {
        
        //delete this;
        return true;
        //delete this;
    }
        vector2d vec(deltaTime, deltaTime);
        *position += speed * vec;
        speed += (speedChange * vec);
        *size += (sizeChange * vec);
    return false;
}
void Particle::onCollision(GameObject* otherObj) {
    
}
