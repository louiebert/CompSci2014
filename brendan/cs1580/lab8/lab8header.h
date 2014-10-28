// Programmer: Brendan Curran              Date: 10/22/2014
// File: lab8header.h                      Class: CS 1580 Sec D
// Description: declares constants for the number of players
// and the number of rounds, which can be changed to affect
// the entire program, and prototypes functions that will be used
// in the program

#ifndef LAB8HEADER_H
#define LAB8HEADER_H

const int numPlayers = 2;
const int numRounds = 6;

struct diceRoll
{
  int m_roll1;
  int m_roll2;
  int m_roll3;
};

//Description: Generates three random numbers 1-6 and assigns them in 
//diceroll struct
//Pre: diceRoll passed by reference
//Post: diceRoll rolls are assigned random values 1-6
void rollTheDice(diceRoll & d);

//Description: calculates the number of points from a roll in a round 
//a point is earned if a roll of a dice is equal to the number of the round
//Pre: parameter diceroll, with three values 1-6 in it, integer parameter
//for the round number
//Post: returns the number of points accumlated
int calculatePoints(const diceRoll d, const int round);

//Description: prints out the information for a round
//Pre: current diceRoll, integer points earned, and integer round number
//Post: outputs the round, the rolls, and the points earned
void printRound(const diceRoll d, const int score, const int round);

//Description: prints out the result of the game, either a player wins or it 
//is a tie
//Pre: a completed score array must be sent, integer scores for each player
//Post: outputs on the screen the winner, or that it was a tie
void gameResult(const int PlayerScore[]);
#endif