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
void Camera::setCamera() {
    position = player->position;
}
void Camera::rectToCamera(SDL_Rect &rect) {
    rect.x -= position->x - 320 + 32;
    rect.y -= position->y - 240 + 32;
}
