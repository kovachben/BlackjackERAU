#include <stdio.h>
#include "blackjack.h"

/*
  File: game.c
  Author: Ben Kovach
  Assignment: Group Project
  Date: 3/18/2025
  References:
*/

int main()
{
  int playerCount, i;
  
  printf("------ Welcome to Blackjack ------\n");
  printf("\n\n\nHow many players are there (1-4)?");
  printf("\nEnter number here: ");
  scanf("%d", &playerCount);
  
  int totalValue[playerCount];
  
  int gameStatus = 1;
  
  struct deck Deck[52];
  
  while (gameStatus == 1); // Move to separate file
  {
    fillDeck(Deck);
    cardCountInitialize(Hand, playerCount);
    
    for (i=0; i<playerCount; i++)
    {
      randomDraw(Deck, i);
    }
    
    for (i=0; i<playerCount; i++)
    {
      randomDraw(Deck, i);
    }
    
    
    printPlayerHand(Deck, playerCount);
    
    
    
    
  }
  

    
  
    
  
  