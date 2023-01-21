//
//  TileObject.hpp
//  Totem
//
//  Created by Rens Weerman on 1/1/23.
//

#ifndef TileObject_hpp
#define TileObject_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <SDL2/SDL.h>
class TileObject : public GameObject {
public:
    TileObject(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, vector2d srcPos);
    ~TileObject();
    void draw();
    void update(double deltaTime);
    void onCollision(GameObject* otherObj);
    SDL_Rect* src;
private:
    
};
#endif /* TileObject_hpp */
