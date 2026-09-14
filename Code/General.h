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
extern float money;

//player
extern actor player;
void player_update();
void player_draw();
//bullets
extern vector<actor> bullets;
extern float b_cooldown;         
extern float b_size;
extern float b_dmg;
extern float b_speed;  


//enemies
class enemie : public actor {
public:
    int id;
    int money;
    float hit_anim = 0.0f;
    float die_anim = 0.0f;
    /// @brief 
    /// @param dmg Damage received
    /// @param v_index Victim index
    /// @param a_index Attacker index
    void damage(float dmg, int v_index, int a_index);
    void die(int index);
    void animate();
    enemie();
    enemie( Vector2 POS, Vector2 VEL,int HP, int MONEY, float SCALE,std::string TEXTURE_PATH,Color MODULATE);
};
extern float diffuclty;
extern vector<enemie> enemies;
void enemies_update();
void enemies_draw();
void spawn_enemie(float diffuclty);

#endif