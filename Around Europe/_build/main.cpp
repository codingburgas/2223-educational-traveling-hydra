#include "main.h"

int main()
{
    InitWindow(1500, 945, "Around Europe");

    Texture2D map = LoadTexture("../resources/map.png");
    Texture2D cards = LoadTexture("../resources/cards.png");
    Texture2D flag = LoadTexture("../resources/flags.png");
    
    Vector2 mousePosition = { -100, -100 };
    Vector2 flagPosition;

    Rectangle countryCollisions = {0, 0, 0, 0};
    Rectangle deck = { 0, 0, (float)(cards.width / 6), (float)cards.height};
    Rectangle playerFlag = { 0, 0, (float)(flag.width / 2), (float)flag.height};

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();
        flagPosition = chooseCountry(countryCollisions, mousePosition);

        BeginDrawing();

        displayMap(map);

        DrawTextureRec(cards, deck, {620, 760}, WHITE);
        DrawTextureRec(flag, playerFlag, flagPosition, WHITE);
        showCardsPlayerOne(cards, deck);
        showCardsPlayerTwo(cards, deck);

        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(cards);
    UnloadTexture(flag);

    CloseWindow();

    return 0;
}