#ifndef BLACKJACK_H
#define BLACKJACK_H

/*
   File : dealer.c
   Author: Ben Kovach
   Assignment: dealer
   Date: 03/24/2025
   References:
*/

struct deck
{
  int bjValue;
  char card[50];
  char suit[50];
  int drawn;
  int playerDrawn;
};

void giveMoney(float bets[2][4], int playerCount);

void fillDeck(struct deck Deck[]);

void drawInitial(struct deck Deck[], int playerCount);

void bjValueCalculatorAll(int totalValue[], struct deck Deck[], int playerCount);

void playerPrompt(int totalValue[], int playerCount, struct deck Deck[], float bets[2][4], int splitHand[], int splitCheck[]);

void dealerInitial(struct deck Deck[]);

void dealerAction(struct deck Deck[], int dealerValue);

void placeBets(float bets[2][4], int playerCount);

void gameEnd(int totalValue[], float bets[2][4], int dealerValue, int playerCount, int splitHand[], int splitCheck[]);

int nextGame(int gameCount, float bets[2][4], int playerCount);

#endif