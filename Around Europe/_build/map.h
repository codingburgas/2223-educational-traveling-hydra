#pragma once

#include <iostream>
#include "raylib.h"

using namespace std;

void displayMap(Texture2D map);
Vector2 chooseCountry(Rectangle countryCollisions, Vector2 mousePosition);