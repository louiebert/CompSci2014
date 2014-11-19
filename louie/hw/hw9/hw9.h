//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hw9.h                     Class: CS 1570, Section D
//Purpose: Header file for hospital tour program

#ifndef H7_H
#define H7_H

using namespace std;

const int DEF_NUM_USES = 0;
const float DEF_COST_OF_USE = 550;
const float DEF_OZ_OF_DRINK = 10.0;
const string NAMES_FILE = "names.dat";

// The greeting() function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// The << operator for the X_rayer class prints an X_rayer object.
// Pre: The ostream must be opened already and x_ray must have all its
//   properties existing.
// Post: Prints the X_rayer object through the given ostream object.
ostream & operator << (ostream & out, const X_rayer & x_ray);

// The << operator for the Patient class prints an Patient object.
// Pre: The ostream must be opened already and ptnt must have all its
//   properties existing.
// Post: Prints the Patient object through the given ostream object.
ostream & operator << (ostream & out, const Patient & ptnt);

// The << operator for the Hospital_room class prints an Hospital_room object.
// Pre: The ostream must be opened already and room must have all its
//   properties existing.
// Post: Prints the Hospital_room object through the given ostream object.
ostream & operator << (ostream & out, const Hospital_room & room);

#endif


