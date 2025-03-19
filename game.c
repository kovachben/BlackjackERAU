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
  
  printf("------ Welcome to Blackjack ------\n");
  printf("\n\n\nHow many players are there (1-4)?");
  printf("\nEnter number here: ");
  scanf("%d", &playerCount);
  
  int* totalValue = (int*)calloc(playerCount, sizeof(int));
  if (totalValue == NULL)
  {
    printf("Memory allocation failed.");
    return 1;
  }
  
  int gameStatus = 1;
  
  struct deck Deck[52];
  
  while (gameStatus == 1) // Move to separate file
  {
    totalValueInitialize(totalValue, playerCount);
    fillDeck(Deck);
    
    drawInitial(Deck, playerCount);
    bjValueCalculatorAll(totalValue, Deck, playerCount);
    
    playerPrompt(totalValue, playerCount, Deck);

    
    
    gameStatus = 0;
    
    
    
    
  }
  return 0;
}

    
  
    
  
  