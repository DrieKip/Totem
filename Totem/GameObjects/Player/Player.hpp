//
//  Player.hpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "ParticleEffect.hpp"
#include <vector>

class ParticleEffect;
class Player : public GameObject {
public:
    Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol);
    ~Player();
    void draw();
    void draw(SDL_Texture* texture, vector2d offset, vector2d size);
    void update(double deltaTime);
    void onCollision(GameObject* otherObj);
    vector2d* velocity;
    bool isDead = false;
    Collider* checkCol;
private:
    ParticleEffect* feetPart;
    bool grounded;
    bool extraCheck;
    bool wallClimb;
    
    SDL_Texture* foot1;
    SDL_Texture* foot2;
    SDL_Texture* body;
    SDL_Texture* head;
    SDL_Texture* weapon;
    vector2d foot1AnimOffset[4] = {vector2d(1,0), vector2d(0,0), vector2d(1,-1), vector2d(2,0)};
    vector2d foot2AnimOffset[4] = {vector2d(1,-1), vector2d(2,0), vector2d(1,0), vector2d(0,0)};
    vector2d bodyAnimOffset[4] = {vector2d(0,0), vector2d(1,0), vector2d(1,1), vector2d(0,1)};
    vector2d headAnimOffset[4] = {vector2d(0,0), vector2d(1,-1), vector2d(2,-1), vector2d(1,0)};
    vector2d weaponAnimOffset[4] = {vector2d(0,0), vector2d(1,0), vector2d(1,0), vector2d(0,0)};
    //vector2d headAnimOffset[4] = {vector2d(0,0), vector2d(0,0), vector2d(0,0), vector2d(0,0)};
    int animationIndex = 0;
    double animationFrameTime = 100.0;
    double addTime = 0.0;
};

#endif /* Player_hpp */
