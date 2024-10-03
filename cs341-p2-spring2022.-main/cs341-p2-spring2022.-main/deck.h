#ifndef Deck_h
#define Deck_h

#include <iostream>
using namespace std;
#include "card.h"
//leave normal funtions normal
//unique functions to the class  are virtual

  class Deck {

  protected:
    Card *deck;								// pointer to record the location of the array of cards in memory
    int numCards;							// stores the number of cards currently in the deck

  public:
    Deck();
    ~Deck();
    //get/set functions
    bool isEmpty();							// returns whether or not the deck is empty
    int getNumCards();						// returns the number of cards remaining in the deck
    Card displayCard(int i);				// displays the ith card of the deck
    void printDeck();             //prints out the deck


    virtual bool addCard(Card c);					// add c to the end of the deck if there is space, fail otherwise
    Card dealCard();						// deal the top card (largest valid index) of the deck -- remove it from the deck, and return it.
    void shuffle();							// Shuffles the deck of cards by performing at least 3*numCards random swaps (random sort from 248!)
    bool mergeDecks(Deck &, bool);	// add cards from input to this deck, then empty the input deck. bool for shuffle afterwards (default = false)




};
#endif
