#include <iostream>
#include <fstream>
#include "card.h"
#include "nonstandarddeck.h"
#include "deck.h"
using namespace std;

int main() {
    int round = 0;
    cout <<" before " <<endl;
    NonStandardDeck battleGrounds; // battleGrounds deck
    cout << " cards in battle " << battleGrounds.getNumCards() << endl;
    NonStandardDeck p1; // player 1 deck
    NonStandardDeck p2; // player 2 deck
    cout<<p2.getNumCards() << endl;
    cout<<p1.getNumCards() << endl;
    cout << " after " <<endl;
    int p1Wins = 0; // p1 total round wins in a game
    int p2Wins = 0;// p2 total round wins in a game
    double averageScorep1 = 0.0; // average score of player 1 in 50 games
    double averageScorep2 = 0.0; // average score of player 2 in 50 games
    int p1Score = 0; // score of player 1 in a game
    int p2Score = 0; // score of player 2 in a game
    double averageCardsleft = 0.0;
    int numGames = 1;
//put 52 in battleGrounds shuffle and then deal 26 to each
while(p2.getNumCards() > 0) {
  p2.dealCard();

}
while(p1.getNumCards() > 0) {
  p1.dealCard();

}

  for(int gam = 0; gam < numGames; gam++) {//game starts
    round = 0;

   while (p2.getNumCards() > 0) {
      battleGrounds.addCard(p2.dealCard());
    }
    while (p1.getNumCards() > 0) {
      battleGrounds.addCard(p1.dealCard());
    }




      battleGrounds.shuffle();
      cout << " some cards " << battleGrounds.getNumCards() << endl;
      for(int i = 0; i < battleGrounds.getNumCards()/2; i++) {
        p1.addCard(battleGrounds.dealCard());

      }
      for(int i = 0; i < battleGrounds.getNumCards()/2; i++) {
        p2.addCard(battleGrounds.dealCard());

      }
      if(battleGrounds.getNumCards() != 0)
      {
        p1.addCard(battleGrounds.dealCard());
      }
      p1.shuffle();
      p2.shuffle();
      cout << " some cards " << p1.getNumCards() << endl;
      cout << " some cards " << p2.getNumCards() << endl;
      while(round == 0) {
        cout << " start of round " << endl;

      battleGrounds.addCard(p1.dealCard());//player 1 places a card down
      cout << " battle " << battleGrounds.getNumCards() << endl;

      if(battleGrounds.displayCard(battleGrounds.getNumCards()).getFace() == battleGrounds.displayCard(battleGrounds.getNumCards()-1).getFace() && battleGrounds.getNumCards() > 1) {
        p1.mergeDecks(battleGrounds,true);
        cout << " player 1 wins the round " << endl;
      }//player one wins a round adds the cards to the deck


      if(p1.isEmpty() == true) {
        round = 100;
        p2Score = p2.getNumCards();
        p2Wins++;
        averageCardsleft = averageCardsleft + battleGrounds.getNumCards();
      //  cout << "game over!!!" << endl;



      }//end of check
      battleGrounds.addCard(p2.dealCard());

      if(battleGrounds.displayCard(battleGrounds.getNumCards()).getFace() == battleGrounds.displayCard(battleGrounds.getNumCards()-1).getFace() && battleGrounds.getNumCards() > 1) {
        p2.mergeDecks(battleGrounds,true);
        cout << " player 2 wins the round " << endl;
      }//player two wins a round




      if(p2.isEmpty() == true) {
        round = 100;
        p1Score = p1.getNumCards();
        p1Wins++;
        averageCardsleft = averageCardsleft + battleGrounds.getNumCards();
      //  cout << " gameover!!! " << endl;


      }//end of check

      cout << p1.getNumCards() << " player 1 carsd " << endl;

      cout << p2.getNumCards() << " player 2 cards " << endl;

    }//end game

    averageScorep1 += p1Score;
    averageScorep2 += p2Score;

  }//end of 50 games

  averageScorep1 = averageScorep1 / numGames;
  averageScorep2 = averageScorep2 / numGames;
  averageCardsleft = averageCardsleft / numGames;
  cout << " the average cards left in the battleGrounds is: " << averageCardsleft << endl;
  cout << " the average score of player 1 is:  " << averageScorep1 << endl;
  cout << " the average score of player 2 is:  " << averageScorep2 << endl;

  if(p1Wins<p2Wins) {
    cout << "player 2 wins more with: " << p2Wins << " wins " << endl;
    cout << " player 1 only had: " << p1Wins << " wins " << endl;
  }
  else if(p1Wins>p2Wins) {
    cout << "player 1 wins more with: " << p1Wins << " wins " << endl;
    cout << " player 2 only had: " << p2Wins << " wins " << endl;
}
  else if(p1Wins == p2Wins) {
    cout << " they tied #boring" << endl;
  }

  if(averageScorep1>averageScorep2) {
    cout << "player 1's average more with: " << averageScorep1 << " score " << endl;
  }
  else if(averageScorep1<averageScorep2) {
    cout << "player 2's average more with: " << averageScorep2 << " score " << endl;

  }
  return 0;
}//end driver class
