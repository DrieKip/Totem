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

TotemBlock::TotemBlock(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, int num, Player* play) :
    GameObject(p, s, texture, hasCol)
{
    blockInt = num;
    player = play;
    id = "TotemBlock";
    velocity = new vector2d(0,0);
    grounded = true;
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
                if (position->y > otherObj->position->y) {
                    changes.y = otherObj->position->y + 64 - position->y;
                } else {
                    player->velocity->y = 0;
                    changes.y = otherObj->position->y - 64 - position->y;
                }
            } else {
                if (position->x > otherObj->position->x) {
                    changes.x =  otherObj->position->x + otherObj->size->x * 4 - position->x;
                } else {
                    changes.x = otherObj->position->x- 64 - position->x ;
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
            if (position->y > otherObj->position->y) {
                position->y = otherObj->position->y + 64;
            } else {
                grounded = true;
                position->y = otherObj->position->y - 64;
            }
        } else {
            if (position->x > otherObj->position->x) {
                position->x = otherObj->position->x + otherObj->size->x * 4;
            } else {
                position->x = otherObj->position->x- 64;
            }
        }
    }
}
void TotemBlock::update(double deltaTime) {
    if (blockInt > -1) {
        position->x = player->position->x;
        position->y = player->position->y - blockInt * 64;
    } else if (blockInt <= -1) {
        if (!grounded) {
            velocity->y += 0.025 * deltaTime;
        }
        if (velocity->y >= 5) {
            velocity->y = 5;
        }
        
    }
    if (id == "TotemBlock") {
        grounded = false;
    }
    if (col != NULL) {
        col->setPosition(position);
    }
    Collisions::CheckCollision(col);
    position->y += velocity->y * 0.1 * deltaTime;
}
