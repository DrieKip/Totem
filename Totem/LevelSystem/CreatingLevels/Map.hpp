//
//  Map.hpp
//  Totem
//
//  Created by Rens Weerman on 1/1/23.
//

#ifndef Map_hpp
#define Map_hpp
#include "GameObject.hpp"
#include <string>

#include <stdio.h>
class GameObject;
class Map{
public:
    Map(std::string file);
    ~Map();
    void createMap();
    std::string filename;
};
#endif /* Map_hpp */
