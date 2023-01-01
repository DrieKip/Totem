//
//  vars.hpp
//  Totem
//
//  Created by Rens Weerman on 12/29/22.
//

#ifndef vars_hpp
#define vars_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

extern SDL_Renderer* gRenderer;

struct vector2d {
  double x;
  double y;
  vector2d(double xx, double yy);
  void operator+=(const vector2d& other);
};
#endif /* vars_hpp */
