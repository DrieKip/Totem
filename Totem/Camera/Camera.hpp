//
//  Camera.hpp
//  Totem
//
//  Created by Rens Weerman on 12/31/22.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <SDL2/SDL.h>
#include "vars.hpp"
#include "GameObject.hpp"
#include "Player.hpp"

#include <stdio.h>
class GameObject;

class Camera {
public:
    static vector2d* position;
    static GameObject* player;
    static void setPlayer(GameObject* obj);
    static void setCamera(double deltaTime);
    static void rectToCamera(SDL_Rect &rect);
};
#endif /* Camera_hpp */
