#include "playerInfo.h"

struct playerInfo {
	int balance;
	int points;
	vector<int> cards;

}player1, player2;

void showPlayerOneInfo(){
	DrawText("Player I:", 10, 10, 25, WHITE);
	DrawText("Balance: ", 10, 40, 25, WHITE);
	DrawText("Points: ", 10, 70, 25, WHITE);
}

void showPlayerTwoInfo() {
	DrawText("Player II:", 1270, 10, 25, WHITE);
	DrawText("Balance: ", 1270, 40, 25, WHITE);
	DrawText("Points: ", 1270, 70, 25, WHITE);
}

