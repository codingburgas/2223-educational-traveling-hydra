#include "menu.h"

Vector2 chooseOption(Vector2 mousePosition)
{
    Rectangle buttonCollision = { 0, 0, 0, 0 };
    Vector2 buttonPosition = { -1000, -1000 };

    float coordinatesY[2] = { 400, 500 };

    for (int i = 0; i < 2; i++)
    {
        buttonCollision = {620, coordinatesY[i], 300, 90};

        if (CheckCollisionPointRec(mousePosition, buttonCollision))
        {
            if (checkMouseButton() == 1)
            {
                return buttonPosition = { 620, coordinatesY[i]};
            }
            else
            {
                return buttonPosition = { 620 , coordinatesY[i]};
            }
        }
    }
}

bool buttonPlayClicked(Vector2 buttonPosition, Vector2 mousePosition)
{
    Rectangle buttonPlay = { 620, 400, 300, 90 };

    if (CheckCollisionPointRec(mousePosition, buttonPlay))
    {
        return checkMouseButton();
    }
}

bool buttonQuitClicked(Vector2 buttonPosition, Vector2 mousePosition, Rectangle buttonQuit)
{
    if (CheckCollisionPointRec(mousePosition, buttonQuit))
    {
        return checkMouseButton();
    }
}


void buttonStatus(Texture2D buttons, Rectangle buttonFrames, Vector2 buttonPosition)
{
    if (checkMouseButton() == 1)
    {
        buttonFrames = { 2 * (float)(buttons.width / 3), 0, (float)(buttons.width / 3), (float)(buttons.height) };
        DrawTextureRec(buttons, buttonFrames, buttonPosition, WHITE);
    }
    else if (buttonPosition.x != 0 && buttonPosition.y != 0)
    {
        buttonFrames = { 1 * (float)(buttons.width / 3), 0, (float)(buttons.width / 3), (float)(buttons.height) };
        DrawTextureRec(buttons, buttonFrames, buttonPosition, WHITE);
    }
}

void displayButtons(Texture2D buttons)
{
    Rectangle buttonFrame = { 0, 0, (float)(buttons.width / 3), (float)buttons.height };

    DrawTextureRec(buttons, buttonFrame, {620, 400}, WHITE);
    DrawTextureRec(buttons, buttonFrame, {620, 500}, WHITE);
}

void displayMenuText()
{
	DrawText("Hello, you have to use your mouse ", 500, 200, 30, DARKGRAY);
	DrawText("to navigate trough the menu", 540, 250, 30, DARKGRAY);
    
    DrawText("Play", 725, 425, 40, DARKGRAY);
    DrawText("Quit", 725, 525, 40, DARKGRAY);
}
void displayMenu(Texture2D menu, Texture2D buttons)
{
	DrawTextureEx(menu, { 0, 0 }, 0, 1, WHITE);
    displayButtons(buttons);
}

void game()
{
    InitWindow(1500, 945, "Around Europe");

    Texture2D map = LoadTexture("../resources/map.png");
    Texture2D cards = LoadTexture("../resources/cards.png");
    Texture2D flag = LoadTexture("../resources/flags.png");
    Texture2D menu = LoadTexture("../resources/menu.png");
    Texture2D buttons = LoadTexture("../resources/buttons.png");

    Vector2 mousePosition = { -100, -100 };
    Vector2 flagPosition = { -100, -100 };
    Vector2 buttonPosition = { 0, 0 };

    Rectangle deck = { 0, 0, (float)(cards.width / 6), (float)cards.height };
    Rectangle playerFlag = { 0, 0, (float)(flag.width / 2), (float)flag.height };
    Rectangle buttonFrames = { 0, 0, (float)(buttons.width / 3), (float)buttons.height};
    Rectangle buttonQuit = { 620, 500, 300, 90 };

    bool isPlaying = 0;

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();

        flagPosition = chooseCountry(mousePosition);
        buttonPosition = chooseOption(mousePosition);

        BeginDrawing();

        if (buttonPlayClicked(buttonPosition, mousePosition) == 0 && isPlaying == 0)
        {
            displayMenu(menu, buttons);
            buttonStatus(buttons, buttonFrames, buttonPosition);
            displayMenuText();

        }
        else
        {
            displayMap(map);

            DrawTextureRec(cards, deck, { 620, 760 }, WHITE);
            displayFlagOrCountryInfo(flag, playerFlag, flagPosition);

            showCardsPlayerOne(cards, deck);
            showCardsPlayerTwo(cards, deck);

            showPlayerOneInfo();
            showPlayerTwoInfo();

            isPlaying = 1;
            buttonQuit = { -100, -100, 0, 0 };
        }

        if (buttonQuitClicked(buttonPosition, mousePosition, buttonQuit) == 1)
        {
            CloseWindow();
        }
        EndDrawing();
    }

    UnloadTexture(menu);
    UnloadTexture(map);
    UnloadTexture(cards);
    UnloadTexture(flag);
    UnloadTexture(buttons);

    CloseWindow();
}