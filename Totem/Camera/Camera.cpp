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
    double addX = 0.0015 * deltaTime * (position->x - player->position->x);
    double addY = 0.0015 * deltaTime * (position->y - player->position->y);
    if (abs(position->x - player->position->x) >= 5) {
        position->x -= addX;
    }
    if (abs(position->y - player->position->y) >= 5) {
        position->y -= addY;
    }
    //position = player->position;
}
void Camera::rectToCamera(SDL_Rect &rect) {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    rect.x -= position->x - Width/2 + 32;
    rect.y -= position->y - Height/2 + 32;
}
