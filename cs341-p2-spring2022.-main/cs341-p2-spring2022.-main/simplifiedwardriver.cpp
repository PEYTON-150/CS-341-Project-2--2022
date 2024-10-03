#include <iostream>
#include <fstream>
#include "card.h"
#include "standarddeck.h"
using namespace std;

int main() {
    int round = 0;
    StandardDeck p1(0); // player 1 deck
    StandardDeck p2(0); // player 2 deck
    StandardDeck battleGround; // battleGround deck
    int p1Wins = 0; // p1 total round wins in a game
    int p2Wins = 0;// p2 total round wins in a game
    double averageScorep1 = 0.0; // average score of player 1 in 50 games
    double averageScorep2 = 0.0; // average score of player 2 in 50 games
    int p1Score = 0; // score of player 1 in a game
    int p2Score = 0; // score of player 2 in a game
    double averageCardsleft = 0.0;
    int numGames = 50;
//put 52 in battleGround shuffle and then deal 26 to each
  for(int gam = 0; gam < numGames; gam++) {
    round = 0;
    while (p2.getNumCards() > 0) {
      battleGround.addCard(p2.dealCard());
    }
    while (p1.getNumCards() > 0) {
      battleGround.addCard(p1.dealCard());
    }




      battleGround.shuffle();
      cout << " some cards " << battleGround.getNumCards() << endl;
      for(int i = 0; i < 26; i++) {
        p1.addCard(battleGround.dealCard());

      }
      for(int i = 0; i < 26; i++) {
        p2.addCard(battleGround.dealCard());

      }
      p1.shuffle();
      p2.shuffle();
      cout << " some cards " << p1.getNumCards() << endl;
      cout << " some cards " << p2.getNumCards() << endl;
      while(round == 0) {
        cout << " hy" << endl;

      battleGround.addCard(p1.dealCard());//player 1 places a card down
      cout << " battle " << battleGround.getNumCards() << endl;

      if(battleGround.displayCard(battleGround.getNumCards()).getFace() == battleGround.displayCard(battleGround.getNumCards()-1).getFace() && battleGround.getNumCards() > 1) {
        p1.mergeDecks(battleGround,true);
        cout << " player 1 wins the round " << endl;
      }//player one wins a round adds the cards to the deck


      if(p1.isEmpty() == true) {
        round = 100;
        p2Score = p2.getNumCards();
        p2Wins++;
        averageCardsleft = averageCardsleft + battleGround.getNumCards();
      //  cout << "game over!!!" << endl;



      }//end of check
      battleGround.addCard(p2.dealCard());

      if(battleGround.displayCard(battleGround.getNumCards()).getFace() == battleGround.displayCard(battleGround.getNumCards()-1).getFace() && battleGround.getNumCards() > 1) {
        p2.mergeDecks(battleGround,true);
        cout << " player 2 wins the round " << endl;
      }//player two wins a round




      if(p2.isEmpty() == true) {
        round = 100;
        p1Score = p1.getNumCards();
        p1Wins++;
        averageCardsleft = averageCardsleft + battleGround.getNumCards();
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
  cout << " the average cards left in the battleground is: " << averageCardsleft << endl;
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
