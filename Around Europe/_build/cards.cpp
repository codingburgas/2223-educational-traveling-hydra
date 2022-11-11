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