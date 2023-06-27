//
//  Particle.hpp
//  Totem
//
//  Created by Rens Weerman on 6/25/23.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "ParticleEffect.hpp"
#include <SDL2/SDL.h>
class ParticleEffect;
class Particle : public GameObject {
public:
    Particle(vector2d* p, vector2d s, SDL_Texture* texture, bool hasCol, vector2d srcPos, vector2d sizeChange, vector2d speed, vector2d speedChange, vector2d sizeRange, ParticleEffect* particleEffect);
    Particle(vector2d* p, vector2d s, SDL_Texture* texture, SDL_Texture* texture2, bool hasCol, vector2d srcPos, vector2d sizeChange, vector2d speed, vector2d speedChange, vector2d sizeRange, ParticleEffect* particleEffect);
    ~Particle();
    void draw();
    bool boolUpdate(double deltaTime);
    void onCollision(GameObject* otherObj);
    void drawOutline();
    SDL_Rect* src;
private:
    SDL_Texture* tex2;
    ParticleEffect* particleEffect;
    vector2d sizeChange;
    vector2d speed;
    vector2d speedChange;
    vector2d sizeRange;
    double loop;
    
};
#endif /* Particle_hpp */
