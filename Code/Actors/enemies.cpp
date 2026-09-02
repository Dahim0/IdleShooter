#include "Code/General.h"




vector<enemie> enemies;

float timer = 3* target_fps;
float time_left = timer;

float diffuclty = 1.0f;
float speed = 0.001f;


enemie::enemie( Vector2 POS, Vector2 VEL,int HP, int MONEY, float SCALE,std::string TEXTURE_PATH,Color MODULATE){
    scale = SCALE;
    pos = POS;
    vel = VEL;
    path = TEXTURE_PATH;
    hp = HP;
    money = MONEY;
    modulate = MODULATE;
}


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


    enemies.push_back(enemie(starting_pos,{0,0},/*hp*/1,/*money*/0,/*scale*/1.0f,"Assets/enemies.png",WHITE));
}


void enemies_update(){
    if (time_left > 0.0f){
        time_left -= 1;
    }
    else if (time_left <= 0 ){
        spawn_enemie(diffuclty);
        time_left = timer;
    }
    for (enemie& i: enemies) {
        i.pos.x = lerp(i.pos.x,player.pos.x,speed);
        i.pos.y = lerp(i.pos.y,player.pos.y,speed);
    }

}


void enemies_draw(){
    for (actor i: enemies) {
      	i.draw();
        
    }
}
