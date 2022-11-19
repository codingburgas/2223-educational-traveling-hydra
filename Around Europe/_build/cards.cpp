#include "cards.h"

int cardRandomizer(int randCard)
{
    int oldCardNumber = 0;

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        randCard = rand() % 6 + 1;
        
        while(randCard == oldCardNumber) {
            randCard = rand() % 6 + 1;
        }
        oldCardNumber = randCard;
        return randCard;
    }
}

int cardFrameCounter(int cardsOrder, int cardFrame) {
    switch (cardRandomizer(cardsOrder)) {
    case 1:
        return cardFrame += 0;
        break;
    case 2:
        return cardFrame += 1;
        break;
    case 3:
        return cardFrame += 2;
        break;
    case 4:
        return cardFrame += 3;
        break;
    case 5:
        return cardFrame += 4;
        break;
    }
}

void showCardsPlayerOne(Texture2D cards, Rectangle deck) {
    
    float cardWidth = (float)(cards.width / 6);
    int cardsOrder = 0;
    float coordinateY = 120;
    int cardFrame = 1;
    int maxCardsFrame = (int)(cards.width / (int)cardWidth);
    
    for (int i = 0; i < 3; i++) {
        cardFrame = cardFrameCounter(cardsOrder, cardFrame);
        cardFrame %= maxCardsFrame;
        
        DrawTextureRec(cards, {cardFrame * cardWidth, 0,  cardWidth, (float)cards.height}, {5, coordinateY}, WHITE);
        coordinateY += 200;
    }


}
void showCardsPlayerTwo(Texture2D cards, Rectangle deck) {
    
    float cardWidth = (float)(cards.width / 6);
    int cardsOrder = 0;
    float coordinateY = 120;
    int cardFrame = 1;
    int maxCardsFrame = (int)(cards.width / (int)cardWidth);

    for (int i = 0; i < 3; i++) {
        cardFrame = cardFrameCounter(cardsOrder, cardFrame);
        cardFrame %= maxCardsFrame;

        DrawTextureRec(cards, { cardFrame * cardWidth, 0,  cardWidth, (float)cards.height }, { 1230, coordinateY }, WHITE);
        coordinateY += 200;
    }

}
