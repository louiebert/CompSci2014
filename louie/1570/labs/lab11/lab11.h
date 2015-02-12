//Programmer: LOUIE BERTONCIN     Date: 11/11/2014
//File: lab11.h                   Class: CS 1580, Section D
//Purpose: Header file for OOP lab.

#ifndef LAB11_H
#define LAB11_H

#include "Speed_recorder.h"

using namespace std;

// greeting() outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// make_speed_recorder() prompts user for elements to construct a speed
//   recorder, then returns the created speed record.
// Pre: None
// Post: Returns a user-created Speed_recorder object.
Speed_recorder make_speed_recorder();

// summary() prints a company summary to the console.
// Pre: spd_rcrd needs to be a created Speed_recorder object.
// Post: Prints a company summary to the console.
void summary(const Speed_recorder & spd_rcrd);

// add_speeds() prompts user if they'd like to add more speeds to a
//   Speed_recorder object and returns their boolean answer.
// Pre: None
// Post: Returns the user's boolean input.
bool add_speeds();

// more_speeds() prompts the user for more speeds to add to the existing
//   Speed_recorder object.
// Pre: spd_rcrd needs to be a created Speed_recorder object.
// Post: Adds more speeds to the Speed_recorder object from user input.
void more_speeds(Speed_recorder & spd_rcrd);

// again() prompts user to run the program again. Returns true if yes.
// Pre: None
// Post: Returns true or false based on user input.
bool again();

// goodbye() prints a farewell to the console.
// Pre: None
// Post: Prints a message to the console
void goodbye();

#endif
