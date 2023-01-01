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
#include <vector>
#include "TotemBlock.hpp"

class TotemBlock;
class Player : public GameObject {
  public:
    Player(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol);
    ~Player();
    void draw();
    void update(double deltaTime);
    void onCollision(GameObject* otherObj);
    vector2d* velocity;
    std::vector<TotemBlock*> blocks;
    int current_block;
    void swapBlockUp();
  private:
    bool grounded;
};

#endif /* Player_hpp */
