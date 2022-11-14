#include "cards.h"

void cardRandomizer(int randCard[])
{
    int temp = time(nullptr);
    srand(temp);

    int count = 5;

    for (int i = 0; i < count; i++)
    {
        int j = rand() % count;

        swap(randCard[i], randCard[j]);
    }

    for (int i = 0; i < count; i++)
    {
        cout << randCard[i] << " ";
    }
}

void showCardsPlayerOne(Texture2D cards, Rectangle deck) {
    
    float coordinateY = 120;

    for (int i = 0; i < 4; i++) {
        DrawTextureRec(cards, deck, { 5, coordinateY }, WHITE);
        coordinateY += 200;
    }

}
void showCardsPlayerTwo(Texture2D cards, Rectangle deck) {
    
    float coordinateY = 120;

    for (int i = 0; i < 4; i++) {
        DrawTextureRec(cards, deck, { 1230, coordinateY }, WHITE);
        coordinateY += 200;
    }

}
