//
//  UIObject.hpp
//  Totem
//
//  Created by Stan Weerman on 1/1/23.
//

#ifndef UIObject_hpp
#define UIObject_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "vars.hpp"
#include <string>


class UIObject {
  public:
    UIObject(vector2d* p, vector2d* s, SDL_Texture* t);
    virtual ~UIObject();
    vector2d* position;
    vector2d* size;
    SDL_Texture* texture;
    virtual void draw();
    virtual void update(double deltaTime);
  private:
};

#endif /* UIObject_hpp */
