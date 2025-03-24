#include <stdio.h>
#include "blackjack.h"

/*
   File : dealer.c
   Author: Sophia Noriega
   Assignment: dealer
   Date: 03/24/2025
   References:
*/

// dealing the dealer two cards and displaying one.

void dealerInitial(struct deck Deck[])
{ 
  int i;
  int j = 0; 
  
  drawRandom(Deck, 20); // playerNumber arbitrarily assigned to the dealer
  drawRandom(Deck, 20); // draws second card
  
  for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == 20 && j ==0)
    {
      printf("\n\nDealer's hand:\n\n");
      printf("Card 1: %s of %s\n", Deck[i].card, Deck[i].suit);
      printf("Card 2: ???\n\n");
      j++;
    } 
  }   
} 

void dealerCalculator(struct deck Deck[], int dealerValue)
{
  int i;
  dealerValue = 0;
  
  for (i=51; i>=0; i--)
  {
    if (Deck[i].playerDrawn == 20)
    {
      dealerValue = Deck[i].bjValue + dealerValue;
      if (i<=3 && dealerValue > 21)
      {
        dealerValue = dealerValue - 10;
      }
    }
  }
}

//void dealerLogic()