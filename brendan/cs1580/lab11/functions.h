// Programmer: Brendan Curran              Date: 11/12/2014
// File: speedRecorder.h                   Class: CS 1580 Sec D
// Description: prototypes functions for the main lab11 program
#include "speedRecorder.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Description: continually adds speeds to company from user input
//calculates total speed, number of entries, and average
//Pre: speedRecorder company passed by reference
//Post: total speed, number of entries, and average will be calculated
//as user enters values
void enterSpeeds (speedRecorder & company);

//Description: Displays info about the company, id, number of entires
//and average speed
//Pre: speedRecorder class filled with data by user
//Post: prints information to screen
void displayInfo (const speedRecorder & company);

#endif