#include <stdio.h>
#include "blackjack.h"
#include <unistd.h>
/*
   File : playerhand.c
   Author: Sophia Noriega
   Assignment: Deck
   Date: 03/19/2025
   References:
*/


void totalValueInitialize(int totalValue[], int playerCount) // Resets the initial blackjack value of each hand to zero
{
  int i;
  
  for (i=0; i<playerCount; i++)
  {
    totalValue[i] = 0;
  }
}
  
void bjValueCalculatorAll(int totalValue[], struct deck Deck[], int playerCount) // Calculates the blackjack value of each hand
{
  int i, j;
  
  for (i=0; i<playerCount; i++)
  {
    for (j=0; j<52; j++)
    {
      if (Deck[j].playerDrawn == i)
      {  
        totalValue[i] = totalValue[i] + Deck[j].bjValue;
      }
    }
  }
}

void playerPrompt(int totalValue[], int playerCount, struct deck Deck[])
{
  int i, j;
  int cardNumber = 1;
  for (i=0; i<playerCount; i++)
  {
    printf("\nDealing player %d's cards!\n", i + 1);
    sleep(2);
    
    for (j=0; j<52; j++)
    {
      if (i == Deck[j].playerDrawn)
      {
        printf("Card %d:\n%s of %s\n", cardNumber, Deck[i].card, Deck[i].suit);
        cardNumber++;
      }
    }
      
    printf("\nTotal blackjack value: %d", totalValue[i]);
  }
}