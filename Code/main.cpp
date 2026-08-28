#include "raylib.h"

int main() {

    InitWindow(500, 500, "Game"); //Setting up the game windows size and name
    SetTargetFPS(60); //Max fps

    while (!WindowShouldClose()) { //Main game loop
        BeginDrawing();

        ClearBackground(WHITE);
        DrawText("Hello World!",10,10,50,BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
