#ifndef blackjack_h
#define blackjack_h

struct deck
{
  int bjValue;
  char card[50];
  char suit[50];
  int drawn;
  int playerDrawn;
};


void fillDeck(struct deck Deck[]);

void drawInitial(struct deck Deck[], int playerCount);

void totalValueInitialize(int totalValue[], int playerCount);

void bjValueCalculator(int totalValue[], struct deck Deck[], int playerCount);

void playerPrompt(int totalValue[], int playerCount, struct deck Deck[]);

#endif