#include <stdio.h>
#include "blackjack.h"
#include <time.h> 
#include <string.h>
/*
   File : playerhand.c
   Author: Ben Kovach, Sophia Noriega
   Assignment: Deck
   Date: 03/21/2025
   References:
*/

int doubleDown(float bets[2][4], struct deck Deck[], int playerNumber, int totalValue[])
{
  int done;
  if (bets[0][playerNumber] > bets[1][playerNumber])
  {
    printf("\nNot enough money to double down.");
    done = 0;
    return done;
  } 
  drawRandom(Deck, playerNumber);
  bjValueCalculator(totalValue, Deck, playerNumber); 
  bets[1][playerNumber] = bets[1][playerNumber] - bets[0][playerNumber];
  bets[0][playerNumber] = bets[0][playerNumber] * 2;
  int i;
  int cardNumber = 1;
  printf("Player %d doubles down!\n", playerNumber+1);
  printf("New Bet: $%.2f\n\n", bets[0][playerNumber]);
  printf("New Hand:\n");
  for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == playerNumber)
    {
      printf("\nCard %d: %s of %s", cardNumber, Deck[i].card, Deck[i].suit);
      cardNumber++;
    }
  }
  printf("\nNew hand value: %d", totalValue[playerNumber]);
  done = 1;
  return done;
}
  
void hit(int totalValue[], struct deck Deck[], int playerNumber)
{
  int cardNumber = 1;
  int i;
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
  cardNumber = 1; // resetting card value for next player
}

int split(int playerNumber, int totalValue[], struct deck Deck[], int splitHand[], float bets[2][4], int splitNumber, int splitCheck[])
{
  int over;
  char strc1[25];
  char strc2[25];
  int i, choice, j, done;
  int check = 0;
  int cardNumber = 2;
  // Finding the two cards in the player's hand
  for (i = 0; i < 52; i++) 
  {
    if (Deck[i].playerDrawn == playerNumber) 
    {
      if (check == 0) 
      {
        strcpy(strc1, Deck[i].card);
        check = 1;
      } 
      else
      {
        strcpy(strc2, Deck[i].card);
        break;
      }
    }
  }

  // Ensuring the player can split
  if (strcmp(strc1, strc2) != 0) 
  {
    printf("\nYour hand is not eligible for a split.\n");
    over = 0;
    return over;
  }
  if (bets[0][playerNumber] > bets[1][playerNumber])
  {
    printf("\nNot enough money to split.");
    over = 0;
    return over;
  } 
  // Resetting split hands (for calculating value if two players split)
  for (i = 0; i < 6; i++) 
  {
    splitHand[i] = 0;
  }
  bets[1][playerNumber] = bets[1][playerNumber] - bets[0][playerNumber];
  bets[0][playerNumber] = bets[0][playerNumber] * 2;
  splitCheck[playerNumber] = 1;
  // Setting initial values for hands
  splitHand[splitNumber] = totalValue[playerNumber] / 2;
  splitHand[splitNumber + 1] = totalValue[playerNumber] / 2;
  
  ///////////////////////////totalValue[playerNumber] = splitNumber;
  // Assigning one card to each split hand
  int firstCard = 1;
  for (i = 0; i < 52; i++) 
  {
    if (Deck[i].playerDrawn == playerNumber) 
    {
      if (firstCard) 
      {
        Deck[i].playerDrawn = splitNumber; // first split hand
        firstCard = 0;
      } 
      else 
      {
        Deck[i].playerDrawn = splitNumber + 1; //second split hand
        break;
      }
    }
  }
  // printing initial split hand
  for (i = splitNumber; i <= splitNumber + 1; i++) 
  {
    done = 0;
    while (done == 0) 
    {
      printf("\nHand %d:\nValue: %d\n", (i - 4), splitHand[i]);
      cardNumber = 1;
      for (j = 0; j < 52; j++) 
      {
        if (Deck[j].playerDrawn == i) 
        {
          printf("Card %d: %s of %s\n", cardNumber, Deck[j].card, Deck[j].suit);
          cardNumber++;
        }
      }
      printf("Would you like to...\n");
      printf("1) Hit\n2) Stand\n");
      printf("Enter selection here: ");
      scanf("%d", &choice);
      /*\\if (scanf("%d", &choice) != 1) 
      {
        printf("Invalid input. Please enter 1 or 2.\n");
        while (getchar() != '\n');
        {
        continue; // idk if thats right 
        }
      }
      */
      switch (choice) 
      {
        case 1:
          drawRandom(Deck, i);
          splitHand[i] = 0;
            for (j = 0; j < 52; j++) 
            {
              if (Deck[j].playerDrawn == i) 
              {
                splitHand[i] += Deck[j].bjValue;
              }
            }
            if (splitHand[i] > 21) 
            {
              printf("Player %d, hand %d has busted! Value: %d\n", playerNumber+1, i - 3, splitHand[i]);
              done = 1;
            }
          break;
        case 2:
          done = 1;
          break;
        default:
          printf("Error. Please enter a 1 or 2.\n");
          scanf("%d", &choice); 
      }
    }
  }
  over = 1;
  return over;
}
   
void playOptions(int playerNumber, int totalValue[], struct deck Deck[], float bets[2][4], int splitHand[], int splitCheck[])
{
  int choice, i;
  int done = 0;
  int splitNumber = 5;
  while (done == 0)
  {
    if (totalValue[playerNumber] > 21)
    {
      done = 1;
    }
    printf("\n\nWould you like to...");
    printf("\n\n1) Hit\n2) Stand\n3) Double Down\n4) Split");
    printf("\nEnter your selection: ");
    scanf("%d", &choice);
    switch (choice) // DO ERROR CHECKING
    {
      case 1: // hit
        hit(totalValue, Deck, playerNumber);
        break; 
      case 2: // Stand
        done = 1; 
        break; 
      case 3: // Double down
        done = doubleDown(bets, Deck, playerNumber, totalValue);
        break; 
      case 4: 
        done = split(playerNumber, totalValue, Deck, splitHand, bets, splitNumber, splitCheck);
        splitNumber += 2;
        break; 
      default: 
        printf("Please enter a number between 1 and 4");
        scanf("%d",&choice); // ERROR CHECK
    }
    if (totalValue[playerNumber] > 21)
    {
      done = 1;
    }
  }
  if (totalValue[playerNumber] > 21)
  {
    printf("\n\nPlayer %d has busted. You lose $%.2f", playerNumber + 1, bets[0][playerNumber]);
  }
}
      
void playerPrompt(int totalValue[], int playerCount, struct deck Deck[], float bets[2][4], int splitHand[], int splitCheck[])
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
    playOptions(i, totalValue, Deck, bets, splitHand, splitCheck);
  }
}