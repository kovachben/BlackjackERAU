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
  
  for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == playerNumber)
    {
      totalValue[playerNumber] = totalValue[playerNumber] + Deck[i].bjValue;
    }
  }
  
  if (i<=3 && totalValue[playerNumber] > 21)
  {
      totalValue[playerNumber] = totalValue[playerNumber] - 10;
  }
}


void playOptions(int playerNumber, int totalValue[], struct deck Deck[])
{
  int choice;
  int done = 0;
  int i;
  int cardNumber = 1;
  
  while (done == 0)
  {
    printf("\n\nWould you like to...");
    printf("\n\n1) Hit\n2) Stand\n3) Double Down\n4) Split");
    printf("\nEnter your selection: ");
    scanf("%d", &choice);
    // Reminder: do errror checking
    switch (choice)
    {
      case 1: // hit
        drawRandom(Deck, playerNumber); // draws card
        bjValueCalculator(totalValue, Deck, playerNumber); //Calculates new hand value
        
        printf("\nNew Hand:\n\n");
        for (i=0; i<52; i++)
        {
          if (playerNumber == Deck[i].playerDrawn)
          {
            printf("Card %d:\n%s of %s\n", cardNumber, Deck[i].card, Deck[i].suit);
            cardNumber++; 
          } 
        }
        printf("New hand value: %d", totalValue[playerNumber]);
        cardNumber = 1; // resets card value for next player
      
        break; 
        
      case 2: // Stand
        done = 1; 
        break; 
      
      case 3: // Double down function
        drawRandom(Deck, playerNumber);
        bjValueCalculator(totalValue, Deck, playerNumber); 
        done = 1;
        break; 
        
      case 4: 
        // Split function
        break; 
      
      default: 
        printf("Please enter a number between 1 and 4");
        scanf("%d",&choice); // ERROR CHECK
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
        printf("Card %d:\n%s of %s\n", cardNumber, Deck[j].card, Deck[j].suit);
        cardNumber++;
      }
    }
    cardNumber = 1; 
      
    printf("\nTotal blackjack value: %d\n", totalValue[i]);
    
    playOptions(i, totalValue, Deck);
  }
}


