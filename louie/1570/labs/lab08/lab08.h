//Programmer: LOUIE BERTONCIN       Date: 10/22/2014
//File: lab08.h                     Class: CS 1580, Section D
//Purpose: Header file for Dice Rolling game

#ifndef LAB8_H
#define LAB8_H

using namespace std;

const int NUMPLAYERS = 2;
const int NUMROUNDS = 6;
const int NUMROLLS = 3;
const int DICEMIN = 1;
const int DICEMAX = 6;
const int SUCCESSPOINTS = 1;

struct Player
{
  string name;
  int rounds[NUMROUNDS][NUMROLLS];
};

// The greeting() function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// createPlayer() prompts user to provide a player's name and returns a Player.
// Pre: none
// Post: returns a Player with a name property filled in
Player createPlayer();

// rollDice() generates a number (size) of random numbers between DICEMIN and
//   DICEMAX and inserts them into the rnd[] array.
// Pre: int size is the size of the rnd[] array
// Post: rnd[] is filled with a number (size) of random numbers
void rollDice(int rnd[], const int & size);

// calculatePoints() puts the number of points that the player earned into the
//   player's index in the total scores array.
// Pre: int size is the size of the rolls[] array and playerIndex is the index
//   of the player in the totScores[] array
// Post: Adds a player's score to the total scores array
void calculatePoints(int rolls[][NUMROLLS], const int & size, int totScores[],
  const int & playerIndex);

// determineWinner() takes in the total scores array and returns the index of
//   the highest number.
// Pre: int size is the size of totScores[] array
// Post: Returns index of highest score
int determineWinner(const int totScores[], const int & size);

// printResults() takes the index of the winner and prints the results to the
//   console.
// Pre: Index is the index of the highest score in totScores[] and the winner in
//   players[]. int size is the size of both players[] and totScores[].
// Post: Prints results of the game
void printResults(const int & index, const int & size, const Player players[],
  const int totScores[]);

// playAgain() prompts user to play again. Returns true if yes.
// Pre: none
// Post: Returns true or false based on user input.
bool playAgain();

// The goodbye() function prints a farewell to the console.
// Pre: None
// Post: Prints a message to the console
void goodbye();

#endif
