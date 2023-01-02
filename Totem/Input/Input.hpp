//
//  Input.hpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
class Input {
public:
    static int key_A;
    static int key_D;
    static int key_W;
    static int key_P;
    static int key_O;
    static bool quit;
    static enum states {NO_PRESS = 0, PRESSED, RELEASED};
    static void getInput();
    static SDL_Event* forButton;
private:
    
};
#endif /* Input_hpp */
