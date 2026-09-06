#include "Code/General.h"



vector<actor> bullets;            
float b_cooldown = 1.0f * target_fps;         
float b_size = 1.0f;
float b_dmg = 1.0f;
float b_speed = 4.0f;  

float b_time_left = b_cooldown;


void shoot(){
    Vector2 target_pos;
    target_pos.x = normalized(GetMousePosition()).x * 1.5f + player.pos.x;
    target_pos.y = normalized(GetMousePosition()).y  * 1.5f + player.pos.y;
    Vector2 target_vel;
    target_vel = normalized(sub_v2(GetMousePosition(),player.pos));

    bullets.push_back(actor(target_pos,mult_v2(target_vel,b_speed),0,1,"Assets/bullet.png"));
}


actor player({400,250},{0,0},0,1,"Assets/player.png");


void player_update(){
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].move();
        bullets[i].scale = b_size;


        if (distance_v2(bullets[i].pos,player.pos) > 1000 ){
            bullets.erase(bullets.begin() + i); // weird but work
           
        }
        for (int u = 0; u < enemies.size(); u++) { // enemies
            if ( distance_v2(bullets[i].pos,enemies[u].pos) < (bullets[i].width + enemies[u].width)/2){
                enemies[u].damage(b_dmg,u,i);
                bullets.erase(bullets.begin() + i);
                
            }
        }

    }

    //look at the mosue
    player.rotation = atan2(
    -(GetMousePosition().x -player.pos.x),
    GetMousePosition().y -player.pos.y)
    *(180/M_PI);

    if (b_time_left > 0.0f){
        b_time_left -= 1;
    }
    else if (b_time_left <= 0 ){
        b_time_left = b_cooldown;
        shoot();
    }
    


}



void player_draw(){
    for (actor& i: bullets) {
        i.draw();
    }
    player.draw();
}