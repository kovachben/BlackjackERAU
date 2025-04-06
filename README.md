# BlackjackERAU
CS125 Group Project

HOW TO DOWNLOAD AND START
- Download ERAU_BLACKJACK Zip File or download the following files directly from the repository:
  - blackjack.h; game.c; actions.c; dealer.c; deck.c; payout.c; playerhand.c; Makefile.txt; receipt.txt
- Create a new directory for the game and enter it
- Upload downloaded files into the new directory
- Rename Makefile.txt to just Makefile
- Run make file by typing "make"
- Type the executable "Blackjack" and the program begins

Gameplay Rules: 

Goal: 
- Have a hand value closer to 21 than the dealer's hand without going over 21. 
- If your hand goes over 21, you lose automatically (“Bust”).

Dealing: Each player and the dealer get two cards.
- Players' cards are face-up.
- The dealer has one face-up card and one face-down card (denoted by ???)

Player's Turn: Perform an action.
- Hit: Draw a card to increase the total value of your hand.  
- Stand: Keep the current hand.
- Double Down: Double your bet and take only one more card.
- Split: double your bet and split two equal cards into two hands.

Dealer's Turn: 
- Once all players finish their turn, the dealer reveals the face down card.
- The dealer must hit if their hand is below 17 and must stand if it’s above 17.
- If the dealer “busts,” all remaining players win.

Card Values: 
- Number cards (2-10): Face value (a 3 is worth 3 points).
- Face cards (Jack, Queen, King): 10 points each.
- Aces: Worth either 1 or 11 points, depending on what's best for your hand 



