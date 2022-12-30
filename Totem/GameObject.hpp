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
#include <stdio.h>
class GameObject {
  public:
    GameObject();
    GameObject(vector2d* p, vector2d* s, SDL_Texture* texture);
    ~GameObject();
    virtual void draw();
    virtual void update();
    vector2d* position;
    vector2d* size;
    SDL_Texture* tex;
  private:
    
};
#endif /* GameObject_hpp */
