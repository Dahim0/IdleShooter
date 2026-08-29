#include "General.h"

using namespace std;

int target_fps = 60;


int main() {

    InitWindow(800, 500, "IdleShooter"); 
    SetTargetFPS(target_fps);


    
    while (!WindowShouldClose()) {
        player_update();
        enemies_update();

        BeginDrawing();

        ClearBackground(BLACK);
        player_draw();
        enemies_draw();
        DrawText(to_string(randi(100,101)).c_str(),0,0,10,WHITE);

        EndDrawing();

    }



    CloseWindow();
    return 0;
}
