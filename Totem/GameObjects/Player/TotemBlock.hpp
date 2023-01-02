//
//  TotemBlock.hpp
//  Totem
//
//  Created by Rens Weerman on 12/31/22.
//

#ifndef TotemBlock_hpp
#define TotemBlock_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Player.hpp"
#include "vars.hpp"

class Player;
class TotemBlock : public GameObject {
  public:
    TotemBlock(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, int num, Player* play);
    ~TotemBlock();
    void draw();
    void update(double deltaTime);
    void onCollision(GameObject* otherObj);
    Player* player;
    vector2d* velocity;
    int blockInt;
  private:
    bool grounded;
};
#endif /* TotemBlock_hpp */
