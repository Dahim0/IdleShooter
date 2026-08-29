#include "Code/General.h"




vector<actor> enemies;

float timer = 5* target_fps;
float time_left = timer;

float diffuclty = 1.0f;


void spawn_enemie(float diffuclty){
    enemies.push_back(actor());
}


void enemies_update(){
    if (time_left > 0.0f){
        time_left -= 1;
    }
    else if (time_left <= 0 ){
        spawn_enemie(diffuclty);
        time_left = timer;
    }
   

}


void enemies_draw(){

}
