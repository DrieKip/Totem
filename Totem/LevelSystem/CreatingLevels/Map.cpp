//
//  Map.cpp
//  Totem
//
//  Created by Rens Weerman on 1/1/23.
//

#include "Map.hpp"
#include <fstream>
#include <iostream>
#include "GameObject.hpp"
#include <string>
#include <stdio.h>
#include "TileObject.hpp"
#include "json.hpp"
#include "vars.hpp"
#include "GameObjectLoader.hpp"
#include "SceneManager.hpp"

using json = nlohmann::json;
using namespace std;
Map::Map(std::string file) {
    filename = file;
}
Map::~Map() {
    
}
void Map::createMap() {
    ifstream f;
    f.open(filename.c_str());
    json data = json::parse(f);
    auto tileData = data["levels"][0]["layerInstances"][0]["autoLayerTiles"];
    for (int i = 0; i < tileData.size(); i++) {
        //somevec
        if (tileData.at(i)["t"] == 36 || tileData.at(i)["t"] == 37) {
            TileObject* someObj = new TileObject(new vector2d(tileData.at(i)["px"][0], tileData.at(i)["px"][1]),
                                     new vector2d(8,8),
                                     GameObjectLoader::forTile,
                                     false,
                                     vector2d{tileData.at(i)["src"][0], tileData.at(i)["src"][1]});
            SceneManager::objList.push_back(someObj);
        } else {
            TileObject* someObj = new TileObject(new vector2d(tileData.at(i)["px"][0], tileData.at(i)["px"][1]),
                                                 new vector2d(8,8),
                                                 GameObjectLoader::forTile,
                                                 true,
                                                 vector2d{tileData.at(i)["src"][0], tileData.at(i)["src"][1]});
            SceneManager::objList.push_back(someObj);
        }
    }
}
