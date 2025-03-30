#include <stdio.h>
#include "blackjack.h"
#include <stdlib.h>
/*
  File: game.c
  Author: Ben Kovach
  Assignment: Group Project
  Date: 3/18/2025
  References: Stack Overflow getchar
*/

int main()
{
  int playerCount, i;
  int dealerValue;
  float bets[2][MAX_PLAYERS];
  int splitHand[12];
  int splitCheck[MAX_PLAYERS];
  int check = 0; 
  for (i=0; i<MAX_PLAYERS; i++)
  {
    splitCheck[i] = 0;
  }
  for (i = 0; i < 12; i++) 
  {
    splitHand[i] = 0;
  }
  int gameCount = 0;
  printf("|----- Welcome to Blackjack -----|");
  printf("\n\n\nHow many players are there (1-4)?"); //ERROR CHECK COMPLETE
  printf("\nEnter number here: ");
  while (check != 1)
  {
    if (scanf("%d", &playerCount) != 1)
    { 
      printf("Please enter a number between 1 and 4: "); // check for valid input
      while(getchar() != '\n');
    } 
    else if (playerCount < 1 || playerCount > MAX_PLAYERS) // ensure number is within bounds
    {
      printf("Please enter a number between 1 and 4: "); 
    }
    else
    {
      check = 1; 
    } 
  }
  int totalValue[MAX_PLAYERS];
  int gameStatus = 1;
  struct deck Deck[52];
  initializeMoney(bets, playerCount);
  while (gameStatus == 1) // Move to separate file
  {
    gameCount++;
    placeBets(bets, playerCount);
    fillDeck(Deck);
    dealerInitial(Deck);
    drawInitial(Deck, playerCount);
    handValueCalculatorAll(totalValue, Deck, playerCount);
    playerPrompt(totalValue, playerCount, Deck, bets, splitHand, splitCheck);
    dealerAction(Deck, dealerValue);
    dealerValue = dealerCalculator(Deck, dealerValue);
    gameEnd(totalValue, bets, dealerValue, playerCount, splitHand, splitCheck);
    gameStatus = nextGame(gameCount, bets, playerCount);
  }
  return 0;
}

    
  
    
  
  