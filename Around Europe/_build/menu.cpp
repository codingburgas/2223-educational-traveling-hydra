#include "menu.h"

void displayMenuText()
{
	DrawText("Hello, you have to use your mouse ", 500, 200, 30, DARKGRAY);
	DrawText("to navigate trough the menu", 540, 250, 30, DARKGRAY);
}
void displayMenu(Texture2D menu)
{
	DrawTextureEx(menu, { 0, 0 }, 0, 1, WHITE);
	displayMenuText();
}