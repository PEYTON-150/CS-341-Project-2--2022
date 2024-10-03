The focus of this project is on creating a card game (a simplified version of "War") using object-oriented programming, inheritance, polymorphism, and good software engineering practices. You are expected to use classes, virtual functions, and handle dynamic memory allocation responsibly.

Phase 1 - Implementing the Card Class (5 points):
Complete the Card class, similar to the previous project (Pirate class).
Create an array of 52 cards and print them to confirm correct implementation.

Phase 2 - Building the StandardDeck Class (5 points):
Implement the StandardDeck class.
Use dynamic memory allocation (new and delete) to store and manage a deck of 52 cards.
Write the necessary getter/setter functions.

Phase 3 - Implement Core Deck Functionality (5 points):
Implement core deck functionalities like adding and dealing cards, as well as shuffling.
Reuse helper functions from earlier projects where possible.
Properly test that all these functions work.

Phase 4 - Create a Simplified War Game (5 points):
Build a driver program to simulate a simplified version of the card game "War".
Play the game 50 times, and return statistics on wins, average scores, and leftover cards.

Phase 5 - Introduce Inheritance and Virtual Deck Class (5 points):
Create a base class Deck and derive StandardDeck from it.
Add another derived class NonStandardDeck, which reads a deck of cards from a text file (weirddeck.txt).

Phase 6 - Implement NonStandardDeck (5 points):
Implement the NonStandardDeck class to read from an input file.
Ensure it works correctly with your Simplified War game.
