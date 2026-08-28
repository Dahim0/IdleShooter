#ifndef GENERAL_H 
#define GENERAL_H



#include "raylib.h"
#include <iostream>

//actor
class actor{
    public:
        int rotation;
        Vector2 pos;
        Vector2 vel;
        std::string path;

        void move();
        void draw();
        actor( Vector2 POS, Vector2 VEL,int ROTATION, std::string TEXTURE_PATH);
};


//player
extern actor player;
void player_update();
void player_draw();

#endif