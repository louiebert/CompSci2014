//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: hw10_functs.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains function definitions for the non-member,  non-friend
// functions in the program that simulates a patient and a doctor visiting
// hospital rooms.

#include "hw10.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

short rand_num(const short min, const short max)
{
  return (min + rand() % (max + 1 - min));
}

string rand_name(const short num_names, ifstream& fin)
{
  string name;
  short counter = 1;      //Set to 1 because 1 name read before loop
  fin >> name;
  while(!fin.eof() && counter < num_names)     //Stops at end of file or at number
  {
    fin >> name;
    counter ++;
  }
  return name;
}

short count_el(ifstream& fin)
{
  short num_el = 0;
  string next;
  while(fin >> next)
  {
    num_el++;
  }
  return num_el;
}

/*template <class T>
void disp_status(const Doctor & d, const Patient patients[],
                 const Hospital<T> rooms[])
{
  cout << d;                                  //Display doctor
  for(int i = 0; i < NUM_PATIENTS; i++)           //Display patients
  {
    cout << patients[i];
  }
  for(int j = 0; j < NUM_ROOMS; j++)           //Display hospital rooms
  {
    cout << rooms[j];
  }
  return;
} */
