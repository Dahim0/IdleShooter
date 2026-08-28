#include "raylib.h"
#include "actor.h"
#include <iostream>
using namespace std;



int main() {

    InitWindow(800, 500, "Game"); //Setting up the game windows size and name
    SetTargetFPS(60); //Max fps

    actor player({400,250},{0,0},90,"Assets/player.png");

    
    while (!WindowShouldClose()) { //Main game loop
        player.move();


        BeginDrawing();

        ClearBackground(BLACK);

        player.draw();

        EndDrawing();
    }



    CloseWindow();
    return 0;
}
