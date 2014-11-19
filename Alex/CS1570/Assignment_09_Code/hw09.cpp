// Programmer: ALEX SHAW                   Date: 11-16-14
// File: hw09.cpp                          Class: CS1570 Section B
// Purpose: This file contains the driver that creates objects of the classes
// that simulate x-ray machines, hospital rooms, and patients for the purpose
// of testing their member functions and member vars.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include "hospital_room.h"
#include "patient.h"
#include "hw09.h"

using namespace std;
int main()
{
  x_rayer x;
  hospital_room h_room;
  patient p1;
  patient p2;
  patient p3;

  srand(time(NULL));
  cout.setf(ios::fixed);                    //Display two dec places for prices
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "\tHospital Simulator 3000" << endl;
  cout << "\nInitial status:" << endl;

  cout << "Hospital room:" << endl;                //Display object data members
  cout << h_room;
  cout << p1;
  cout << p2;
  cout << p3;

  int i = 0;
  while(i < MAX_TESTS && p1.get_condition())
  {
    h_room.admit(p1);
    i++;
  }

  cout << "\nFinal status:" << endl;

  cout << "Hospital room:" << endl;                //Display data members
  cout << h_room;


  cout << p1;


  cout << p2;


  cout << p3;

  return 0;
}
