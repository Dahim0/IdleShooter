#include "raylib.h"
#include "General.h"
#include <cmath>
using namespace std;



int main() {

    InitWindow(800, 500, "IdleShooter"); 
    SetTargetFPS(60);


    
    while (!WindowShouldClose()) {
        //updates
        player_update();

        BeginDrawing();

        ClearBackground(BLACK);
        player_draw();

        EndDrawing();

    }



    CloseWindow();
    return 0;
}
