#include <stdio.h>
#include "blackjack.h"
#include <stdlib.h>
/*
  File: game.c
  Author: Ben Kovach
  Assignment: Group Project
  Date: 3/18/2025
  References: Stack Overflow (dynamic memory allocation)
*/

int main()
{
  int playerCount, i;
  int dealerValue;
  float bets[2][4];
  int splitHand[12];
  int splitCheck[4];
  for (i=0; i<4; i++)
  {
    splitCheck[i] = 0;
  }
  for (i = 0; i < 12; i++) 
  {
    splitHand[i] = 0;
  }
  int gameCount = 0;
  printf("|----- Welcome to Blackjack -----|");
  printf("\n\n\nHow many players are there (1-4)?");
  printf("\nEnter number here: ");
  scanf("%d", &playerCount);
  // preallocating memory for totalValue array as number of players is unknown.
  int* totalValue = (int*)calloc(playerCount, sizeof(int));
  if (totalValue == NULL)
  {
    printf("Memory allocation failed.");
    return 1;
  }
  int gameStatus = 1;
  struct deck Deck[52];
  giveMoney(bets, playerCount);
  while (gameStatus == 1) // Move to separate file
  {
    gameCount++;
    placeBets(bets, playerCount);
    fillDeck(Deck);
    dealerInitial(Deck);
    drawInitial(Deck, playerCount);
    bjValueCalculatorAll(totalValue, Deck, playerCount);
    playerPrompt(totalValue, playerCount, Deck, bets, splitHand, splitCheck);
    dealerAction(Deck, dealerValue);
    dealerValue = dealerCalculator(Deck, dealerValue);
    gameEnd(totalValue, bets, dealerValue, playerCount, splitHand, splitCheck);
    gameStatus = nextGame(gameCount, bets, playerCount);
  }
  return 0;
}

    
  
    
  
  