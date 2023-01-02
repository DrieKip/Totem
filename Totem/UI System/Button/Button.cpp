//
//  Button.cpp
//  Totem
//
//  Created by Stan Weerman on 1/1/23.
//

#include "Button.hpp"
#include <iostream>

using namespace std;

Button::Button(vector2d* p, vector2d* s, SDL_Texture* t) :
    UIObject(p, s, t)
{
    
}

Button::~Button(){
    
}

void Button::draw(){
    UIObject::draw();
}

void Button::update(double deltaTime){
    UIObject::update(deltaTime);
}

 void Button::handleEvent(SDL_Event* e){
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
        cout << "Ha" << endl;
        int x, y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;

                //Mouse is left of the button
                if( x < position->x )
                {
                    inside = false;
                }
                //Mouse is right of the button
                else if( x > position->x + size->x )
                {
                    inside = false;
                }
                //Mouse above the button
                else if( y < position->y )
                {
                    inside = false;
                }
                //Mouse below the button
                else if( y > position->y + size->y )
                {
                    inside = false;
                }
        if(!inside){
                    //mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
                }
                //Mouse is inside button
        else {
                    //Set mouse over sprite
            switch( e->type ){
                        case SDL_MOUSEMOTION:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    cout << "MOUSEMOTION" << endl;
                        break;
                    
                        case SDL_MOUSEBUTTONDOWN:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                    cout << "MOUSEButtonDown" << endl;
                        break;
                        
                        case SDL_MOUSEBUTTONUP:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                    cout << "MOUSEButtonUp" << endl;
                        break;
                    }
                }
    }
}
