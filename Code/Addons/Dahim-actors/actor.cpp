#include "actor.h"
#include <iostream>


void actor::move(){
    pos.x += vel.x;
    pos.y += vel.y;
};

void actor::draw(){

    Texture2D texture = LoadTexture(path.c_str());
    Rectangle textureRect = {0.0f,0.0f,(float)texture.width,(float)texture.height};
    Vector2 TextureOrigin = {(float)texture.width/2.0f,(float)texture.height/2.0f};

    DrawTexturePro(
        texture,textureRect,
        (Rectangle) {pos.x,pos.y,(float)textureRect.width*scale,(float)textureRect.height*scale},
        TextureOrigin,rotation,WHITE
    );
    width = (float)textureRect.width;
    height = (float)textureRect.height;
};


actor::actor(){
    rotation = 0;
    hp = 1;
    scale = 1.0f;
    pos = {0,0};
    vel = {0,0};
    path = "Assets/enemies.png";
}

actor::actor( Vector2 POS , Vector2 VEL ,int ROTATION,int HP , std::string TEXTURE_PATH, float SCALE){
    rotation = ROTATION;
    pos = POS;
    vel = VEL;
    path = TEXTURE_PATH;
    hp = HP;
    scale = SCALE;
};
