#include <stdio.h>
#include "blackjack.h"
/*
   File : playerhand.c
   Author: Sophia Noriega, Ben Kovach
   Assignment: Deck
   Date: 03/19/2025
   References: getchar - Stack Overflow
*/

void splitGameEnd(float bets[2][MAX_PLAYERS], int dealerValue, int playerNumber, int splitHand[], int splitCheck[], int splitNumber)
{
  int i;
  int j=0;
  for (i=splitNumber; i<splitNumber+2; i++)
  {
    j++;
    if (splitHand[i] > dealerValue && splitHand[i] <= 21 || dealerValue > 21 && splitHand[i] == 21)
    {
     	 if (splitHand[i] == 21)
       {
       		printf("\n\nBlackjack for player %d, in hand %d! You win $%.2f", playerNumber+1, j, (bets[0][playerNumber] / 2) * 1.5);
          bets[1][playerNumber] = bets[1][playerNumber] + 1.5 * (bets[0][playerNumber] / 2);
          continue;  
       }
       else
       {
          printf("\n\nCongratulations player %d! Hand %d wins $%.2f", playerNumber+1, j, bets[0][playerNumber] / 2);
          bets[1][playerNumber] = bets[1][playerNumber] + bets[0][playerNumber];
          continue;
       }
    }
    if (splitHand[i] == dealerValue)
    {
     	 printf("\n\nPush! Player 2, hand %d's bet of $%.2f is returned.", bets[0][playerNumber] / 2);
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
     	 printf("\n\nPlayer %d's hand %d looses. $%.2f lost.", playerNumber+1, bets[0][playerNumber] / 2);
       continue;
    }
  }
}
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
  fprintf(filePointer, "Game %d: Player %d's Balance: $%.2f\n", gameCount, playerNumber, bets[1][playerNumber]);
  fclose(filePointer);
  return;
}
void gameEnd(int totalValue[], float bets[2][MAX_PLAYERS], int dealerValue, int playerCount, int splitHand[], int splitCheck[], int gameCount)
{
  int i;
  int splitNumber = 5;
  for (i=0; i<playerCount; i++)
  {
   		if (splitCheck[i] == 0)
      {
       	 if (totalValue[i] > dealerValue && totalValue[i] <= 21 || dealerValue > 21 && totalValue[i] == 21)
         {
         		if (totalValue[i] == 21)
  			 		{
             	 printf("\n\nBlackjack for player %d! You win $%.2f", i+1, bets[0][i] * 1.5);
							 bets[1][i] = bets[1][i] + 1.5 * bets[0][i] + bets[0][i]; // confirm correct
            	 continue;
	 		 		  }
          	else
          	{
             		printf("\n\nCongratulations player %d! You win $%.2f", i+1, bets[0][i]);
            		bets[1][i] = bets[1][i] + 2 * bets[0][i];
            		continue;
            }
        }
        if (totalValue[i] == dealerValue)
        {
         	 printf("\n\nPush! Your bet of $%.2f is returned.", bets[0][i]);
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
      printReceipt(bets, i, gameCount);
  }
}

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