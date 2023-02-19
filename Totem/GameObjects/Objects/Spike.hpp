//
//  Spike.hpp
//  Totem
//
//  Created by Rens Weerman on 2/19/23.
//

#ifndef Spike_hpp
#define Spike_hpp

#include <stdio.h>
#include "GameObject.hpp"

#endif /* Spike_hpp */
class Spike : public GameObject {
public:
    Spike(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id);
    void onCollision(GameObject* otherObj);
};
