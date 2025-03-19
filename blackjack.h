#ifndef blackjack.h
#define blackjack.h

struct deck
{
  int bjValue;
  char card[50];
  char suit[50];
  int drawn;
  int playerDrawn;
};

struct hand
{
  int totalValue;
  struct deck playerCard[11]; // Maximum number of cards for a blackjack hand is 11
  int cardCount;
};

void fillDeck(struct deck Deck);

void drawRandom(struct deck Deck, struct hand Hand, int playerNumber);

#endif