#include "raylib.h"
#include "actor.h"
#include <iostream>
#include <cmath>
using namespace std;



int main() {

    InitWindow(800, 500, "IdleShooter"); 
    SetTargetFPS(60);

    actor player({400,250},{0,0},90,"Assets/player.png");

    
    while (!WindowShouldClose()) {
        player.move();


        BeginDrawing();

        ClearBackground(BLACK);
        player.rotation = atan2(
        -(GetMousePosition().x -player.pos.x),
        GetMousePosition().y -player.pos.y)
        *(180/M_PI);


        player.draw();


        EndDrawing();
    }



    CloseWindow();
    return 0;
}
