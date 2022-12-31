//
//  Collisions.cpp
//  Totem
//
//  Created by Rens Weerman on 12/30/22.
//

#include "Collisions.hpp"
#include <list>
using namespace std;

list<Collider> Collisions::colliders;

void Collisions::AddCollider(Collider col) {
    //std::list<Collider> Collisions::colliders;
    colliders.push_back(col);
}
void Collisions::removeCollider(Collider col) {
    colliders.remove(col);
}
void Collisions::clearColliders(Collider col) {
    colliders.clear();
}
void Collisions::CheckCollision(Collider col) {
    for (Collider othercol : colliders) {
        if (!(col == othercol) && SDL_HasIntersection(&(col.bounds), &(othercol.bounds))) {
            col.obj->onCollision(othercol.obj);
            othercol.obj->onCollision(col.obj);
        }
    }
}

