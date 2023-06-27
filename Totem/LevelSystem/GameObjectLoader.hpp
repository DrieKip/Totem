//
//  GameObjectLoader.hpp
//  Totem
//
//  Created by Rens Weerman on 1/1/23.
//

#ifndef GameObjectLoader_hpp
#define GameObjectLoader_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <string>
#include <SDL2_mixer/SDL_mixer.h>

class GameObjectLoader {
public:
    static SDL_Texture* load_tex(std::string filename);
    static SDL_Texture* forTotemBlock;
    static SDL_Texture* forTile;
    static SDL_Texture* buttonUp;
    static SDL_Texture* buttonDown;
    static SDL_Texture* door;
    static SDL_Texture* spike;
    static SDL_Texture* lava;
    static SDL_Texture* particle;
    static SDL_Texture* outline;
    static SDL_Texture* head;
    static SDL_Texture* foot;
    static SDL_Texture* body;
    static SDL_Texture* weapon1;
    static Mix_Chunk* gJump;
    static SDL_Renderer* some_renderer;
    static void setTextures();
private:
    
};
#endif /* GameObjectLoader_hpp */
