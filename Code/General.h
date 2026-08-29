#ifndef GENERAL_H 
#define GENERAL_H


#include "raylib.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//system
extern int target_fps;



//actor
class actor{
    public:
        int rotation;
        Vector2 pos;
        Vector2 vel;
        std::string path;

        void move();
        void draw();
        actor();
        actor( Vector2 POS, Vector2 VEL,int ROTATION, std::string TEXTURE_PATH);
};

//player
extern actor player;
void player_update();
void player_draw();

//enemies
extern float diffuclty;
extern vector<actor> enemies;
void enemies_update();
void enemies_draw();
void spawn_enemie(float diffuclty);

#endif