#include "Code/General.h"




actor player({400,250},{0,0},0,"Assets/player.png");

void player_update(){
    player.move();

    //look at the mosue
    player.rotation = atan2(
    -(GetMousePosition().x -player.pos.x),
    GetMousePosition().y -player.pos.y)
    *(180/M_PI);
}



void player_draw(){
    player.draw();
}