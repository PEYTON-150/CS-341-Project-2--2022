#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

// The Card class is an object that represents a single card in from a standard deck of cards.
// It is mainly used to store and print the contents of a card. It also allows you to initialize in two ways:
// 1) via the initialize function (that sets both values at once), and
// 2) via a non-default constructor, if you happen to want to do it when you declare a Card instance

class Card {
	private:
        int suitVal;				// contains the index of the suit array that corresponds to the suit of the card
		int faceVal;				// contains the index of the face array that corresponds to the face of the card
		static string suitArr[5];
		static string faceArr[14];

	public:
		// Constructors/Destructors
        Card();						// default constructor
        Card(int, int);				// non-default constructor that sets the value of suit and face
        ~Card();					// default destructor

		// Get/Set functions
		  string getSuit();			// returns the string corresponding to the suit of the card
		  string getFace();			// returns the string corresponding to the face of the card
		
        // Core functionality
		string print();				// returns a string with the full name of the card, e.g. "Ace of Spades"
        void initialize(int, int);  // sets the value of suitVal and faceVal, suit is first then face
};

#endif
