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

Player::Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol) :
    GameObject(p, s, texture, hasCol)
{
    
}

Player::~Player(){
    
}

void Player::draw(){
    GameObject::draw();
}

void Player::update(double deltaTime){
    //std::cout << std::endl << Input::key_D;
    if (Input::key_D == Input::PRESSED) {
        flipType = SDL_FLIP_NONE;
        position->x += 0.2 * deltaTime;
    }
    if (Input::key_A == Input::PRESSED) {
        flipType = SDL_FLIP_HORIZONTAL;
        position->x -= 0.2 * deltaTime;
    }
    if (Input::key_W == Input::PRESSED) {
        position->y -= 0.2 * deltaTime;
    }
    
    position->y += 0.1 * deltaTime;
    if (col != NULL) {
        col->setPosition(position);
    }
    Collisions::CheckCollision(*col);
}

void Player::onCollision(GameObject* otherObj){
    std::cout << std::endl << "HIT!";
    position->y = otherObj->position->y - otherObj->size->y * 4;
}
