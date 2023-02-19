//
//  Lava.hpp
//  Totem
//
//  Created by Rens Weerman on 2/19/23.
//

#ifndef Lava_hpp
#define Lava_hpp

#include <stdio.h>
#include "GameObject.hpp"

#endif /* Lava_hpp */

class Lava : public GameObject {
public:
    Lava(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id);
    void onCollision(GameObject* otherObj);
};
