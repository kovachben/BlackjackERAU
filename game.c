#include <stdio.h>
#include "blackjack.h"
#include <stdlib.h>
/*
  Author: Ben Kovach, Sophia Noriega
  References: Geeks for Geeks - getchar
*/

int main()
{
  int playerCount, i;
  int dealerValue;
  int totalValue[MAX_PLAYERS];
  struct deck Deck[52];
  float bets[2][MAX_PLAYERS]; // One row for current bet, one row for total
  int splitHand[12]; // Size allows all players to split
  int splitCheck[MAX_PLAYERS];
  int check = 0; 
  int gameCount = 0;
  int dealerBlackjack;
  
  printf("|----- Welcome to Blackjack -----|");
  printf("\n\n\nHow many players are there (1-4)?");
  printf("\nEnter number here: ");
  
	while (check != 1) //Ensuring valid input
  {  
    if (scanf("%d", &playerCount) != 1)
    { 
      printf("Please enter a number between 1 and 4: "); 
      while(getchar() != '\n');
    } 
    
		else if (playerCount < 1 || playerCount > MAX_PLAYERS)
    {
      printf("Please enter a number between 1 and 4: "); 
    }
    
		else
    {
      check = 1; 
    } 
  }
 
  initializeMoney(bets, playerCount);
  int gameStatus = 1;
  
	// General game flow
	while (gameStatus == 1)
  {
    dealerBlackjack = resetGame(splitCheck, splitHand, playerCount, dealerBlackjack);
    gameCount++;
    placeBets(bets, playerCount);
    fillDeck(Deck);
    dealerInitial(Deck);
    drawInitial(Deck, playerCount);
    handValueCalculatorAll(totalValue, Deck, playerCount);
    playerPrompt(totalValue, playerCount, Deck, bets, splitHand, splitCheck);
    dealerBlackjack = dealerAction(Deck, dealerValue, dealerBlackjack);
    dealerValue = dealerCalculator(Deck, dealerValue);
    gameEnd(totalValue, bets, dealerValue, playerCount, splitHand, splitCheck, gameCount, Deck, dealerBlackjack);
    gameStatus = nextGame(gameCount, bets, playerCount);
  }
  
	return 0;
}