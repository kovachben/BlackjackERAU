#include <stdio.h>
#include "blackjack.h"
#include <unistd.h>
/*
   File : playerhand.c
   Author: Sophia Noriega, Ben Kovach
   Assignment: Deck
   Date: 03/19/2025
   References:
*/
void bjValueCalculatorAll(int totalValue[], struct deck Deck[], int playerCount) 
// Calculates the blackjack value for every hand
{
  int i, j;
  for (i=0; i<playerCount; i++)
  {
    totalValue[i] = 0;
  }
  
  for (i=0; i<playerCount; i++)
  {
    for (j=51; j>=0; j--)
    {
      if (Deck[j].playerDrawn == i)
      {  
        totalValue[i] = totalValue[i] + Deck[j].bjValue;
      }
      if (i<=3 && Deck[j].bjValue > 21)
      {
        totalValue[i] = totalValue[i] - 10;
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
void giveMoney(float bets[2][4], int playerCount)
{
  int i;
  for (i=0; i<playerCount; i++)
  {
    bets[0][i] = 0;
    bets[1][i] = 0;
  }
  for (i=0; i<playerCount; i++)
  { 
    printf("\n\nPlayer %d, how much money do you have? $", i + 1);
    scanf("%f", &bets[1][i]);
  }
}
void placeBets(float bets[2][4], int playerCount)
{
  int i;
  for (i=0; i<playerCount; i++)
  {
    bets[0][i] = 0;
  }
  for (i=0; i<playerCount; i++)
  { 
    int enough = 0;
    while (enough == 0)
    {
      printf("\n\nPlayer %d, place your bet: $", i + 1);
      scanf("%f", &bets[0][i]);
      if (bets[0][i] > bets[1][i])
      {
        printf("Not enough money to place bet. You only have $%.2f", bets[1][i]);
      }
      else
      {
        bets[1][i] = bets[1][i] - bets[0][i];
        enough = 1;
      }
    }
  }
}