//
//  Button.cpp
//  Totem
//
//  Created by Stan Weerman on 1/1/23.
//

#include "Button.hpp"
#include <iostream>
#include "Input.hpp"

using namespace std;

Button::Button(vector2d* p, vector2d* s, SDL_Texture* t, SDL_Texture* t2, SDL_Texture* t3) :
    UIObject(p, s, t)
{
    tex = t;
    hoverTex = t2;
    pushTex = t3;
}

Button::~Button(){
    
}

void Button::draw(){
    UIObject::draw();
}

void Button::update(double deltaTime){
    UIObject::update(deltaTime);
    handleEvent();
}

 void Button::handleEvent(){
     int x, y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;

                //Mouse is left of the button
                if(x < position->x)
                {
                    inside = false;
                }
                //Mouse is right of the button
                else if(x > position->x + 4*(size->x))
                {
                    inside = false;
                }
                //Mouse above the button
                else if(y < position->y)
                {
                    inside = false;
                }
                //Mouse below the button
                else if( y > position->y + 4*(size->y))
                {
                    inside = false;
                }
        if(!inside){
            //cout << x << "  " << y << endl;
            //mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
            texture = tex;
                }
                //Mouse is inside button
        else {
            //Set mouse over sprite
            if (Input::forButton.type != 0){
                //cout << (Input::forButton).type << endl;
                switch((Input::forButton).type){
                    case SDL_MOUSEMOTION:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                        //cout << "MOUSEMOTION" << endl;
                        texture = hoverTex;
                        break;
                        
                    case SDL_MOUSEBUTTONDOWN:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                        cout << "MOUSEButtonDown" << endl;
                        texture = pushTex;
                        break;
                        
                    case SDL_MOUSEBUTTONUP:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                        cout << "MOUSEButtonUp" << endl;
                        texture = hoverTex;;
                        break;
                }
            }
        }
     Input::forButton.type = 0;
    }
