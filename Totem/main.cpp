#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <string>
#include <vector>
#include "vars.hpp"
#include "GameObject.hpp"
#include <iostream>

using namespace std;

void Render();
void Update();
SDL_Texture* load_tex(string filename);

SDL_Window* gWindow = 0;
SDL_Texture* hutspot_tex = NULL;
SDL_Event e;
double deltaTime = 0;
vector<GameObject*> objList;
bool a = false;
bool d = false;

bool quit = true;

int main(int argc, char* args[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    gWindow = SDL_CreateWindow("Setting up SDL",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      640, 480, SDL_WINDOW_SHOWN);

    if (gWindow != 0) {
      gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    }
  }
  else {
    return 1;
  }
  hutspot_tex = load_tex("Assets/StanPot.png");

  GameObject* Hutspot = new GameObject(new vector2d(64,64), new vector2d(64,64), hutspot_tex);
    objList.push_back(Hutspot);
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    while (quit) {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency());
        Update();
        Render();
    }
    SDL_Quit();
  return 0;
}
void Update() {
    //Uint64 delta_time = SDL_TICKS_PASSED(startTime,SDL_GetTicks());
    //startTime = SDL_GetTicks();
    int counter = 1;
    while( SDL_PollEvent(&e) != 0 ) {
      //User requests quit
        counter++;
        if(e.type == SDL_QUIT ) {
            quit = false;
        }
        if (e.type == SDL_KEYDOWN){
            counter++;
            if (e.key.keysym.scancode == SDL_SCANCODE_A) {
                a = true;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_D) {
                d = true;
            }
            break;
        }
        if (e.type == SDL_KEYUP){
            counter++;
            if (e.key.keysym.scancode == SDL_SCANCODE_A) {
                a = false;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_D) {
                d = false;
            }
            break;
        }
    }
    if (a) {
        objList.at(0)->position->x -= 0.2 * deltaTime;
    }
    if (d) {
        objList.at(0)->position->x += 0.2 * deltaTime;
    }
    cout << endl << counter;
    //cout << endl << deltaTime;
    //cout << endl << objList.at(0)->position->x << " : " << objList.at(0)->position->x;
    //objList.at(0)->position->x = SDL_GetTicks() * 1/100;
}
void Render() {
  for (GameObject* obj : objList) {
    obj->draw();
  }
}

SDL_Texture* load_tex(string filename) {
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
  newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
  SDL_FreeSurface( loadedSurface );
  return newTexture;
}
