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
#include "SceneManager.hpp"
#include "UIObject.hpp"
#include "Button.hpp"
#include "GameObjectLoader.hpp"
#include "Map.hpp"

using namespace std;

void Render();
void Update();
SDL_Texture* load_tex(string filename);

SDL_Window* gWindow = 0;
SDL_Event e;
double deltaTime = 0;
bool a = false;
bool d = false;

bool quit = true;

int main(int argc, char* args[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
      SDL_DisplayMode DM;
      SDL_GetCurrentDisplayMode(0, &DM);
      auto Width = DM.w;
      auto Height = DM.h;
    gWindow = SDL_CreateWindow("TOTEM",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      Width, Height, SDL_WINDOW_SHOWN);
      SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
      //SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (gWindow != 0) {
      gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    }
  }
  else {
    return 1;
  }
    SDL_Texture* player_tex = load_tex("Assets/TotemBlock.png");
    SDL_Texture* ground_tex = load_tex("Assets/TileTest.png");
    SDL_Texture* stanPot = load_tex("Assets/StanPot.png");
    GameObjectLoader::setTextures();
    Map* some_map = new Map("LevelSystem/CreatingLevels/Totem.json");
    some_map->createMap();

    Player* Hutspot = new Player(new vector2d(300,64), new vector2d(16,16), player_tex, true);
    
    SceneManager::objList.push_back(Hutspot);
    
    UIObject* UI1 = new Button(new vector2d(164, 64), new vector2d(100,100), stanPot, player_tex, ground_tex);
    SceneManager::uiList.push_back(UI1);
    //GameObject* G1 = new GameObject(new vector2d(128, 64), new vector2d(16,16), stanPot, true);
    //SceneManager::objList.push_back(G1);
    
    Camera::position = new vector2d{0,0};
    Camera::setPlayer(Hutspot);
    
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
    Camera::setCamera(deltaTime);
    for (GameObject* obj : SceneManager::objList) {
        obj->update(deltaTime);
    }
    for (UIObject* ui : SceneManager::uiList) {
        ui->update(deltaTime);
    }
}
void Render() {
    SDL_RenderClear(gRenderer);
    for (GameObject* obj : SceneManager::objList) {
        obj->draw();
    }
    for (UIObject* ui : SceneManager::uiList) {
        ui->draw();
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
