#include "main.h"

int main()
{
    InitWindow(1500, 945, "Around Europe");

    Texture2D map = LoadTexture("../resources/map.png");
    Texture2D cards = LoadTexture("../resources/cards.png");
    
    Rectangle deck = { 0, 0, (float)(cards.width / 6), (float)cards.height};

    while (!WindowShouldClose())
    {
        BeginDrawing();

        displayMap(map);
        DrawTextureRec(cards, deck, {620, 760}, WHITE);

        
        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(cards);

    CloseWindow();

    return 0;
}