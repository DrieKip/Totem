//
//  ParticleEffect.cpp
//  Totem
//
//  Created by Rens Weerman on 6/25/23.
//

#include "ParticleEffect.hpp"
#include "Player.hpp"
#include <iostream>
#include <SDL2_mixer/SDL_mixer.h>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "SceneManager.hpp"
#include "GameObjectLoader.hpp"
#include <vector>
#include "InGameButton.hpp"
#include "Particle.hpp"
using namespace std;


ParticleEffect::ParticleEffect(vector2d* p, vector2d* s, SDL_Texture* texture, SDL_RendererFlip* flip) {
    tex = texture;
    position = p;
    size = *s;
    this->flip = flip;
}
ParticleEffect::ParticleEffect(vector2d* p, vector2d* s, SDL_Texture* texture, SDL_Texture* texture2, SDL_RendererFlip* flip) {
    tex = texture;
    position = p;
    size = *s;
    this->flip = flip;
}
void ParticleEffect::draw() {
    for (Particle* par : particles) {
        par->drawOutline();
    }
    for (Particle* par : particles) {
        par->draw();
    }
}
void ParticleEffect::update(double deltaTime) {
    if (*flip == SDL_FLIP_HORIZONTAL) {
        speed = savedSpeed;
        speedChange = savedSpeedChange;
    } else {
        speed = vector2d(savedSpeed.x * -1, savedSpeed.y * 1);
        speedChange = vector2d(savedSpeedChange.x * -1, savedSpeedChange.y * 1);
    }
    loop += deltaTime;
    if (loop > loopSize) {
        if ((Input::key_D == Input::PRESSED || Input::key_A == Input::PRESSED) && spawn) {
            spawnParticles(5);
        }
        loop = 0;
        loopSize = rand() % 200 + 100;
    }
    for (int i = 0; i < particles.size(); i++) {
        if (particles[i]->boolUpdate(deltaTime)) {
            removeParticle(particles[i]);
        }
    }
}

void ParticleEffect::setInitialSize(vector2d s) {
    size = s;
}
void ParticleEffect::setSizeOverTime(vector2d ds) {
    sizeChange = ds;
}
void ParticleEffect::setInitialSpeed(vector2d s) {
    speed = s;
    savedSpeed = s;
    
}
void ParticleEffect::setSpeedOverTime(vector2d ds) {
    speedChange = ds;
    savedSpeedChange = ds;
}
void ParticleEffect::spawnParticles(int amount) {
    for (int i = 0; i < amount; i++) {
        addParticle(new Particle(new vector2d(position->x + offset.x, position->y + offset.y), size, tex, tex2, false, size, sizeChange, speed, speedChange, sizeRange, this
                             ));
    }
}
//(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, vector2d srcPos, vector2d sizeChange, vector2d speed, vector2d speedChange, vector2d sizeRange)
void ParticleEffect::addParticle(Particle* par) {
    //std::list<Collider> Collisions::colliders;
    particles.push_back(par);
}
void ParticleEffect::removeParticle(Particle* par) {
    particles.erase(std::find(particles.begin(), particles.end(), par));
    delete par;
}
void ParticleEffect::clearParticles() {
    particles.clear();
}
void ParticleEffect::setOffset(vector2d offset) {
    this->offset = offset;
}

void ParticleEffect::dontSpawn() {
    spawn = false;
}
void ParticleEffect::Spawn() {
    spawn = true;
}

