#include "General.h"

using namespace std;

int target_fps = 60;
float money = 0.0f;

int main() {
        // Initialize audio device

    InitWindow(800, 500, "IdleShooter"); 
    SetTargetFPS(target_fps);

    InitAudioDevice();  
    
    while (!WindowShouldClose()) {


        BeginDrawing();

        ClearBackground(BLACK);
        player_draw();
        enemies_draw();
        DrawText(TextFormat("%.0f$", money), 20, 20, 20, YELLOW);
        EndDrawing();

        player_update();
        enemies_update();

    }


    CloseAudioDevice();
    CloseWindow();
    return 0;
}
