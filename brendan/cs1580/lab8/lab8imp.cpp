// Programmer: Brendan Curran              Date: 10/22/2014
// File: lab8imp.cpp                       Class: CS 1580 Sec D
// Description: contains the implementations of functions declared in 
// the header file

#include <iostream>
#include <cstdlib>
#include "lab8header.h"
using namespace std;

void rollTheDice(diceRoll & d)
{
  d.m_roll1 = rand()%6+1;
  d.m_roll2 = rand()%6+1;
  d.m_roll3 = rand()%6+1;
}

int calculatePoints(const diceRoll d, const int round)
{
  int points = 0;
  if (d.m_roll1 == round)
    points++;
  if (d.m_roll2 == round)
    points++;
  if (d.m_roll3 == round)
    points++;
  return points;
}

void printRound(const diceRoll d, const int score, const int round)
{
  cout << round << ": " << d.m_roll1 << ", " << d.m_roll2 << ", ";
  cout << d.m_roll3 << "(" << score << ")"" << endl;
}

void gameResult(const int PlayerScore[numPlayers])
{
  int highScore = -1, winningPlayer;
  bool tieIndicator;
  
  for (int i = 0; i < numPlayers; i++)
  {
    cout << "player " << i+1 << " score = " << PlayerScore[i] << endl;
  }
  
  for (int i = 0; i < numPlayers; i++)
  {
    if (PlayerScore[i] > highScore)
    {
      highScore = PlayerScore[i];
      winningPlayer = i+1;
      tieIndicator = false;
    }
    else if (PlayerScore[i] == highScore)
      tieIndicator = true;
  }
  if (tieIndicator)
    cout << "It's a tie" << endl;
  else
    cout << "player " << winningPlayer << " wins!" << endl;
}