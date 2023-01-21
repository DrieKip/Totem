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
#include "GameObjectLoader.hpp"
#include <vector>
using namespace std;

Player::Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol) :
    GameObject(p, s, texture, hasCol)
{
    id = "Player";
    velocity = new vector2d(0,0);
    TotemBlock* some_TotemBlock1 = new TotemBlock(new vector2d(0,0), new vector2d(16,16), GameObjectLoader::forTotemBlock, hasCol, 1, this);
    TotemBlock* some_TotemBlock2 = new TotemBlock(new vector2d(0,0), new vector2d(16,16), GameObjectLoader::forTotemBlock, hasCol, 2, this);
    SceneManager::objList.push_back(some_TotemBlock1);
    SceneManager::objList.push_back(some_TotemBlock2);
    blocks.push_back(some_TotemBlock1);
    blocks.push_back(some_TotemBlock2);
    TotemBlock* some_TotemBlock3 = new TotemBlock(new vector2d(0,0), new vector2d(16,16), GameObjectLoader::forTotemBlock, hasCol, 3, this);
    TotemBlock* some_TotemBlock4 = new TotemBlock(new vector2d(0,0), new vector2d(16,16), GameObjectLoader::forTotemBlock, hasCol, 4, this);
    SceneManager::objList.push_back(some_TotemBlock3);
    SceneManager::objList.push_back(some_TotemBlock4);
    blocks.push_back(some_TotemBlock3);
    blocks.push_back(some_TotemBlock4);
    grounded = false;
    if (hasCol) {
        checkCol = new Collider(position, new vector2d(4, 4), this);
        Collisions::AddCollider(col);
//        col->bounds.w = 64;
//        col->bounds.h = 64;
    }
}

Player::~Player(){
    delete velocity;
}

void Player::draw(){
    GameObject::draw();
}
void Player::swapBlockUp() {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks.at(i)->blockInt >= 1) {
        }
        if (blocks.at(i)->blockInt == 1) {
            blocks.at(i)->blockInt -= 1;
            position->y -=78;
            blocks.at(i)->position->y += 64;
            blocks.at(i)->id = "Deactivated";
            extraCheck = false;
        }
            blocks.at(i)->blockInt -= 1;
    }
}
void Player::swapBlockDown(int block) {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks.at(i)->blockInt >= 1) {
            blocks.at(i)->blockInt += 1;
        }
        if (blocks.at(i)->blockInt == block) {
            blocks.at(i)->blockInt = 1;
            blocks.at(i)->id = "TotemBlock";
            position->x = blocks.at(i)->position->x;
            position->y += 60;
            //blocks.at(i)->position->y -= 64;
        }
    }
    Input::key_O = 0;
}
void Player::update(double deltaTime){
    //std::cout << std::endl << Input::key_D;
    if (extraCheck == false) {
        grounded = false;
    }
    if (!grounded) {
        velocity->y += 0.025 * deltaTime;
    }
    
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
        grounded = false;
        velocity->y = -8.25;
    }
    if (Input::key_P == Input::PRESSED) {
        swapBlockUp();
    }
    extraCheck = false;
    //cout << endl << extraCheck;
    if (col != NULL) {
        col->setPosition(position);
        
        vector2d* somevec = new vector2d(0,0);
        somevec->x = position->x + 6 * 4;
        somevec->y = position->y + 64;
        checkCol->setPosition(somevec);
        delete somevec;
    }
    Collisions::CheckCollision(checkCol);
    Collisions::CheckCollision(col);
    position->y += velocity->y * 0.1 * deltaTime;
}

void Player::onCollision(GameObject* otherObj){
    if (otherObj->id == "TotemBlock") {
        return;
    }
    if (SDL_HasIntersection(&(checkCol->bounds), &(otherObj->col->bounds))) {
        extraCheck = true;
        if (otherObj->id == "Deactivated" && grounded && Input::key_O == Input::PRESSED) {
            grounded = false;
            swapBlockDown(static_cast<TotemBlock*>(otherObj)->blockInt);
        }
    }
    if (!SDL_HasIntersection(&(col->bounds), &(otherObj->col->bounds))) {
        return;
    }
    if (otherObj->id != "player" && otherObj->id != "TotemBlock") {
        SDL_Rect intersection;
        double someint = 0;
        //if (otherObj->id == "Deactivated") someint = 0.5;
        SDL_IntersectRect(&(this->col->bounds), &(otherObj->col->bounds), &intersection);
        if (intersection.h + 4 < intersection.w) {
            velocity->y = 0;
            if (extraCheck) {
                velocity->y = 0;
            }
            if (position->y > otherObj->position->y) {
                position->y = otherObj->position->y + otherObj->size->y * 4;
                otherObj->position->y -= someint;
            } else {
                grounded = true;
                position->y = otherObj->position->y - 64;
                otherObj->position->y += someint;
            }
        } else {
            if (position->x > otherObj->position->x) {
                position->x = otherObj->position->x + otherObj->size->x * 4;// + otherObj->size->x;
                otherObj->position->x -= someint;
            } else {
                position->x = otherObj->position->x- 64;
                otherObj->position->x += someint;
            }
        }
    }
}
