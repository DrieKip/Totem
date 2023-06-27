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
#include "Door.hpp"
#include "Button.hpp"
#include "InGameButton.hpp"
#include "Spike.hpp"
#include "Lava.hpp"

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
    auto tileData = data["levels"][3]["layerInstances"][1]["autoLayerTiles"];
    for (int i = 0; i < tileData.size(); i++) {
        //somevec
        int no =tileData.at(i)["t"];
        std::vector<int> numbers = data["defs"]["tilesets"][0]["enumTags"][1]["tileIds"].get<std::vector<int>>();
        if (std::find(numbers.begin(), numbers.end(), no) != numbers.end()) {
            TileObject* someObj = new TileObject(new vector2d(tileData.at(i)["px"][0], tileData.at(i)["px"][1]),
                                     new vector2d(16,16),
                                     GameObjectLoader::forTile,
                                     false,
                                     vector2d{tileData.at(i)["src"][0], tileData.at(i)["src"][1]});
            SceneManager::objList.push_back(someObj);
        } else {
            TileObject* someObj = new TileObject(new vector2d(tileData.at(i)["px"][0], tileData.at(i)["px"][1]),
                                                 new vector2d(16,16),
                                                 GameObjectLoader::forTile,
                                                 true,
                                                 vector2d{tileData.at(i)["src"][0], tileData.at(i)["src"][1]});
            SceneManager::objList.push_back(someObj);
        }
    }
    /*auto entityData = data["levels"][2]["layerInstances"][0]["entityInstances"];
    for (int i = 0; i < entityData.size(); i++) {
        auto ent = entityData.at(i);
        if (entityData.at(i)["__identifier"] == "Door") {
            GameObject* someObj = new Door(new vector2d(4 * (int)entityData.at(i)["px"][0], 4 * (int)entityData.at(i)["px"][1]),
                                           new vector2d(16,16),
                                           GameObjectLoader::door,
                                           true,
                                           ent["fieldInstances"][0]["__value"]);
            SceneManager::objList.push_back(someObj);
        }
        if (entityData.at(i)["__identifier"] == "Button") {
            GameObject* someObj = new InGameButton(new vector2d(4 * (int)entityData.at(i)["px"][0], 4 * (int)entityData.at(i)["px"][1]),
                                           new vector2d(16,8),
                                           GameObjectLoader::buttonUp,
                                           true,
                                           ent["fieldInstances"][0]["__value"]
                                           );
            SceneManager::objList.push_back(someObj);
        }
        if (entityData.at(i)["__identifier"] == "Spike") {
            GameObject* someObj = new Spike(new vector2d(4 * (int)entityData.at(i)["px"][0], 4 * (int)entityData.at(i)["px"][1]),
                                           new vector2d(5,6),
                                           GameObjectLoader::spike,
                                           true,
                                           "spike");
            SceneManager::objList.push_back(someObj);
        }
        if (entityData.at(i)["__identifier"] == "Lava") {
            GameObject* someObj = new Lava(new vector2d(4 * (int)entityData.at(i)["px"][0], 4 * (int)entityData.at(i)["px"][1]),
                                           new vector2d(ent["width"],ent["height"]),
                                           GameObjectLoader::lava,
                                           true,
                                           "doorA");
            SceneManager::objList.push_back(someObj);
        }
    }*/
        
}
