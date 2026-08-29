#ifndef GENERAL_H 
#define GENERAL_H


#include "raylib.h"
#include <iostream>
#include <vector>
#include <cmath>
//personal addons
#include "Code/Addons/Dahim-qol/DahimQol.h"
#include "Code/Addons/Dahim-actors/actor.h"

using namespace std;

//system
extern int target_fps;





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