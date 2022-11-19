#include "main.h"

int main()
{
    InitWindow(1500, 945, "Around Europe");

    Texture2D map = LoadTexture("../resources/map.png");
    Texture2D cards = LoadTexture("../resources/cards.png");
    Texture2D flag = LoadTexture("../resources/flags.png");
    Texture2D menu = LoadTexture("../resources/menu.png");
    
    Vector2 mousePosition = { -100, -100 };
    Vector2 mousePoint = { 0.0f, 0.0f };
    Vector2 flagPosition = { -1000, -1000 };

    Rectangle countryCollisions = {0, 0, 0, 0};
    Rectangle deck = { 0, 0, (float)(cards.width / 6), (float)cards.height};
    Rectangle playerFlag = { 0, 0, (float)(flag.width / 2), (float)flag.height};
    Rectangle button = { 0, 0, 0, 0 };

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();
        flagPosition = chooseCountry(countryCollisions, mousePosition);
       
        BeginDrawing();

        displayMenu(menu);
        /* !!!DO NOT DELETE
        displayMap(map);

        DrawTextureRec(cards, deck, {620, 760}, WHITE);
        displayFlagOrCountryInfo(flag, playerFlag, flagPosition);
        
        showCardsPlayerOne(cards, deck);
        showCardsPlayerTwo(cards, deck);
        
        showPlayerOneInfo();
        showPlayerTwoInfo();
        */
        EndDrawing();
    }
    UnloadTexture(menu);
    UnloadTexture(map);
    UnloadTexture(cards);
    UnloadTexture(flag);

    CloseWindow();

    return 0;
}