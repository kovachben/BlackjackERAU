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


void totalValueInitialize(int totalValue[], int playerCount)
// Resets the initial blackjack value of each hand to zero
{
  int i;
  
  for (i=0; i<playerCount; i++)
  {
    totalValue[i] = 0;
  }
}
  
void bjValueCalculatorAll(int totalValue[], struct deck Deck[], int playerCount) 
// Calculates the blackjack value for every hand
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


void bjValueCalculator(int totalValue[], struct deck Deck[], int playerNumber) 
// calculates the value of a single hand
{
  int i;
  totalValue[playerNumber] = 0; 
  
  for (i=51; i>=0; i--)
  {
    if (Deck[i].playerDrawn == playerNumber)
    {
      totalValue[playerNumber] = totalValue[playerNumber] + Deck[i].bjValue;
      if (i<=3 && totalValue[playerNumber] > 21) // ace logic (EXPLAIN MORE)
      {
        totalValue[playerNumber] = totalValue[playerNumber] - 10;
      }
    }
  }
}


