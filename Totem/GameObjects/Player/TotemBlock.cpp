//
//  TotemBlock.cpp
//  Totem
//
//  Created by Rens Weerman on 12/31/22.
//

#include "Player.hpp"
#include <iostream>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "TotemBlock.hpp"
#include "vars.hpp"
#include "InGameButton.hpp"

TotemBlock::TotemBlock(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, int num, Player* play) :
    GameObject(p, s, texture, hasCol)
{
    blockInt = num;
    player = play;
    id = "TotemBlock";
    velocity = new vector2d(0,0);
    grounded = true;
    checkCol = new Collider(position, new vector2d(32, 32), this);
    Collisions::AddCollider(col);
}
TotemBlock::~TotemBlock() {
    delete velocity;
}
void TotemBlock::draw() {
    GameObject::draw();
}
void TotemBlock::onCollision(GameObject* otherObj) {
    if (otherObj->id == "Player") {
        return;
    }
    if (SDL_HasIntersection(&(checkCol->bounds), &(otherObj->col->bounds))) {
        extraCheck = true;
    }
    if (!SDL_HasIntersection(&(col->bounds), &(otherObj->col->bounds))) {
        return;
    }
    if (id == "TotemBlock") {
        if (blockInt != -1) {
            SDL_Rect intersection;
            vector2d changes {0,0};
            SDL_IntersectRect(&(this->col->bounds), &(otherObj->col->bounds), &intersection);
            if (otherObj->id == "TotemBlock") {
                return;
            }
            if (intersection.h < intersection.w) {
                player->velocity->y = 0;
                if (position->y > otherObj->col->bounds.y) {
                    changes.y = otherObj->col->bounds.y + otherObj->col->bounds.h - position->y;
                } else {
                    player->velocity->y = 0;
                    changes.y = otherObj->col->bounds.y - 64 - position->y;
                }
            } else {
                if (position->x > otherObj->col->bounds.x) {
                    changes.x =  otherObj->col->bounds.x + otherObj->col->bounds.w - position->x;
                } else {
                    changes.x = otherObj->col->bounds.x- 64 - position->x ;
                }
            }
            *(player->position) += changes;
        }
    }
    if ((id == "Deactivated")) {
        if (otherObj->id == "TotemBlock") {
            return;
        }
        SDL_Rect intersection;
        SDL_IntersectRect(&(this->col->bounds), &(otherObj->col->bounds), &intersection);
        if (intersection.h < intersection.w) {
            velocity->y = 0;
            if (position->y > otherObj->col->bounds.y) {
                position->y = otherObj->col->bounds.y + otherObj->col->bounds.h;
            } else {
                grounded = true;
                position->y = otherObj->col->bounds.y - 64;
            }
        } else {
            if (position->x > otherObj->col->bounds.x) {
                //position->x = otherObj->col->bounds.x + otherObj->size->x * 4;
                position->x = otherObj->col->bounds.x + otherObj->col->bounds.w;
            } else {
                position->x = otherObj->col->bounds.x - 64;
            }
        }
    }
    if (SDL_HasIntersection(&(checkCol->bounds), &(otherObj->col->bounds))) {
        extraCheck = true;
        return;
    }
}
void TotemBlock::update(double deltaTime) {
    if (blockInt > -1) {
        position->x = player->position->x;
        position->y = player->position->y - blockInt * 64;
    } else if (blockInt <= -1) {
        if (extraCheck == false) {
            grounded = false;
        }
        if (!grounded) {
            velocity->y += 0.025 * deltaTime;
        }
        if (velocity->y >= 5) {
            velocity->y = 5;
        }
        
    }
        extraCheck = false;
    if (col != NULL) {
        col->setPosition(position);
        vector2d* somevec = new vector2d(0,0);
        somevec->x = position->x + 16;
        somevec->y = position->y + 40;
        checkCol->setPosition(somevec);
        delete somevec;
    }
    Collisions::CheckCollision(col);
    position->y += velocity->y * 0.1 * deltaTime;
}
