#include "General.h"

using namespace std;

int target_fps = 60;
float money = 0.0f;

int main() {

    InitWindow(800, 500, "IdleShooter"); 
    SetTargetFPS(target_fps);


    
    while (!WindowShouldClose()) {


        BeginDrawing();

        ClearBackground(BLACK);
        player_draw();
        enemies_draw();
        DrawText(TextFormat("%.2f$", money), 20, 20, 30, YELLOW);

        EndDrawing();

        player_update();
        enemies_update();

    }



    CloseWindow();
    return 0;
}
