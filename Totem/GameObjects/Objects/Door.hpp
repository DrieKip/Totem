//
//  Door.hpp
//  Totem
//
//  Created by Rens Weerman on 2/18/23.
//

#ifndef Door_hpp
#define Door_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <vector>
#include "TotemBlock.hpp"

class Door : public GameObject {
public:
    Door(vector2d* p, vector2d* s, SDL_Texture* texture, bool hasCol, std::string id);
    bool isOpen;
    std::string door_id;
    void openDoor();
    void closeDoor();
    
    
    
};


#endif /* Door_hpp */
