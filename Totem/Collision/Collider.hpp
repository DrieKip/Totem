//
//  Collider.hpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#ifndef Collider_hpp
#define Collider_hpp

#include <SDL2/SDL.h>
#include "vars.hpp"
#include "GameObject.hpp"
#include <stdio.h>
#include <string>
class GameObject;

class Collider {
  public:
    Collider();
    Collider(vector2d* p, vector2d* s, GameObject* o);
    Collider(vector2d* p, vector2d* s, GameObject* o, std::string i);
    ~Collider();
    SDL_Rect bounds;
    GameObject* obj;
    std::string id;
    void setPosition(vector2d* p);
    bool operator==(const Collider& c) const;
  private:
    
};

#endif /* Collider_hpp */
