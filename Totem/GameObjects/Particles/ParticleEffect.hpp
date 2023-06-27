//
//  ParticleEffect.hpp
//  Totem
//
//  Created by Rens Weerman on 6/25/23.
//

#ifndef ParticleEffect_hpp
#define ParticleEffect_hpp

#include <stdio.h>
#include <vector>
#include "Player.hpp"
#include <iostream>
#include <SDL2_mixer/SDL_mixer.h>
#include "Input.hpp"
#include <SDL2/SDL.h>
#include "SceneManager.hpp"
#include "GameObjectLoader.hpp"
#include <vector>
#include "InGameButton.hpp"
class Particle;
class ParticleEffect {
  public:
    ParticleEffect(vector2d* p, vector2d* s, SDL_Texture* texture, SDL_RendererFlip* flip);
    ParticleEffect(vector2d* p, vector2d* s, SDL_Texture* texture, SDL_Texture* texture2, SDL_RendererFlip* flip);
    void draw();
    void update(double deltaTime);
    void setInitialSize(vector2d s);
    void setSizeOverTime(vector2d ds);
    void setInitialSpeed(vector2d s);
    void setSpeedOverTime(vector2d ds);
    void spawnParticles(int amount);
    void addParticle(Particle* par);
    void removeParticle(Particle* par);
    void clearParticles();
    void setOffset(vector2d offset);
    void dontSpawn();
    void Spawn();
    //void onCollision(GameObject* otherObj);
    //vector2d* velocity;
    
    std::vector<Particle*> particles;
  private:
    
    vector2d* position;
    vector2d offset;
    vector2d size;
    vector2d sizeChange;
    vector2d speed;
    vector2d speedChange;
    vector2d sizeRange;
    vector2d speedRange;
    vector2d savedSpeed;
    vector2d savedSpeedChange;
    
    bool spawn;
    int spawnRate;
    SDL_Texture* tex;
    SDL_Texture* tex2;
    std::string id;
    bool grounded;
    bool extraCheck;
    double loop;
    double loopSize;
    SDL_RendererFlip* flip;
};
#endif /* ParticleEffect_hpp */
