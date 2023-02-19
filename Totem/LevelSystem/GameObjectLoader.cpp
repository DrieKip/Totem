//
//  GameObjectLoader.cpp
//  Totem
//
//  Created by Rens Weerman on 1/1/23.
//

#include "GameObjectLoader.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include "GameObject.hpp"
#include "vars.hpp"

SDL_Texture* GameObjectLoader::load_tex(std::string filename) {
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
  newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
  SDL_FreeSurface( loadedSurface );
  return newTexture;
}

SDL_Texture* GameObjectLoader::forTotemBlock;
SDL_Texture* GameObjectLoader::forTile;
SDL_Texture* GameObjectLoader::buttonUp;
SDL_Texture* GameObjectLoader::buttonDown;
SDL_Texture* GameObjectLoader::door;

void GameObjectLoader::setTextures() {
    forTotemBlock = GameObjectLoader::load_tex("Assets/BlankTotemBlock.png");
    forTile = GameObjectLoader::load_tex("Assets/ground_tile.png");
    buttonUp = GameObjectLoader::load_tex("Assets/ButtonUp.png");
    buttonDown = GameObjectLoader::load_tex("Assets/ButtonDown.png");
    door = GameObjectLoader::load_tex("Assets/Door.png");
}
