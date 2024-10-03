#include "nonstandarddeck.h"

NonStandardDeck :: NonStandardDeck() {
//size of deck is dependent on weirddeck
//all go up except the functions only used by non stand
//the virtual funtions are the ones used by both that use different variables
  readCards();
  //size of deck??????????


  }



NonStandardDeck :: ~NonStandardDeck() {
  delete [] deck;

  }

  void NonStandardDeck :: readCards() {
    int suitVal3;
    int faceVal3;
    string faceValstr;
    string suitValstr;
    string maxstr;

    ifstream infile;
    cout << "read" << endl;
    infile.open("weirddeck.txt");

    if(!infile) {
      cout << "weirddeck.txt not opened" << endl;
    }// end if
    infile >> maxstr;
    maxCards = stoi(maxstr);
    deck = new Card[maxCards];
    cout << maxCards << endl;

    for(int i = 0; i < maxCards; i++) {
      infile >> faceValstr;
      infile >> suitValstr;
      suitVal3 = stoi(suitValstr);
      faceVal3 = stoi(faceValstr);
      deck[i] = Card(suitVal3,faceVal3);
    }
    infile.close();
    numCards = maxCards;
  }


  bool NonStandardDeck::isEmpty() {
    if(numCards == 0) // it is compared with 2 equal signs
      return true;
    if(numCards != 0)
      return false;
    }//end isEmpty

  int NonStandardDeck::getNumCards() {
      return numCards;
    }//end getNumCards

  Card NonStandardDeck::displayCard(int i) {
      return deck[i];
    }//end displayCard

  void NonStandardDeck::printDeck() {
    for(int i = 1; i < numCards-1; i++)
      cout << deck[i].print() << endl;
    }//end printDeck

    bool NonStandardDeck::addCard(Card c) {

  if(numCards < maxCards) {
    deck[numCards] = c;
    numCards++;
      return true;
}
else
  return false;
}//end addCard

Card NonStandardDeck::dealCard() {
  return deck[numCards--];

}// end dealCard

void NonStandardDeck::shuffle() {
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

bool NonStandardDeck::mergeDecks(NonStandardDeck &deck2,bool doShuffle) {
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
