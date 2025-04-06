#include <stdio.h>
#include "blackjack.h"
#include <unistd.h>
/*
   Author: Sophia Noriega, Ben Kovach
*/

// Deals the dealer two cards and displaying one.
void dealerInitial(struct deck Deck[])
{ 
  int i;
  drawRandom(Deck, 20); // All values in the 20's belong to the dealer.
  drawRandom(Deck, 21); // draws second card
  
  for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == 20)
    {
      printf("\n\nDealer's Hand:\n\n");
      printf("Card 1: %s of %s\n", Deck[i].card, Deck[i].suit);
      printf("Card 2: ???\n\n");
    } 
  }   
} 

// Calculates the hand value for the dealer
int dealerCalculator(struct deck Deck[], int dealerValue)
{
  int i;
  dealerValue = 0;
  
  for (i=51; i>=0; i--)
  {
    if (Deck[i].playerDrawn >= 20)
    {
      dealerValue = Deck[i].handValue + dealerValue;
      
      if (i<=3 && dealerValue > 21)
      {
        dealerValue = dealerValue - 10;
      }
      
    }
  }
  
  return dealerValue;
}

// Contains logic for if the dealer hits or stands
void dealerAction(struct deck Deck[], int dealerValue)
{
  int i, done;
  printf("\n\nDealer's Hand:\n\n");
  
  for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == 20)
    {
      printf("Card 1: %s of %s\n", Deck[i].card, Deck[i].suit);
    }
  }
  
  for(i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == 21)
    {
      printf("Card 2: %s of %s\n", Deck[i].card, Deck[i].suit);
    }
  }
  
  dealerValue = dealerCalculator(Deck, dealerValue);
  printf("Hand Value: %d", dealerValue);
  int cardAssignment = 22;
  
  while (dealerValue < 17)
  {
      cardAssignment = dealerHit(Deck, dealerValue, cardAssignment);
      dealerValue = dealerCalculator(Deck, dealerValue);
  }
  
}

// Hits for the dealer
int dealerHit(struct deck Deck[], int dealerValue, int cardAssignment)
{
  drawRandom(Deck, cardAssignment); 
  
  int i;
  printf("\n\nThe dealer draws another card...\n");
  
  sleep(2);
  
  for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == cardAssignment)
    {
      printf("Dealer's New Card: %s of %s", Deck[i].card, Deck[i].suit);
    }
  }
  
  dealerValue = dealerCalculator(Deck, dealerValue);
  printf("\nNew hand value: %d", dealerValue);
  cardAssignment++;
  return cardAssignment;
}  