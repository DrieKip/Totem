//
//  InGameButton.hpp
//  Totem
//
//  Created by Rens Weerman on 2/18/23.
//

#ifndef InGameButton_hpp
#define InGameButton_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <vector>
#include "Door.hpp"

class InGameButton : public GameObject {
public:
    InGameButton(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id);
    bool isPressed;
    static std::vector<Door*> doors;
    std::string door_id;
    void buttonDown();
    void buttonUp();
    void update(double deltaTime);
    void onCollision(GameObject* otherObj);
    
};


#endif /* InGameButton_hpp */
