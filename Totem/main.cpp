#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <string>
#include <vector>
#include "vars.hpp"
#include "GameObject.hpp"
#include "Collider.hpp"
#include "Collisions.hpp"
#include "Player.hpp"
#include <iostream>
#include "Input.hpp"
using namespace std;

void Render();
void Update();
SDL_Texture* load_tex(string filename);

SDL_Window* gWindow = 0;
SDL_Texture* hutspot_tex = NULL;
SDL_Texture* player_tex = NULL;
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
    player_tex = load_tex("Assets/TotemBlock.png");
    hutspot_tex = load_tex("Assets/StanPot.png");

    Player* Hutspot = new Player(new vector2d(64,64), new vector2d(20,16), player_tex, true);
    GameObject* Somepot = new GameObject(new vector2d(64,300), new vector2d(200,16), hutspot_tex, true);
    objList.push_back(Hutspot);
    objList.push_back(Somepot);
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    while (Input::quit) {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency());
        Update();
        Render();
    }
    //eadad
    SDL_Quit();
  return 0;
}
void Update() {
    Input::getInput();
    for (GameObject* obj : objList) {
        obj->update(deltaTime);
    }
}
void Render() {
    SDL_RenderClear(gRenderer);
    for (GameObject* obj : objList) {
        obj->draw();
    }
    SDL_RenderPresent(gRenderer);
}
SDL_Texture* load_tex(string filename) {
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
  newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
  SDL_FreeSurface( loadedSurface );
  return newTexture;
}
