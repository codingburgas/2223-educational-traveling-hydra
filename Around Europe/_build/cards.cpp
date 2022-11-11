#include "cards.h"

void CardRandomizer()
{
	srand(time(0));
	int cardRandomising = rand() % 5 + 1;
}