//
//  Collisions.hpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#ifndef Collisions_hpp
#define Collisions_hpp

#include <stdio.h>
#include "Collider.hpp"
#include <list>
class Collider;

class Collisions {
    public:
        static std::list<Collider*> colliders;
        static void AddCollider(Collider* col);
        static void removeCollider(Collider* col);
        static void clearColliders(Collider* col);
        static void CheckCollision(Collider* col);
};

#endif /* Collisions_hpp */
