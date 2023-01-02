//
//  SceneManager.hpp
//  Totem
//
//  Created by Rens Weerman on 12/31/22.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include <list>
#include "GameObject.hpp"
#include "UIObject.hpp"

class GameObject;

class SceneManager {
public:
    static std::list<GameObject*> objList;
    static std::list<UIObject*> uiList;
};
#endif /* SceneManager_hpp */
