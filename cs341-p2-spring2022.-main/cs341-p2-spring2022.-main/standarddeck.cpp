#include "standarddeck.h"

StandardDeck::StandardDeck() {
srand(time(0));
deck = new Card[52];
numCards = 0;
for(int i = 1; i < 14; i++)
{
  for(int j = 1; j < 5; j++)
  {
    addCard(Card(j,i));
  }
}
}//end default Constructors
StandardDeck::StandardDeck(int nofill) {
  deck = new Card[52];
  numCards = 0;
}
StandardDeck::~StandardDeck() {
delete [] deck;
}// end default deconstructor

bool StandardDeck::isEmpty() {
  if(numCards == 0) // it is compared with 2 equal signs
    return true;
    if(numCards != 0)
    return false;
}//end isEmpty

int StandardDeck::getNumCards() {
  return numCards;
}//end getNumCards

Card StandardDeck::displayCard(int i) {
  return deck[i];
}//end displayCard

void StandardDeck::printDeck() {
  for(int i = 1; i < numCards-1; i++)
    cout << deck[i].print() << endl;
}//end printDeck

bool StandardDeck::addCard(Card c) {
  if(numCards < 52) {
    deck[numCards] = c;
    numCards++;
      return true;
}
else
  return false;
}//end addCard

Card StandardDeck::dealCard() {
  return deck[numCards--];

}// end dealCard

void StandardDeck::shuffle() {
srand(time(0));
  Card tempcard;
  Card card1;
  Card card2;
  for(int i = 0; i < 3; i++)
{
  for(int p = 1; p < numCards-1; p++)
  {
int rando = rand()% (numCards-1)+1;
    card1 = deck[rando];
    deck[rando] = deck[p];
    deck[p] = card1;
  }
  }

}//end shuffle

bool StandardDeck::mergeDecks(StandardDeck &deck2,bool doShuffle) {
  int otherNum = numCards;
  numCards += deck2.getNumCards();

  for(int i = 0; i < deck2.getNumCards();) {
    deck[otherNum + i ] = deck2.dealCard();
  }


  if(doShuffle)
  {
    shuffle();
    return true;
  }
return false;
}//end mergeDecks
