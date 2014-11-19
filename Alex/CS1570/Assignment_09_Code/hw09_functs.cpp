// Programmer: ALEX SHAW                   Date: 11-16-14
// File: hw09_functs.cpp                   Class: CS1570 Section B
// Purpose: This file contains the non-member functions for the driver
// that creates objects of the classes that simulate x-ray machines,
// hospital rooms, and patients for the purpose of testing their member
// functions and member vars.

#include "x_rayer.h"
#include "hospital_room.h"
#include "patient.h"
#include "hw09.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

float random_num(const float min, const float max)
{
  return (min + rand() % (max + 1 - min));
}

template <typename T>
void open_connection(T & the_stream, const string & filename)
{
  the_stream.open(filename.c_str());      //Attempt to connect to data file
  int counter = 0;
  while(!the_stream && counter < MAX_TRIES)      //Test connection
  {
    the_stream.clear();
    the_stream.open(filename.c_str());
    counter++;
  }
  if(!the_stream)                          //Exit if unable to connect
  {
    cout << "Error: Unable to connect to " << filename << "."
         << "Exiting program." << endl;
    exit(1);
  }
}

int num_el(ifstream & fin)
{
  int total_el = 0;
  char next;
  while(fin >> next)
  {
    total_el++;
  }
  return total_el;
}
