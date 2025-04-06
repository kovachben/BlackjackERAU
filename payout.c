#include <stdio.h>
#include "blackjack.h"
/*
   Author: Sophia Noriega, Ben Kovach
   References: getchar - Stack Overflow
*/

// Game end logic for if a player splits
void splitGameEnd(float bets[2][MAX_PLAYERS], int dealerValue, int playerNumber, int splitHand[], int splitCheck[], int splitNumber)
{
  int i;
  int j=0;

  for (i=splitNumber; i<splitNumber+2; i++)
  {
    j++;
    if (splitHand[i] > dealerValue && splitHand[i] <= 21 || dealerValue > 21 && splitHand[i] == 21)
    {
      printf("\n\nCongratulations player %d! Hand %d wins $%.2f", playerNumber+1, j, bets[0][playerNumber] / 2);
      bets[1][playerNumber] = bets[1][playerNumber] + bets[0][playerNumber];
      continue;
    }
    
    if (splitHand[i] == dealerValue && splitHand[i] <= 21)
    {
     	 printf("\n\nPush! Player %d, hand %d's bet of $%.2f is returned.", playerNumber + 1, j, bets[0][playerNumber] / 2);
       bets[1][playerNumber] = bets[1][playerNumber] + bets[0][playerNumber] / 2;
       continue;
    }  
    
    if (dealerValue > 21 && splitHand[i] <= 21)
    {
     	 printf("\n\nCongratulations player %d! Hand %d wins $%.2f", playerNumber+1, j, bets[0][playerNumber] / 2);
       bets[1][playerNumber] = bets[1][playerNumber] + bets[0][playerNumber];
       continue;
    }
    
    if (splitHand[i] > 21)
    {
     	 continue;
    }
    
    if (dealerValue > splitHand[i] && dealerValue <= 21)
    {
     	 printf("\n\nPlayer %d's hand %d looses. $%.2f lost.", playerNumber+1, j, bets[0][playerNumber] / 2);
       continue;
    }
  }
  
}

// Prints each player's balance after every game to a text file
void printReceipt(float bets[2][MAX_PLAYERS], int playerNumber, int gameCount)
{
  FILE *filePointer = NULL;
  
  if (gameCount == 1 && playerNumber == 0)
  {
    filePointer = fopen("receipt.txt", "w");
    
    if (filePointer == NULL)
    {
      printf("Error opening file!\n");
      return;
    }
    fclose(filePointer);
    filePointer = NULL;
  }
  filePointer = fopen("receipt.txt", "a");
  
  if (filePointer == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  fprintf(filePointer, "Game %d: Player %d's Balance: $%.2f\n", gameCount, playerNumber + 1, bets[1][playerNumber]);
  fclose(filePointer);
  return;
}

// Determines if a player wins, looses, or pushes
void gameEnd(int totalValue[], float bets[2][MAX_PLAYERS], int dealerValue, int playerCount, int splitHand[], int splitCheck[], int gameCount, struct deck Deck[], int dealerBlackJack)
{
  int i, j;
  int splitNumber = 5;
  int cardCount;
  
  for (i=0; i<playerCount; i++)
  {
    cardCount = 0;
    
    for (j = 0; j < 52; j++)
    {
      if (Deck[j].playerDrawn == i)
      {
        cardCount++;
      }
    }
		if (splitCheck[i] == 0)
    {
      if (totalValue[i] > dealerValue && totalValue[i] <= 21 || dealerValue > 21 && totalValue[i] == 21)
      {
    		if (totalValue[i] == 21 && cardCount == 2 && dealerBlackJack != 1)
	 		  {
    	     printf("\n\nBlackjack for player %d! You win $%.2f", i+1, bets[0][i] * 1.5);
					 bets[1][i] = bets[1][i] + bets[0][i] + 1.5 * bets[0][i]; 
    	     continue;
	 		  }
     	  else
       	{
    		  printf("\n\nCongratulations player %d! You win $%.2f", i+1, bets[0][i]);
      		bets[1][i] = bets[1][i] + 2 * bets[0][i];
      		continue;
        }
      }
      
      if (totalValue[i] == dealerValue && totalValue[i] <= 21)
      {
    	   printf("\n\nPush for player %d! Your bet of $%.2f is returned.", i+1, bets[0][i]);
         bets[1][i] = bets[1][i] + bets[0][i];
         continue;
      }
      
      if (dealerValue > 21 && totalValue[i] <= 21)
      {
    	   printf("\n\nCongratulations player %d! You win $%.2f", i+1, bets[0][i]);
         bets[1][i] = bets[1][i] + 2 * bets[0][i];
         continue;
      }
      
      if (totalValue[i] > 21)
      {
        continue;
      }
      
      if (dealerValue > totalValue[i] && dealerValue <= 21)
      {
        printf("\n\nPlayer %d looses. $%.2f lost.", i+1, bets[0][i]);
        continue;
      }
    }
    else
    {
      splitGameEnd(bets, dealerValue, i, splitHand, splitCheck, splitNumber);
      splitNumber += 2; 
      continue;
    }
    
  }
  
  for (i=0; i<playerCount; i++)
  {
    printReceipt(bets, i, gameCount);
  }
  
}

// Prints player balance after the game, and prompts user to quit or play again
int nextGame(int gameCount, float bets[2][MAX_PLAYERS], int playerCount) 
{
  int choice, gameStatus, i, check;
  printf("\n\nGame %d complete:\n\n", gameCount); 
  
  for (i=0; i<playerCount; i++)
  {
    printf("\nPlayer %d's balance: $%.2f", i+1, bets[1][i]);
  }
  
  do
  {
    printf("\n\nSelect an option below:\n");
    printf("1)Play again\n2)Quit\nEnter choice here: ");
    check = scanf("%d", &choice);
    
    if (check != 1) // checking for invalid inputs
    {
      printf("Please enter a valid number:\n");
      while (getchar() != '\n');
    }
    
    else if (choice != 1 && choice != 2) 
        {
            printf("Invalid choice! Please enter 1 to play again or 2 to quit.\n");
        }
  }
  
  while (check != 1 || (choice != 1 && choice != 2));
  
  if (choice == 1) // go again
  {
    gameStatus = 1;
  }
  
  if (choice == 2) // quit game
  {
    gameStatus = 0;
  }
  
  return gameStatus;
}     