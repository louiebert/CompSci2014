//Programmer: LOUIE BERTONCIN       Date: 10/22/2014
//File: lab08.cpp                   Class: CS 1580, Section D
//Purpose: Main file for Dice Rolling game

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lab08.h"

using namespace std;

int main()
{
  Player players[NUMPLAYERS];
  int totalScores[NUMPLAYERS];

  srand(time(NULL));

  greeting();

  do
  {
    for(int i = 0; i < NUMPLAYERS; i++)
    {
      players[i] = createPlayer();
      for(int j = 0; j < NUMROUNDS; j++)
        rollDice(players[i].rounds[j], NUMROLLS);
      calculatePoints (players[i].rounds, NUMROUNDS, totalScores, i);
    }

    printResults(determineWinner(totalScores, NUMPLAYERS), NUMPLAYERS, players,
      totalScores);

  }while(playAgain());

  goodbye();

  return 0;
}
