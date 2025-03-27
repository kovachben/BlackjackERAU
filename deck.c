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

// Function to randomly draw a card for a player
void drawRandom(struct deck Deck[], int playerNumber)
{
  int cardDrawn; 
  int check = 0;
  srand(time(NULL)); 
  
  while (check == 0)
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
  Deck[cardDrawn].playerDrawn = playerNumber;
} 
// Function to draw a card to all players, utilizes the drawRandom function above
void drawInitial(struct deck Deck[], int playerCount)
{
  int i;
  
  for (i=0; i<playerCount; i++)
    {
      drawRandom(Deck, i);
    } 
  for (i=0; i<playerCount; i++)
    {
      drawRandom(Deck, i);
    }
}

void fillDeck(struct deck Deck[])
{
  int i;
  for (i=0; i<=51; i++) //All cards given an initial drawn value of 0
  {
    Deck[i].drawn = 0;
  }
  // Filling cards based on number/name 4 at a time
  for (i=0; i<=3; i++) //0-3 is ace
  {
    strcpy(Deck[i].card, "Ace");
    Deck[i].bjValue = 11;
  }
  for (i=4; i<=7; i++) //4-7 is two
  {
    strcpy(Deck[i].card, "Two");
    Deck[i].bjValue = 2;
  }
  for (i=8; i<=11; i++) // 8-11 is three
  {
    strcpy(Deck[i].card, "Three");
    Deck[i].bjValue = 3;
  }
  for (i=12; i<=15; i++)
  {
    strcpy(Deck[i].card, "Four"); // 12-15 is four
    Deck[i].bjValue = 4;
  }
  for (i=16; i<=19; i++)
  {
    strcpy(Deck[i].card, "Five"); // 16-19 is five
    Deck[i].bjValue = 5;
  }
  for (i=20; i<=23; i++)
  {
    strcpy(Deck[i].card, "Six"); // 20-23 is Six
    Deck[i].bjValue = 6;
  }
  for (i=24; i<=27; i++)
  {
    strcpy(Deck[i].card, "Seven"); // 24-27 is seven
    Deck[i].bjValue = 7;
  }
  for (i=28; i<=31; i++)
  {
    strcpy(Deck[i].card, "Eight"); // 28-31 is Eight
    Deck[i].bjValue = 8;
  }
  for (i=32; i<=35; i++)
  {
    strcpy(Deck[i].card, "Nine"); // 32-35 is nine
    Deck[i].bjValue = 9;
  }
  for (i=36; i<=39; i++)
  {
    strcpy(Deck[i].card, "Ten"); // 36-39 is ten
    Deck[i].bjValue = 10;
  }
  for (i=40; i<=43; i++)
  {
    strcpy(Deck[i].card, "Jack"); // 40-43 is Jack
    Deck[i].bjValue = 10;
  }
  for (i=44; i<=47; i++)
  {
    strcpy(Deck[i].card, "Queen"); // 44-47 is Queen
    Deck[i].bjValue = 10;
  }
  for (i=48; i<=51; i++)
  {
    strcpy(Deck[i].card, "King"); // 48-51 is King
    Deck[i].bjValue = 10;
  }
  for (i=0; i<=51; i++)
  {
    Deck[i].playerDrawn = 19;// Set to a number that will never equal the player count
  }
  for (i=0; i<=51; i++)
  {
    Deck[i].drawn = 0; // Initialized all cards to not have been drawn
  }
  for (i = 0; i <= 51; i++) 
  {
    if (i % 4 == 0) 
    {
      strcpy(Deck[i].suit, "Diamonds");
    } 
    else if (i % 4 == 1) 
    {
      strcpy(Deck[i].suit, "Clubs");
    } 
    else if (i % 4 == 2) 
    {
      strcpy(Deck[i].suit, "Spades");
    } 
    else if (i % 4 == 3) 
    {
      strcpy(Deck[i].suit, "Hearts");
    }
  } 
}