#include "deck.h"

Deck::Deck() {
srand(time(0));
deck = new Card[52];
numCards = 0;
}//end default Constructors

Deck::~Deck() {
delete [] deck;
}// end default deconstructor

bool Deck::isEmpty() {
  if(numCards == 0) // it is compared with 2 equal signs
    return true;
    if(numCards != 0)
    return false;
}//end isEmpty

int Deck::getNumCards() {
  return numCards;
}//end getNumCards

Card Deck::displayCard(int i) {
  return deck[i];
}//end displayCard

void Deck::printDeck() {
  for(int i = 1; i < numCards-1; i++)
    cout << deck[i].print() << endl;
}//end printDeck

bool Deck::addCard(Card c) {
  if(numCards < 52) {
    deck[numCards] = c;
    numCards++;
      return true;
}
else
  return false;
}//end addCard

Card Deck::dealCard() {
  return deck[numCards--];

}// end dealCard

void Deck::shuffle() {
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

bool Deck::mergeDecks(Deck &deck2,bool doShuffle) {
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
