//
//  Input.cpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#include "Input.hpp"
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>

bool Input::quit = true;
int Input::key_A = 0;
int Input::key_D = 0;
int Input::key_W = 0;
int Input::key_P = 0;
int Input::key_O = 0;
SDL_Event Input::forButton;

void Input::getInput() {
    SDL_Event e;
    //key_A = 0;
    //key_D = 0;
    key_P = 0;
    //key_O = 0;
    Input::forButton.type = 0;
    while( SDL_PollEvent(&e) != 0 ) {
      //User requests quit
        if(e.type == SDL_QUIT ) {
            Mix_PauseMusic();
           quit = false;
        }
        if(e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
            forButton = e;
            //std::cout << e.type << std::endl;
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
            if (e.key.keysym.scancode == SDL_SCANCODE_P) {
                key_P = PRESSED;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_O) {
                key_O = PRESSED;
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
            if (e.key.keysym.scancode == SDL_SCANCODE_P) {
                key_P = RELEASED;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_O) {
                key_O = RELEASED;
            }
            break;
        }
    }
}
