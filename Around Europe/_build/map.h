#pragma once

#include "raylib.h"

using namespace std;

// Visualises game background
void displayMap(Texture2D map);

// Makes the capital cities collision
Vector2 chooseCountry(Vector2 mousePosition);

// Visualises flags and country information
void displayFlagOrCountryInfo(Texture2D flag, Rectangle playerFlag, Vector2 flagPosition);

// Checks if any button is clicked
bool checkMouseButton();