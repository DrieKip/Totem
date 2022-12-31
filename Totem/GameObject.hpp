//
//  GameObject.hpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <SDL2/SDL.h>
#include "vars.hpp"
#include "Collider.hpp"
#include "Collisions.hpp"
#include <stdio.h>
#include <string>
class Collider;

class GameObject {
  public:
    GameObject();
    GameObject(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol);
    virtual ~GameObject();
    virtual void draw();
    virtual void update(double deltaTime);
    virtual void onCollision(GameObject* otherObj);
    vector2d* position;
    vector2d* size;
    SDL_Texture* tex;
    std::string id;
    SDL_RendererFlip flipType;
    Collider* col;
  private:
    
};
#endif /* GameObject_hpp */
