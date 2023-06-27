//
//  Door.cpp
//  Totem
//
//  Created by Rens Weerman on 2/18/23.
//

#include "Door.hpp"
#include "InGameButton.hpp"
#include <stdio.h>
#include "Player.hpp"
#include <iostream>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "TotemBlock.hpp"
#include "SceneManager.hpp"
#include "GameObjectLoader.hpp"
#include <vector>

Door::Door(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id) :
    GameObject(p, s, texture, hasCol) {
        InGameButton::doors.push_back(this);
        door_id = id;
}
void Door::openDoor() {
    tex = NULL;
    Collisions::removeCollider(col);
    isOpen = true;
}
void Door::closeDoor() {
    tex = GameObjectLoader::door;
    isOpen = false;
    Collisions::AddCollider(col);
}

