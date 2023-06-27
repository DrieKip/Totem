//
//  InGameButton.cpp
//  Totem
//
//  Created by Rens Weerman on 2/18/23.
//

#include "InGameButton.hpp"
#include <stdio.h>
#include "Player.hpp"
#include <iostream>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "SceneManager.hpp"
#include "GameObjectLoader.hpp"
#include <vector>
std::vector<Door*> InGameButton::doors;
InGameButton::InGameButton(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id) :
    GameObject(p, s, texture, hasCol) {
        door_id = id;
        this->id = "InGameButton";

}
void InGameButton::buttonUp() {
    tex = GameObjectLoader::buttonUp;
    //col->setPosition(new vector2d(position->x, position->y));
    //col->bounds.h = 8;
    for (Door* door : doors) {
        if (door->door_id == this->door_id) {
            door->closeDoor();
        }
    }
}
void InGameButton::buttonDown() {
    tex = GameObjectLoader::buttonDown;
    col->bounds.h = 20;
    col->bounds.y = position->y + 20;
    for (Door* door : doors) {
        if (door->door_id == this->door_id) {
            door->openDoor();
        }
    }
}
void InGameButton::update(double deltaTime){
    if (!isPressed) {
        buttonUp();
    }
}
void InGameButton::onCollision(GameObject* otherObj) {
    /*if (otherObj->id != "Player" && otherObj->id != "TotemBlock") {
        return;
    }*/
        buttonDown();
        isPressed = true;
//    std::cout << otherObj->id;
    if (otherObj->id == "Player") {
        isPressed = false;
    }
}
