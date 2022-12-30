//
//  Collider.hpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#ifndef Collider_hpp
#define Collider_hpp

#include <SDL2/SDL.h>
#include "vars.hpp"
#include <stdio.h>
class Collider {
  public:
    Collider();
    Collider(vector2d* p, vector2d* s, SDL_Texture* texture);
    ~Collider();
    void draw();
    vector2d* size;
    SDL_Texture* tex;
  private:
    
};

#endif /* Collider_hpp */
