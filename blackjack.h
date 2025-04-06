#ifndef BLACKJACK_H
#define BLACKJACK_H
#define MAX_PLAYERS 4
/*
   Author: Ben Kovach
*/

struct deck
{
  int handValue;
  char card[50];
  char suit[50];
  int drawn;
  int playerDrawn;
};

void initializeMoney(float bets[2][MAX_PLAYERS], int playerCount);

void fillDeck(struct deck Deck[]);

void drawInitial(struct deck Deck[], int playerCount);

void handValueCalculatorAll(int totalValue[], struct deck Deck[], int playerCount);

void playerPrompt(int totalValue[], int playerCount, struct deck Deck[], float bets[2][MAX_PLAYERS], int splitHand[], int splitCheck[]);

void dealerInitial(struct deck Deck[]);

int dealerAction(struct deck Deck[], int dealerValue, int dealerBlackjack);

void placeBets(float bets[2][MAX_PLAYERS], int playerCount);

void gameEnd(int totalValue[], float bets[2][MAX_PLAYERS], int dealerValue, int playerCount, int splitHand[], int splitCheck[], int gameCount, struct deck Deck[], int dealerBlackjack);

int nextGame(int gameCount, float bets[2][MAX_PLAYERS], int playerCount);

#endif