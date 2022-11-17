#include "menu.h"

void DrawText(const char* text, int posX, int posY, int fontSize, Color color);
void Menu()
{
	DrawText("Hello, you have to use your mouse ", 500, 200, 30, RED);
	DrawText("to navigate trough the menu", 540, 250, 30, RED);
}
void displayMenu(Texture2D menu)
{
	DrawTextureEx(menu, { 0, 0 }, 0, 1, WHITE);
}