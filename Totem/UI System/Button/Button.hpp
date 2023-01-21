//
//  Button.hpp
//  Totem
//
//  Created by Stan Weerman on 1/1/23.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "vars.hpp"
#include <string>
#include "UIObject.hpp"

class Button : public UIObject{
  public:
    Button(vector2d* p, vector2d* s, SDL_Texture* t, SDL_Texture* t2, SDL_Texture* t3);
    ~Button();
    void draw();
    void update(double deltaTime);
    void handleEvent();
    SDL_Texture* tex;
    SDL_Texture* hoverTex;
    SDL_Texture* pushTex;
  private:
    
};

#endif /* Button_hpp */
