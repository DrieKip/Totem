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
#include "SceneManager.hpp"
#include <vector>
using namespace std;
Player::Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol) :
    GameObject(p, s, texture, hasCol)
{
    id = "Player";
    velocity = new vector2d(0,0);
    TotemBlock* some_TotemBlock1 = new TotemBlock(new vector2d(0,0), new vector2d(16,16), tex, hasCol, 1, this);
    TotemBlock* some_TotemBlock2 = new TotemBlock(new vector2d(0,0), new vector2d(16,16), tex, hasCol, 2, this);
    SceneManager::objList.push_back(some_TotemBlock1);
    SceneManager::objList.push_back(some_TotemBlock2);
    blocks.push_back(some_TotemBlock1);
    blocks.push_back(some_TotemBlock2);
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
void Player::swapBlockUp() {
    position->y -= 64;
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks.at(i)->blockInt == 1) {
            blocks.at(i)->blockInt -= 1;
            blocks.at(i)->id = "Deactivated";
        }
        if (blocks.at(i)->blockInt != -1) {
            blocks.at(i)->position->y += 64;
            blocks.at(i)->blockInt -= 1;
        }
    }
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
    if (Input::key_P == Input::PRESSED) {
        swapBlockUp();
    }
    
        position->y += velocity->y * 0.1 * deltaTime;
    
    grounded = false;
    if (col != NULL) {
        col->setPosition(position);
    }
    Collisions::CheckCollision(*col);
}

void Player::onCollision(GameObject* otherObj){
    if (otherObj->id != "player") {
        SDL_Rect intersection;
        SDL_IntersectRect(&(this->col->bounds), &(otherObj->col->bounds), &intersection);
        if (otherObj->id == "TotemBlock") {
            //if (dynamic_cast<TotemBlock*>((otherObj))->blockInt != -1) {
                return;
            //}
            if (dynamic_cast<TotemBlock*>((otherObj))->blockInt == -1) {
                std::cout << std::endl << "EDADAED" << SDL_GetTicks();
            }
        }
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
}
