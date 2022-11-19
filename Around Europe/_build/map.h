#pragma once

#include <iostream>
#include "raylib.h"

using namespace std;

void displayMap(Texture2D map);
Vector2 chooseCountry(Vector2 mousePosition);
void displayFlagOrCountryInfo(Texture2D flag, Rectangle playerFlag, Vector2 flagPosition);
bool checkMouseButton();