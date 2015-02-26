// Programmer: Brendan Curran              Date: 10/22/2014
// File: lab8main.cpp                      Class: CS 1580 Sec D
// Description: executes the game for the specified number of players
// and loops as long as the user wants to play again

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lab8header.h"
using namespace std;

int main()
{
  diceRoll roll[numRounds];
  int playerScore[numPlayers];
  int roundScore;
  char choice;
  bool again = true;
  
  srand(time(NULL));
  
  while (again)
  {
    
    for (int j = 0; j<numPlayers; j++)
    {
      cout << "Player "<< j+1 << ": (round#: roll1, roll2, roll3 (score))"";
      cout << endl;
      playerScore[j] = 0;
      for (int i = 0;  i < 6; i++)
      {
        rollTheDice(roll[i]);
        roundScore = calculatePoints(roll[i], i+1);
        printRound(roll[i], roundScore, i+1);
        playerScore[j] += roundScore;
      }    
    }
    gameResult(playerScore);
    cout << "Would you like to play again? (y/n): ";
    cin >> choice;
    if (choice != 'y')
      again = false;
  }
 
  return 0;
}