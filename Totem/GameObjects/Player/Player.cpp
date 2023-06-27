//
//  Player.cpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#include "Player.hpp"
#include <iostream>
#include <SDL2_mixer/SDL_mixer.h>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "SceneManager.hpp"
#include "GameObjectLoader.hpp"
#include <vector>
#include "InGameButton.hpp"
#include "ParticleEffect.hpp"
#include "Camera.hpp"
using namespace std;

Player::Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol) :
    GameObject(p, s, texture, hasCol)
{
    id = "Player";
    velocity = new vector2d(0,0);
    grounded = false;
    feetPart = new ParticleEffect(p, s, GameObjectLoader::particle, GameObjectLoader::outline, &flipType
                                  );
    feetPart->setInitialSize(vector2d(3, 3));
    feetPart->setInitialSpeed(vector2d(0.1,-0.05));
    feetPart->setOffset(vector2d(25, 20 * 4));
    feetPart->setSizeOverTime(vector2d(-0.0075, -0.0075));
    //ParticleEffect::ParticleEffect(vector2d* p, vector2d* s, SDL_Texture* texture)
    if (hasCol) {
        checkCol = new Collider(position, new vector2d(1, 1), this);
        Collisions::AddCollider(checkCol);
//        col->bounds.w = 64;
//        col->bounds.h = 64;
    }
    foot1 = GameObjectLoader::foot;
    foot2 = GameObjectLoader::foot;
    body = GameObjectLoader::body;
    head = GameObjectLoader::head;
    weapon = GameObjectLoader::weapon1;
}

Player::~Player(){
    delete velocity;
}

void Player::draw(){
    feetPart->draw();
    //GameObject::draw();
    if (!(grounded || wallClimb) && animationIndex == 0) {
        draw(body, vector2d(0,9), vector2d(12, 9));
        draw(foot1, vector2d(1,17), vector2d(4, 3));
        draw(foot2, vector2d(8,17), vector2d(4, 3));
        draw(head, vector2d(0,1), vector2d(13, 11));
        draw(weapon, vector2d(3, 9), vector2d(14,7));
        addTime = 0;
        return;
    }
    if (((Input::key_D == Input::PRESSED || Input::key_A == Input::PRESSED) && (grounded || wallClimb)) || animationIndex != 0) {
        draw(body, vector2d(0,8) + bodyAnimOffset[animationIndex], vector2d(12, 9));
        draw(foot1, vector2d(1,17) + foot1AnimOffset[animationIndex], vector2d(4, 3));
        draw(foot2, vector2d(8,17) + foot2AnimOffset[animationIndex], vector2d(4, 3));
        draw(head, vector2d(0,0) +  headAnimOffset[animationIndex], vector2d(13, 11));
        draw(weapon, vector2d(3, 9) + headAnimOffset[animationIndex], vector2d(14,7));
        return;
    }
        animationIndex = 0;
        addTime = 0.0;
        draw(body, vector2d(0,8), vector2d(12, 9));
        draw(foot1, vector2d(1,17), vector2d(4, 3));
        draw(foot2, vector2d(8,17), vector2d(4, 3));
        draw(head, vector2d(0,0), vector2d(13, 11));
        draw(weapon, vector2d(3, 9), vector2d(14,7));
    //feetPart->draw();
}
void Player::draw(SDL_Texture* texture, vector2d offset, vector2d size) {
    //SDL_SetRenderDrawColor(gRenderer, 68, 43, 72, 255);
    SDL_SetRenderDrawColor(gRenderer, 139, 210, 241, 255);
    //SDL_RenderClear(gRenderer);
    SDL_Rect some_rect;
    if (flipType == SDL_FLIP_HORIZONTAL) {
        //some_rect.x = position->x + (15 - offset.x) * 4;
        some_rect.x = position->x + (15 - (offset.x + size.x)) * 4;
    } else {
        some_rect.x = position->x + offset.x * 4;
    }
    some_rect.y = position->y + offset.y * 4;
    some_rect.w = size.x * 4;
    some_rect.h = size.y * 4;
    Camera::rectToCamera(some_rect);
    SDL_RenderCopyEx(gRenderer, texture, NULL, &some_rect, 0, NULL, flipType);
}
void Player::update(double deltaTime){
    //std::cout << std::endl << Input::key_D;
    addTime += deltaTime;
    if (addTime > animationFrameTime) {
        animationIndex = ++animationIndex % 4;
        addTime = 0;
    }
    feetPart->update(deltaTime);
    cout << velocity->x << endl;
    
    if (extraCheck == false) {
        feetPart->dontSpawn();
        grounded = false;
    }
    if (!grounded) {
        velocity->y += 0.015 * deltaTime;
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
        //feetPart->spawnParticles(10);
        grounded = false;
        feetPart->dontSpawn();
        velocity->y = -3;
    }
    if (Input::key_W == Input::PRESSED && wallClimb) {
        velocity->y = -1;
    }
    wallClimb = false;
    extraCheck = false;
    //cout << endl << extraCheck;
    if (col != NULL) {
        col->setPosition(position);
        
        vector2d* somevec = new vector2d(0,0);
        somevec->x = position->x + 7 * 4;
        somevec->y = position->y +  85;
        checkCol->setPosition(somevec);
        delete somevec;
    }
    Collisions::CheckCollision(checkCol);
    Collisions::CheckCollision(col);
    position->y += velocity->y * 0.1 * deltaTime;
}

void Player::onCollision(GameObject* otherObj){
    if (SDL_HasIntersection(&(checkCol->bounds), &(otherObj->col->bounds))) {
        extraCheck = true;
        if (grounded) {
            velocity->y = 0;
        }
    }
    if (!SDL_HasIntersection(&(col->bounds), &(otherObj->col->bounds))) {
        return;
    }
    if (otherObj->id != "player") {
        grounded = false;
        feetPart->dontSpawn();
        SDL_Rect intersection;
        //if (otherObj->id == "Deactivated") someint = 0.5;
        SDL_IntersectRect(&(this->col->bounds), &(otherObj->col->bounds), &intersection);
        if (intersection.h < intersection.w) {
            velocity->y = 0;
            if (position->y > otherObj->col->bounds.y) {
                position->y = otherObj->col->bounds.y + otherObj->col->bounds.h;
            } else {
                grounded = true;
                if (extraCheck == true) {
                    feetPart->Spawn();
                    feetPart->spawnParticles(5);
                }
                position->y = otherObj->col->bounds.y - 80;
            }
        } else {
            wallClimb = true;
            if (position->x > otherObj->col->bounds.x) {
                position->x = otherObj->col->bounds.x + otherObj->col->bounds.w;// + otherObj->size->x;
            } else {
                position->x = otherObj->col->bounds.x - 60;
            }
        }
    }
}
