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
#include "Camera.hpp"
using namespace std;

void Render();
void Update();
SDL_Texture* load_tex(string filename);

SDL_Window* gWindow = 0;
SDL_Event e;
double deltaTime = 0;
vector<GameObject*> objList;
bool a = false;
bool d = false;

bool quit = true;

int main(int argc, char* args[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    gWindow = SDL_CreateWindow("TOTEM",
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
    SDL_Texture* player_tex = load_tex("Assets/TotemBlock.png");
    SDL_Texture* ground_tex = load_tex("Assets/ground_tile.png");

    Player* Hutspot = new Player(new vector2d(128,64), new vector2d(16,16), player_tex, true);
    GameObject* ground1 = new GameObject(new vector2d(64,300), new vector2d(16,16), ground_tex, true);
    GameObject* ground2 = new GameObject(new vector2d(128,300), new vector2d(16,16), ground_tex, true);
    GameObject* ground3 = new GameObject(new vector2d(192,300), new vector2d(16,16), ground_tex, true);
    GameObject* ground4 = new GameObject(new vector2d(192,364), new vector2d(16,16), ground_tex, true);
    GameObject* ground5 = new GameObject(new vector2d(256,364), new vector2d(16,16), ground_tex, true);
    GameObject* ground6 = new GameObject(new vector2d(320,364), new vector2d(16,16), ground_tex, true);
    GameObject* ground7 = new GameObject(new vector2d(384,364), new vector2d(16,16), ground_tex, true);
    GameObject* ground8 = new GameObject(new vector2d(384,300), new vector2d(16,16), ground_tex, true);
    GameObject* ground9 = new GameObject(new vector2d(320,108), new vector2d(16,16), ground_tex, true);
    objList.push_back(Hutspot);
    objList.push_back(ground1);
    objList.push_back(ground2);
    objList.push_back(ground3);
    objList.push_back(ground4);
    objList.push_back(ground5);
    objList.push_back(ground6);
    objList.push_back(ground7);
    objList.push_back(ground8);
    objList.push_back(ground9);
    
    Camera::setPlayer((objList.at(0)));
    
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
    Camera::setCamera();
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
