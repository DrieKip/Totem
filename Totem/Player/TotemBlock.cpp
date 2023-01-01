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

TotemBlock::TotemBlock(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, int num, Player* play) :
    GameObject(p, s, texture, hasCol)
{
    blockInt = num;
    player = play;
}
TotemBlock::~TotemBlock() {
    
}
void TotemBlock::draw() {
    GameObject::draw();
}
void TotemBlock::onCollision(GameObject* otherObj) {
    
}
void TotemBlock::update(double deltaTime) {
    position->x = player->position->x;
    position->y = player->position->x - blockInt * 64;
}
