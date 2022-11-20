#include "playerInfo.h"

// All players' information is saved in a structure
struct playerInfo
{
	int balance;
	int points;
	vector<int> cards;
	
}playerOne, playerTwo;

// Visualises player one's information
void showPlayerOneInfo()
{
	DrawText("Player I:", 10, 10, 25, WHITE);
	DrawText("Balance: 1000", 10, 40, 25, WHITE);
	DrawText("Points: 0", 10, 70, 25, WHITE);
}

// Visualises player two's information
void showPlayerTwoInfo()
{
	DrawText("Player II:", 1270, 10, 25, WHITE);
	DrawText("Balance: 1000", 1270, 40, 25, WHITE);
	DrawText("Points: 0", 1270, 70, 25, WHITE);
}

