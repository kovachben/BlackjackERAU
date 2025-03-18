#ifndef blackjack.h
#define blackjack.h

struct deck
{
  int bjValue;
  char card[50];
  char suit[50];
  int drawn;
};

struct deck createDeck();



#endif