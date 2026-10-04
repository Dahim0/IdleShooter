#ifndef GENERAL_H 
#define GENERAL_H


#include "raylib.h"
#include <iostream>
#include <vector>
#include <cmath>
//personal addons
#include "Code/Addons/Dahim-qol/DahimQol.hpp"
#include "Code/Addons/Dahim-actors/actor.h"

using namespace std;

//system
extern int target_fps;
extern float money;

//player
extern actor player;
void player_update();
void player_draw();
//bullets
extern vector<actor> Bullets;
extern float SpawnBulletCooldown;//seconds
extern float BulletSize;
extern float BulletDmg;
extern float BulletSpd;


//enemies
class enemie : public actor {
public:
    int id;
    int money_drop;
    Timer hit_anim;
    Timer die_anim;
    Color diff_color; // diffuculty color
    Color target_color = {255,255,255,255};
    /// @brief 
    /// @param dmg Damage received
    /// @param v_index Victim index
    /// @param a_index Attacker index
    void damage(float dmg, int v_index, int a_index);
    void animate();
    enemie();
};
extern int diffuclty;
extern vector<enemie> enemies;
void enemies_update();
void enemies_draw();
void spawn_enemie(float diffuclty);
void clean_up();

#endif // GENERAL_H