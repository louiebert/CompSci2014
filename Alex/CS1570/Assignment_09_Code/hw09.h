// Programmer: ALEX SHAW                   Date: 11-16-14
// File: hw09.cpp                          Class: CS1570 Section B
// Purpose: This file contains any global constants and non-member functions
// needed for the driver that creates objects of the classes that simulate
// x-ray machines, hospital rooms, and patients for the purpose of testing
// their member functions and member vars.

#ifndef HW09_H
#define HW09_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

//----------------------------Global Constants-------------------------------//
const float CHARGE = 550.00;
const int INIT_USES = 0;
const float INIT_SCHRAUT = 10.0;
const float MIN_MONEY = 0.00;               //Range of money patient might
const float MAX_MONEY = 4000.00;           // start with
const int MIN_CONDITION = 0;                  //Range representing patient's
const int MAX_CONDITION = 100;                // health
const int APPLY_RANGE = 10;             //Determines if x-ray harms patient
const int APPLY_CHANGE = 2;              //Factor patient's health decreases
const int MAX_TRIES = 4;                //Number of tries to connect to file
const int MAX_TESTS = 5;                //Times to "test" patient
const string NAMES_FILE = "names.dat";         //File that holds names


//---------------------Non-member function prototypes------------------------//
// open_connection() opens and tests a connection to a data file.
// Pre: Data file must have same name as the value stored in the var holding
//  the data file name. Var holding name must be string type.
// Post: Connects to specified data file or exits program if unable to connect.
template <typename T>
void open_connection(T & the_stream, const string & filename);

// random_num() selects a random number in the range between (and inclusive
//  of) parameters min and max.
// Pre: rand() must be seeded.
// Post: Returns a random number in the range between (and inclusive of)
//  parameters min and max.
int random_num(const int min = 0, const int max = 100);

// num_el() determines how many data elements are in a data file.
// Pre: File stream must be connected to file.
// Post: Returns the number of elements in data file.
int num_el(ifstream & fin);

#endif
