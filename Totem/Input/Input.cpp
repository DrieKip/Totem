//
//  Input.cpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#include "Input.hpp"
#include <SDL2/SDL.h>

bool Input::quit = true;
int Input::key_A = 0;
int Input::key_D = 0;
int Input::key_W = 0;

void Input::getInput() {
    SDL_Event e;
    //key_A = 0;
    //key_D = 0;
    while( SDL_PollEvent(&e) != 0 ) {
      //User requests quit
            
        if(e.type == SDL_QUIT ) {
           quit = false;
        }
        if (e.type == SDL_KEYDOWN){
            if (e.key.keysym.scancode == SDL_SCANCODE_A) {
                key_A = PRESSED;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_D) {
                key_D = PRESSED;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_W) {
                key_W = PRESSED;
            }
            break;
        }
        if (e.type == SDL_KEYUP){
            if (e.key.keysym.scancode == SDL_SCANCODE_A) {
                
                key_A = RELEASED;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_D) {
                key_D = RELEASED;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_W) {
                key_W = RELEASED;
            }
            break;
        }
    }
}
