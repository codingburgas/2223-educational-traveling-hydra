#include "raylib.h"

int main()
{
    InitWindow(1500, 945, "Around Europe");

    Texture2D map = LoadTexture("../resources/map.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        DrawTextureEx(map, { 0, 0 }, 0, 1, WHITE);
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}