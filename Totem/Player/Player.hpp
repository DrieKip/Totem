//
//  Player.hpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Player : public GameObject {
  public:
    Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol);
    ~Player();
    void draw();
    void update(double deltaTime);
    void onCollision(GameObject* otherObj);
  private:
};

#endif /* Player_hpp */
