//
//  Player.cpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#include "Player.hpp"
#include <iostream>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "TotemBlock.hpp"

Player::Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol) :
    GameObject(p, s, texture, hasCol)
{
    id = "Player";
    velocity = new vector2d(0,0);
    TotemBlock* some_TotemBlock;
    some_TotemBlock = new TotemBlock(new vector2d(0,0), new vector2d(16,16), tex, hasCol, 1, this);
//    if (hasCol) {
//        col->bounds.w = 64;
//        col->bounds.h = 64;
//    }
}

Player::~Player(){
    
}

void Player::draw(){
    GameObject::draw();
}

void Player::update(double deltaTime){
    //std::cout << std::endl << Input::key_D;
    velocity->y += 0.025 * deltaTime;
    if (velocity->y >= 5) {
        velocity->y = 5;
    }
    if (Input::key_D == Input::PRESSED) {
        flipType = SDL_FLIP_NONE;
        position->x += 0.15 * deltaTime;
    }
    if (Input::key_A == Input::PRESSED) {
        flipType = SDL_FLIP_HORIZONTAL;
        position->x -= 0.15 * deltaTime;
    }
    if (Input::key_W == Input::PRESSED && grounded) {
        velocity->y = -7.5;
    }
    
        position->y += velocity->y * 0.1 * deltaTime;
    
    grounded = false;
    if (col != NULL) {
        col->setPosition(position);
    }
    Collisions::CheckCollision(*col);
}

void Player::onCollision(GameObject* otherObj){
    SDL_Rect intersection;
    SDL_IntersectRect(&(this->col->bounds), &(otherObj->col->bounds), &intersection);
    if (intersection.h < intersection.w) {
        velocity->y = 0;
        if (position->y > otherObj->position->y) {
            position->y = otherObj->position->y + 64;
        } else {
            grounded = true;
            position->y = otherObj->position->y - 64;
        }
    } else {
        if (position->x > otherObj->position->x) {
            position->x = otherObj->position->x + 64;
        } else {
            position->x = otherObj->position->x- 64;
        }
    }
}
