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
    Button(vector2d* p, vector2d* s, SDL_Texture* t);
    ~Button();
    void draw();
    void update(double deltaTime);
    void handleEvent(SDL_Event* e);
  private:
    
};

#endif /* Button_hpp */
