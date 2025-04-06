#include <stdio.h>
#include "blackjack.h"
#include <time.h> 
#include <string.h>
/*
   Authors: Ben Kovach, Sophia Noriega
*/

// Doubling down: draws another card, doubles the players bet, and ends the turn
int doubleDown(float bets[2][MAX_PLAYERS], struct deck Deck[], int playerNumber, int totalValue[])
{
  int done;
  
  if (bets[0][playerNumber] > bets[1][playerNumber]) // Ensuring the player has enough money to split
  {
    printf("\nNot enough money to double down.");
    done = 0;
    return done;
  } 
  
  drawRandom(Deck, playerNumber); // Drawing another card and calculating the new hand value
  handValueCalculator(totalValue, Deck, playerNumber);
  bets[1][playerNumber] = bets[1][playerNumber] - bets[0][playerNumber]; // Withdrawing from player's "account"
  bets[0][playerNumber] = bets[0][playerNumber] * 2; // Doubling bet
 
  printf("Player %d doubles down!\n", playerNumber+1);
  printf("New Bet: $%.2f\n\n", bets[0][playerNumber]);
  printf("New Hand:\n");
 
  int i;
  int cardNumber = 1;
	
	for (i=0; i<52; i++)
  {
    if (Deck[i].playerDrawn == playerNumber)
    {
      printf("\nCard %d: %s of %s", cardNumber, Deck[i].card, Deck[i].suit);
      cardNumber++;
    }
  }
  printf("\nNew hand value: %d", totalValue[playerNumber]);
  done = 1; // Returns a value to end the players turn in playerOptions
  return done;
}

// Hit: draws another card and prints the players new hand 
void hit(int totalValue[], struct deck Deck[], int playerNumber)
{
  int cardNumber = 1;
  int i;
  drawRandom(Deck, playerNumber); // draws card
  handValueCalculator(totalValue, Deck, playerNumber); 
        
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
}

// Split: splits the hand into two
int split(int playerNumber, int totalValue[], struct deck Deck[], int splitHand[], float bets[2][MAX_PLAYERS], int splitNumber, int splitCheck[])
{
  int over;
  int cardOneValue, cardTwoValue;
  int i, choice, j, done;
  int check = 0;
  int cardNumber = 2;
  int cardCount = 0;
  
  // Ensuring the player has two cards
  for (i = 0; i < 52; i++)
  {
    if (Deck[i].playerDrawn == playerNumber)
    {
      cardCount++;
    }
  }
  
  if (cardCount != 2)
  {
    printf("\nToo many cards. You can only split with two cards.\n");
    over = 0;
    return over;
  }
  
	// Finding the two cards in the player's hand
  for (i = 0; i < 52; i++) 
	{
    if (Deck[i].playerDrawn == playerNumber) 
    {
      if (check == 0) 
      {
        cardOneValue = Deck[i].handValue;
        check = 1;
      } 
      
      else
      {
        cardTwoValue = Deck[i].handValue;
      }
    }
  }

  // Ensuring the player has two of the same card
  if (cardOneValue != cardTwoValue)
  {
    printf("\nYour hand is not eligible for a split.\n");
    over = 0;
    return over;
  }
  
  // Verifying the player has enough money
	if (bets[0][playerNumber] > bets[1][playerNumber])
  {
    printf("\nNot enough money to split.\n");
    over = 0;
    return over;
  } 
  
  bets[1][playerNumber] = bets[1][playerNumber] - bets[0][playerNumber];
  bets[0][playerNumber] = bets[0][playerNumber] * 2;
  splitCheck[playerNumber] = 1;
  
  for (i = 0; i < 52; i++) // Assigning an initial value to each hand
  {
    if (Deck[i].playerDrawn == playerNumber)
    {
      splitHand[splitNumber] = Deck[i].handValue;
      splitHand[splitNumber + 1] = Deck[i].handValue;
    }
  }
  
  int firstCard = 1;
  
  for (i = 0; i < 52; i++) // Assigning one card to each split hand
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
  
  for (i = splitNumber; i <= splitNumber + 1; i++) // printing initial split hand
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
      
			if (scanf("%d", &choice) != 1) 
      {
        printf("Invalid input. Please enter 1 or 2.\n");
        
				while (getchar() != '\n');
        {
         continue; 
        }
      }
    
      switch (choice) 
      {
        case 1:
          drawRandom(Deck, i);
          splitHand[i] = 0;
            
            for (j = 0; j < 52; j++) 
            {
              if (Deck[j].playerDrawn == i) 
              {
                splitHand[i] += Deck[j].handValue;
              }
            }
            
            if (splitHand[i] > 21) 
            {
              printf("Player %d, hand %d has busted! Value: %d\n", playerNumber+1, i - 4, splitHand[i]);
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
   
// Provides users with menu to hit, stand, double down, or split
int playOptions(int playerNumber, int totalValue[], struct deck Deck[], float bets[2][MAX_PLAYERS], int splitHand[], int splitCheck[], int splitNumber)
{
  int choice, i; 
  int done = 0;
  
  if (totalValue[playerNumber] == 21)
  {
    printf("\n\nBlackjack for player %d!!!\n\n", playerNumber + 1);
    return;
  }
  
	while (done == 0)
  {
    int check = 0;
    
		if (totalValue[playerNumber] > 21)
    {
      done = 1;
    }
    printf("\n\nWould you like to...");
    printf("\n\n1) Hit\n2) Stand\n3) Double Down\n4) Split");
    printf("\nEnter your selection: ");    
    
		while (check != 1)
    {
      if (scanf("%d", &choice) != 1)
      { 
        printf("\nPlease enter a number between 1 and 4: "); // check for valid input
        while(getchar() != '\n');
      } 
      else if (choice < 1 || choice > 4) // ensure number is within bounds
      {
        printf("Please enter a number between 1 and 4.\n"); 
      }
      else
      {
        check = 1; 
      } 
    }
   
	  switch (choice)
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
        printf("Please enter a number between 1 and 4: ");
    }
    
    if (totalValue[playerNumber] > 21)
    {
      done = 1;
    }
  }
  
  if (totalValue[playerNumber] > 21)
  {
    printf("\n\nPlayer %d has busted. You lose $%.2f\n\n", playerNumber + 1, bets[0][playerNumber]);
  }
  return splitNumber;
}

// Prints the intial cards for each player and the hand value
void playerPrompt(int totalValue[], int playerCount, struct deck Deck[], float bets[2][MAX_PLAYERS], int splitHand[], int splitCheck[])
{
  int i, j;
  int cardNumber = 1;
  int splitNumber = 5;
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
    printf("\nTotal hand value: %d\n", totalValue[i]);
    splitNumber = playOptions(i, totalValue, Deck, bets, splitHand, splitCheck, splitNumber);
  }
}
