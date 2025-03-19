#include <stdio.h>
#include "blackjack.h"

/*
   File : printhand.c
   Author: Ben Kovach
   Assignment: Group Project
   Date: 03/18/2025
   References:
*/

void printPlayerHand(struct deck Deck[], int playerNumber)
{
  int i, j;
  int cardNumber = 1;
  for (i = 0; i < playerNumber; i++)
  {
    printf("\n\nPlayer %d's Hand\n\n", i + 1);
    
    for (j=0; j<=51; j++)
    {
      if (i == Deck[j].playerDrawn)
      printf("Card %d; %s of %s", cardNumber, Deck[j].card, Deck[j].suit)
    }
  }
}

    