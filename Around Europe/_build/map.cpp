#include "map.h"

bool checkMouseButton()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Vector2 chooseCountry(Vector2 mousePosition)
{
    float coordinatesX[39] = { 435, 695, 775, 850, 850, 850, 870, 900, 1000, 710, 485, 550, 570, 460, 365, 710, 640, 610, 617, 725, 825, 725, 760, 778, 795, 740, 762, 795, 810, 818, 820, 910, 940, 947, 625, 845, 835, 870, 885 };
    float coordinatesY[39] = { 90, 270, 285, 255, 280, 325, 365, 375, 305, 365, 375, 430, 495, 640, 655, 645, 540, 455, 423, 425, 425, 475, 515, 515, 530, 558, 560, 600, 636, 656, 580, 585, 523, 455, 475, 640, 625, 625, 718 };
   
    Rectangle countryCollisions = { 0, 0, 0, 0 };

    Vector2 flagPosition = {-1000, -1000};

    for (int i = 0; i < 39; i++)
    {
        countryCollisions = { coordinatesX[i] - 4, coordinatesY[i] - 4, 8, 8 };

        if (CheckCollisionPointRec(mousePosition, countryCollisions))
        {
            if (checkMouseButton() == 1)
            {
                return flagPosition = { coordinatesX[i] - 6, coordinatesY[i] - 27 };
            }
            else
            {
                return flagPosition = { coordinatesX[i] + 10, coordinatesY[i] - 27 };
            }
        }
 
    }
}

void displayFlagOrCountryInfo(Texture2D flag, Rectangle playerFlag, Vector2 flagPosition)
{
    Rectangle countryInfo = { flagPosition.x, flagPosition.y, 130, 70 };

    if (checkMouseButton() == 1)
    {
        DrawTextureRec(flag, playerFlag, flagPosition, WHITE);
    }
    else if (flagPosition.x != 0 && flagPosition.y != 0)
    {

        DrawRectangleRounded(countryInfo, 0.5, 1, WHITE);
        DrawRectangleRoundedLines(countryInfo, 0.5, 1, 2, BLACK);

        if ((flagPosition.x == 580 && flagPosition.y == 468) || (flagPosition.x == 720 && flagPosition.y == 618) || (flagPosition.x == 735 && flagPosition.y == 398) ||
            (flagPosition.x == 560 && flagPosition.y == 403) || (flagPosition.x == 785 && flagPosition.y == 258) || (flagPosition.x == 705 && flagPosition.y == 243) ||
            (flagPosition.x == 635 && flagPosition.y == 448))
        {
            DrawText("Price: 400$", (int)flagPosition.x + 10, (int)flagPosition.y + 10, 20, DARKGRAY);
            DrawText("Points: 5", (int)flagPosition.x + 10, (int)flagPosition.y + 40, 20, DARKGRAY);
        }
        else if ((flagPosition.x == 770 && flagPosition.y == 488) || (flagPosition.x == 895 && flagPosition.y == 691) || (flagPosition.x == 1010 && flagPosition.y == 278) ||
            (flagPosition.x == 620 && flagPosition.y == 428) || (flagPosition.x == 470 && flagPosition.y == 613) || (flagPosition.x == 627 && flagPosition.y == 396) ||
            (flagPosition.x == 495 && flagPosition.y == 348) || (flagPosition.x == 860 && flagPosition.y == 228))
        {
            DrawText("Price: 300$", (int)flagPosition.x + 10, (int)flagPosition.y + 10, 20, DARKGRAY);
            DrawText("Points: 4", (int)flagPosition.x + 10, (int)flagPosition.y + 40, 20, DARKGRAY);
        }
        else if ((flagPosition.x == 375 && flagPosition.y == 628) || (flagPosition.x == 957 && flagPosition.y == 428) || (flagPosition.x == 788 && flagPosition.y == 488) ||
            (flagPosition.x == 650 && flagPosition.y == 513) || (flagPosition.x == 445 && flagPosition.y == 63) || (flagPosition.x == 720 && flagPosition.y == 338) ||
            (flagPosition.x == 835 && flagPosition.y == 398) || (flagPosition.x == 735 && flagPosition.y == 448))
        {
            DrawText("Price: 250$", (int)flagPosition.x + 10, (int)flagPosition.y + 10, 20, DARKGRAY);
            DrawText("Points: 3", (int)flagPosition.x + 10, (int)flagPosition.y + 40, 20, DARKGRAY);
        }
        else if ((flagPosition.x == 860 && flagPosition.y == 298) || (flagPosition.x == 880 && flagPosition.y == 338) || (flagPosition.x == 860 && flagPosition.y == 253) ||
            (flagPosition.x == 920 && flagPosition.y == 558) || (flagPosition.x == 880 && flagPosition.y == 598) || (flagPosition.x == 805 && flagPosition.y == 503) ||
            (flagPosition.x == 830 && flagPosition.y == 553) || (flagPosition.x == 772 && flagPosition.y == 533))
        {
            DrawText("Price: 200$", (int)flagPosition.x + 10, (int)flagPosition.y + 10, 20, DARKGRAY);
            DrawText("Points: 2", (int)flagPosition.x + 10, (int)flagPosition.y + 40, 20, DARKGRAY);
        }
        else if ((flagPosition.x == 855 && flagPosition.y == 613) || (flagPosition.x == 820 && flagPosition.y == 609) || (flagPosition.x == 845 && flagPosition.y == 598) ||
            (flagPosition.x == 828 && flagPosition.y == 629) || (flagPosition.x == 805 && flagPosition.y == 573) || (flagPosition.x == 950 && flagPosition.y == 496) ||
            (flagPosition.x == 910 && flagPosition.y == 348) || (flagPosition.x == 750 && flagPosition.y == 531))
        {
            DrawText("Price: 150$", (int)flagPosition.x + 10, (int)flagPosition.y + 10, 20, DARKGRAY);
            DrawText("Points: 1", (int)flagPosition.x + 10, (int)flagPosition.y + 40, 20, DARKGRAY);
        }
    }
}

void displayCapitalCities()
{
	
    int coordinatesX[39] = { 435, 695, 775, 850, 850, 850, 870, 900, 1000, 710, 485, 550, 570, 460, 365, 710, 640, 610, 617, 725, 825, 725, 760, 778, 795, 740, 762, 795, 810, 818, 820, 910, 940, 947, 625, 845, 835, 870, 885 };
	int coordinatesY[39] = { 90, 270, 285, 255, 280, 325, 365, 375, 305, 365, 375, 430, 495, 640, 655, 645, 540, 455, 423, 425, 425, 475, 515, 515, 530, 558, 560, 600, 636, 656, 580, 585, 523, 455, 475, 640, 625, 625, 718 };
   
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
