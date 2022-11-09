#include "map.h"

void displayCapitalCities()
{
	int coordinatesX[44] = {435, 695, 775, 850, 850, 850, 870, 900, 1000, 710, 485, 550, 570, 460, 365, 710, 640, 610, 617, 725, 825, 725, 760, 778, 795, 740, 762, 795, 810, 818, 820, 910, 940, 947, 625, 845, 835, 870, 885};
	int coordinatesY[44] = {90, 270, 285, 255, 280, 325, 365, 375, 305, 365, 375, 430, 495, 640, 655, 645, 540, 455, 423, 425, 425, 475, 515, 515, 530, 558, 560, 600, 636, 656, 580, 585, 523, 455, 475, 640, 625, 625, 718};

	for (int i = 0; i < 39; i++)
	{
		DrawCircleLines(coordinatesX[i], coordinatesY[i], 4, BLACK);
		DrawCircle(coordinatesX[i], coordinatesY[i], 3, WHITE);
	}
}

void displayMap(Texture2D map)
{
	DrawTextureEx(map, { 0, 0 }, 0, 1, WHITE);
	displayCapitalCities();
}