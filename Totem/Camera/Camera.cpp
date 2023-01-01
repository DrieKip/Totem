//
//  Camera.cpp
//  Totem
//
//  Created by Rens Weerman on 12/31/22.
//

#include "Camera.hpp"
#include <SDL2/SDL.h>
#include "vars.hpp"
#include "GameObject.hpp"
#include "Player.hpp"

GameObject* Camera::player;
vector2d* Camera::position;
void Camera::setPlayer(GameObject* obj) {
    player = obj;
}
void Camera::setCamera(double deltaTime) {
    if (abs(position->x - player->position->x) >= 32) {
        if (position->x < player->position->x) position->x += 0.1 * deltaTime;
        if (position->x > player->position->x) position->x -= 0.1 * deltaTime;
    }
    if (abs(position->y - player->position->y) >= 32) {
        if (position->y < player->position->y) position->y += 0.5 * deltaTime;
        if (position->y > player->position->y) position->y -= 0.5 * deltaTime;
    }
    //position = player->position;
}
void Camera::rectToCamera(SDL_Rect &rect) {
    rect.x -= position->x - 320 + 40;
    rect.y -= position->y - 240 + 32;
}
