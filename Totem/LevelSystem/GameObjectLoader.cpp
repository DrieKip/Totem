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
#include <SDL2_mixer/SDL_mixer.h>

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
SDL_Texture* GameObjectLoader::spike;
SDL_Texture* GameObjectLoader::lava;
SDL_Texture* GameObjectLoader::particle;
SDL_Texture* GameObjectLoader::outline;
SDL_Texture* GameObjectLoader::foot;
SDL_Texture* GameObjectLoader::body;
SDL_Texture* GameObjectLoader::head;
SDL_Texture* GameObjectLoader::weapon1;
Mix_Chunk*   GameObjectLoader::gJump;

void GameObjectLoader::setTextures() {
    forTotemBlock = GameObjectLoader::load_tex("Assets/BlankTotemBlock.png");
    forTile = GameObjectLoader::load_tex("Assets/Ww2SpelGround1.png");
    buttonUp = GameObjectLoader::load_tex("Assets/ButtonUp.png");
    buttonDown = GameObjectLoader::load_tex("Assets/ButtonDown.png");
    door = GameObjectLoader::load_tex("Assets/Door.png");
    spike = GameObjectLoader::load_tex("Assets/Spike.png");
    lava = GameObjectLoader::load_tex("Assets/Lava.png");
    particle = GameObjectLoader::load_tex("Assets/Particle1.png");
    outline = GameObjectLoader::load_tex("Assets/Particle2.png");
    
    foot = GameObjectLoader::load_tex("Assets/soldier_foot.png");
    body = GameObjectLoader::load_tex("Assets/soldier_body.png");
    head = GameObjectLoader::load_tex("Assets/soldier_head.png");
    
    weapon1 = GameObjectLoader::load_tex("Assets/weapon1.png");
    
    gJump = Mix_LoadWAV( "Assets/Jump.wav" );
}
