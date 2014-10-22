//Programmer: LOUIE BERTONCIN       Date: 10/22/2014
//File: lab08_functions.cpp         Class: CS 1580, Section D
//Purpose: Function definitions for Dice Rolling game

#include <iostream>
#include <cstdlib>
#include "lab08.h"

using namespace std;

void greeting()
{
  cout << "\n\nWelcome to the Dice Game!!\n\n" << endl;

  return;
}

Player createPlayer()
{
  Player activePlayer;

  cout << "Please enter a player's name: ";
  cin >> activePlayer.name;

  return activePlayer;
}

void rollDice(int rnd[], const int & size)
{
  for(int i = 0; i < size; i++)
    rnd[i] = rand()%(DICEMAX+1-DICEMIN)+DICEMIN;

  return;
}

void calculatePoints(int rolls[][NUMROLLS], const int & size, int totScores[],
  const int & playerIndex)
{
  int score = 0;

  for(int i = 0; i < size; i++)
    for (int j = 0; j < NUMROLLS; j++)
      if(rolls[i][j] == i+1)
        score += SUCCESSPOINTS;

  totScores[playerIndex] = score;

  return;
}

int determineWinner(const int totScores[], const int & size)
{
  int index = 0, temp = totScores[0];

  for(int i = 0; i < size; i++)
  {
    if(totScores[i] > temp)
    {
      temp = totScores[i];
      index = i;
    }
  }

  return index;
}

void printResults(const int & index, const int & size, const Player players[],
  const int totScores[])
{
  cout << endl;
  for(int i = 0; i < NUMPLAYERS; i++)
  {
    Player currentPlayer = players[i];
    cout << currentPlayer.name << ":" << endl;
    cout << "(round #: ";
    for(int j = 0; j < NUMROLLS; j++)
      cout << "roll" << j+1 << ", ";
    cout << ":: round score)\n" << endl;
    for(int j = 0; j < NUMROUNDS; j++)
    {
      int roundTotal = 0;
      cout << j + 1 << ": ";
      for(int k = 0; k < NUMROLLS; k++)
      {
        cout << currentPlayer.rounds[j][k] << ", ";
        if(currentPlayer.rounds[j][k] == j + 1)
          roundTotal += SUCCESSPOINTS;
      }
      cout << ":: " << roundTotal << endl << endl;
    }
    cout << currentPlayer.name << "'s total score is " << totScores[i] << endl
      << endl;
  }
  cout << endl << endl << endl;

  cout << players[index].name << " wins!!\n" << endl << endl;

  return;
}

bool playAgain()
{
  bool response = false;

  cout << "Want to play again? (1 = yes, 0 = no) ";
  cin >> response;

  return response;
}

void goodbye()
{
  cout << "\n\nThanks for playing!!!";

  return;
}
