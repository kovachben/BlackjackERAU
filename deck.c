#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "blackjack.h"
#include <time.h> 

/*
   File : deck.c
   Author: Sophia Noriega
   Assignment: Deck
   Date: 03/18/2025
   References: Stack Overflow - Seeding rand()
*/

// drawRandom is a function to randomly draw a card for a player
void drawRandom(struct deck Deck[], int playerNumber)
{
  int cardDrawn; 
  int check = 0;
  
  srand(time(NULL)); 
  
  while (check = 0)
  {
    cardDrawn = rand() % 52; 
    
    if (Deck[cardDrawn].drawn != 0)
    {
    } // Draw new card while true
    else
    {
      check = 1;
    }
  }
  
  Deck[cardDrawn].drawn = 1;
  Hand[playerNumber].cardcount ++;
  Deck[cardDrawn].playerDrawn = playerNumber;
} 


void fillDeck(struct deck Deck[])
{
  int i;
  
  for (i=0; i<=51; i++) //All cards given an initial drawn value of 0
  {
    deck[i].drawn = 0;
  }
  
  // Filling cards based on number/name 4 at a time
  
  for (i=0; i<=3; i++) //0-3 is ace
  {
    strcpy(deck[i].card, "Ace");
    deck[i].bjValue = 11;
  }

  for (i=4; i<=7; i++) //4-7 is two
  {
    strcpy(deck[i].card, "Two");
    deck[i].bjValue = 2;
  }
  
  for (i=8; i<=11; i++) // 8-11 is three
  {
    strcpy(deck[i].card, "Three")
    deck[i].bjValue = 3;
  }
  
  for (i=12; i<=15; i++)
  {
    strcpy(deck[i].card, "Four") // 12-15 is four
    deck[i].bjValue = 4;
  }
  
  for (i=16; i<=19; i++)
  {
    strcpy(deck[i].card, "Five") // 16-19 is five
    deck[i].bjValue = 5;
  }
  
  for (i=20; i<=23; i++)
  {
    strcpy(deck[i].card, "Six") // 20-23 is Six
    deck[i].bjValue = 6;
  }
  
  for (i=24; i<=27; i++)
  {
    strcpy(deck[i].card, "Seven") // 24-27 is seven
    deck[i].bjValue = 7;
  }
  
  for (i=28; i<=31; i++)
  {
    strcpy(deck[i].card, "Eight") // 28-31 is Eight
    deck[i].bjValue = 8;
  }
  
  for (i=32; i<=35; i++)
  {
    strcpy(deck[i].card, "Nine") // 32-35 is nine
    deck[i].bjValue = 9;
  }
  
  for (i=36; i<=39; i++)
  {
    strcpy(deck[i].card, "Ten") // 36-39 is ten
    deck[i].bjValue = 10;
  }
  
  for (i=40; i<=43; i++)
  {
    strcpy(deck[i].card, "Jack") // 40-43 is Jack
    deck[i].bjValue = 10;
  }
  
  for (i=44; i<=47; i++)
  {
    strcpy(deck[i].card, "Queen") // 44-47 is Queen
    deck[i].bjValue = 10;
  }
  
  for (i=48; i<=51; i++)
  {
    strcpy(deck[i].card, "King") // 48-51 is King
    deck[i].bjValue = 10;
  }
  
  for (i=0; i<=51; i++)
  {
    deck[i].playerDrawn = 200;// Set to a number that will never equal the player count
  }
}

void cardCountInitialize(struct hand Hand[], int playercount) // Sets  card count equal to zero, so it can be incremented correctly
{
  int i;
  
  for (i=0; i<playercount; i++)
  {
    Hand[i].cardCount = -1; // Starts at -1 so it can be easily incremented and index the proper values
  }
}
  
    // need a random card puller - use time.h 
// Draw a randon card 
    
