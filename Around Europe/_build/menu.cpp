#include "menu.h"

// Makes the menu buttons' collision
Vector2 chooseOption(Vector2 mousePosition)
{
    Rectangle buttonCollision = { 0, 0, 0, 0 };
    Vector2 buttonPosition = { -1000, -1000 };

    float coordinatesY[2] = { 400, 500 };

    for (int i = 0; i < 2; i++)
    {
        buttonCollision = {620, coordinatesY[i], 300, 90};

        //  Checks if the mouse position is on one of the buttons
        if (CheckCollisionPointRec(mousePosition, buttonCollision))
        {
            // Checks if it's clicked
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

// Starts game when "Play" it's clicked 
bool buttonPlayClicked(Vector2 buttonPosition, Vector2 mousePosition)
{
    Rectangle buttonPlay = { 620, 400, 300, 90 };

    if (CheckCollisionPointRec(mousePosition, buttonPlay))
    {
        return checkMouseButton();
    }
}

// Closes game when "Quit" it's clicked
bool buttonQuitClicked(Vector2 buttonPosition, Vector2 mousePosition, Rectangle buttonQuit)
{
    if (CheckCollisionPointRec(mousePosition, buttonQuit))
    {
        return checkMouseButton();
    }
}

// Displays button status
void buttonStatus(Texture2D buttons, Rectangle buttonFrames, Vector2 buttonPosition)
{
    // If the player has clicked one of the buttons
    if (checkMouseButton() == 1)
    {
        buttonFrames = { 2 * (float)(buttons.width / 3), 0, (float)(buttons.width / 3), (float)(buttons.height) };
        DrawTextureRec(buttons, buttonFrames, buttonPosition, WHITE);
    }
    // If the mouse cursor is on top of a button (hover)
    else if (buttonPosition.x != 0 && buttonPosition.y != 0)
    {
        buttonFrames = { 1 * (float)(buttons.width / 3), 0, (float)(buttons.width / 3), (float)(buttons.height) };
        DrawTextureRec(buttons, buttonFrames, buttonPosition, WHITE);
    }
}

// Visualise game menu buttons
void displayButtons(Texture2D buttons)
{
    Rectangle buttonFrame = { 0, 0, (float)(buttons.width / 3), (float)buttons.height };

    DrawTextureRec(buttons, buttonFrame, {620, 400}, WHITE);
    DrawTextureRec(buttons, buttonFrame, {620, 500}, WHITE);
}

// Visualise logo in game menu
void displayLogo(Texture2D logo)
{
    DrawText("Created by Team Hydra", 1100, 890, 25, DARKGRAY);
    DrawTextureEx(logo, {1080, 700}, 0, 0.4, WHITE);
}

// Visualise text in game menu
void displayMenuText()
{
    // Visualise basic instructions in game menu
	DrawText("Hello, you have to use your mouse ", 500, 200, 30, DARKGRAY);
	DrawText("to navigate trough the menu", 540, 250, 30, DARKGRAY);
    
    // Visualise button text in game menu
    DrawText("Play", 725, 425, 40, DARKGRAY);
    DrawText("Quit", 725, 525, 40, DARKGRAY);
}

// Visualise menu 
void displayMenu(Texture2D menu, Texture2D buttons, Texture2D logo)
{
    // Visualise menu background
	DrawTextureEx(menu, { 0, 0 }, 0, 1, WHITE);
    
    // Visualise buttons and logo
    displayButtons(buttons);
    displayLogo(logo);
}

// Main game function
void startGame()
{
    // Initialize Window
    InitWindow(1500, 945, "Around Europe");

    // Load all textures needed
    Texture2D map = LoadTexture("../resources/map.png");
    Texture2D cards = LoadTexture("../resources/cards.png");
    Texture2D flag = LoadTexture("../resources/flags.png");
    Texture2D menu = LoadTexture("../resources/menu.png");
    Texture2D buttons = LoadTexture("../resources/buttons.png");
    Texture2D logo = LoadTexture("../resources/logo.png");

    Vector2 mousePosition = { -100, -100 };
    Vector2 flagPosition = { -100, -100 };
    Vector2 menuButtonPosition = { 0, 0 };
 
    Rectangle deck = { 0, 0, (float)(cards.width / 6), (float)cards.height };
    Rectangle playerFlag = { 0, 0, (float)(flag.width / 2), (float)flag.height };
    Rectangle buttonFrames = { 0, 0, (float)(buttons.width / 3), (float)buttons.height};
    Rectangle buttonQuitCollision = { 620, 500, 300, 90 };

    // Checks if the players has clicked "Play"
    bool isPlaying = 0;

    while (!WindowShouldClose())
    {
        // Tracks mouse cursor position
        mousePosition = GetMousePosition();

        // Tracks what button the player has clicked
        flagPosition = chooseCountry(mousePosition);
        menuButtonPosition = chooseOption(mousePosition);

        BeginDrawing();
        
        // Displays menu 
        if (buttonPlayClicked(menuButtonPosition, mousePosition) == 0 && isPlaying == 0)
        {
            displayMenu(menu, buttons, logo);
            buttonStatus(buttons, buttonFrames, menuButtonPosition);
            displayMenuText();
        }
        // Displays game
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

            // Hides "Quit" button's collision
            buttonQuitCollision = { -100, -100, 0, 0 };
        }

        // Closes game from "Quit" button
        if (buttonQuitClicked(menuButtonPosition, mousePosition, buttonQuitCollision) == 1)
        {
            CloseWindow();
        }
        EndDrawing();
    }

    // Unloads textures
    UnloadTexture(menu);
    UnloadTexture(map);
    UnloadTexture(cards);
    UnloadTexture(flag);
    UnloadTexture(buttons);
    UnloadTexture(logo);

    CloseWindow();
}