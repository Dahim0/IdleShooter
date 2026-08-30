#include "Code/General.h"




vector<actor> enemies;

float timer = 3* target_fps;
float time_left = timer;

float diffuclty = 1.0f;
float speed = 0.001f;



void spawn_enemie(float diffuclty){
    int starting_direction = randi(1,4);
    Vector2 starting_pos;
    switch(starting_direction) {
    case 1:
        // left
        starting_pos = {-50,(float)randi(0,800)};
        break;
    case 2:
        // up
        starting_pos = {(float)randi(0,400),-50};
        break;
    case 3:
        // right
        starting_pos = {850,(float)randi(0,800)};
        break;
    case 4:
        // down
        starting_pos = {(float)randi(0,400),550};
        break;
    }


    enemies.push_back(actor(starting_pos,{0,0},0,1,"Assets/enemies.png",(float)randi(5,20)/10));
}


void enemies_update(){
    if (time_left > 0.0f){
        time_left -= 1;
    }
    else if (time_left <= 0 ){
        spawn_enemie(diffuclty);
        time_left = timer;
    }
    for (actor& i: enemies) {
        i.pos.x = lerp(i.pos.x,player.pos.x,speed);
        i.pos.y = lerp(i.pos.y,player.pos.y,speed);
    }

}


void enemies_draw(){
    for (actor i: enemies) {
      	i.draw();
        
    }
}
