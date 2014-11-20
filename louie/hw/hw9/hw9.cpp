//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hw9.cpp                   Class: CS 1570, Section D
//Purpose: Main file for hospital tour program

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include "hospital_room.h"
#include "patient.h"
#include "x_rayer.h"

using namespace std;

const int ADMIT_COUNT = 5;

// greeting() outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// farewell() outputs a goodbye to the user.
// Pre: None
// Post: A goodbye string is printed to the console
void farewell();

int main()
{
  srand(time(NULL));

  greeting();

  Hospital_room myHospital;
  Patient patient1, patient2, patient3;

  cout << "HOSPITAL: " << myHospital << endl;
  cout << "PATIENT 1: " << patient1 << endl;
  cout << "PATIENT 2: " << patient2 << endl;
  cout << "PATIENT 3: " << patient3 << endl << endl;

  for(int i = 0; i < ADMIT_COUNT; i++)
  {
    myHospital.admit(patient1);
  }

  cout << "PATIENT 1 after being admitted " << ADMIT_COUNT << " times: \n\t"
    << patient1 << endl;

  farewell();

  return 0;
}

void greeting()
{
  cout << "Welcome to the hospital tour!\n\n" << endl;

  return;
}

void farewell()
{
  cout << "\nGlad we could give you a tour today! Toodaloo!!" << endl;

  return;
}
