//
//  Spike.cpp
//  Totem
//
//  Created by Rens Weerman on 2/19/23.
//

#include "Spike.hpp"
#include "GameObjectLoader.hpp"
#include <stdio.h>
#include "Player.hpp"
#include <iostream>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "TotemBlock.hpp"
#include "SceneManager.hpp"
#include "GameObjectLoader.hpp"
#include <vector>
#include "Input.hpp"

Spike::Spike(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id) :
    GameObject(p, s, texture, hasCol) {
}

void Spike::onCollision(GameObject* otherObj) {
    /*if (otherObj->id != "Player" && otherObj->id != "TotemBlock") {
        return;
    }*/
//    std::cout << otherObj->id;
    if (otherObj->id == "Player") {
        Input::quit = false;
    }
}
