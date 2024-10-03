#include "card.h"

string Card::suitArr[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
string Card::faceArr[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card() {
int suitVal = 0;
int faceVal = 0;
}//end default constructor

Card::~Card() {

}//end default deconstructor

Card::Card(int suitVal2, int faceVal2 ) {
suitVal = suitVal2;
faceVal = faceVal2;
}//end constructor

string Card::getFace() {

  return faceArr[faceVal];
}//end getface

string Card::getSuit() {
  return suitArr[suitVal];
}//end get suit

string Card::print() {

  return getFace() + " " + getSuit();
}// ends print

void Card::initialize(int suitVal1,int faceVal1) {
  suitVal = suitVal1;
  faceVal = faceVal1;
}
