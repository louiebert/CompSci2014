// Programmer: Brendan Curran              Date: 10/13/2014
// File: h6main.cpp                        Class: CS 1570 Sec C
// Description: cockroach testing for JHS, this file executes the
// necessary operations to test for this disease

#include <iostream> 
#include <ctime>
#include <cstdlib>
#include "tones.h"
using namespace std;

int main()
{
  patient patientA;
  char input;
  bool loop = true;
  srand(time(NULL));
  
  greet();
  while(loop)
  {
    patientA.m_name = getName();
  
    cout << "Testing will now commence\n" << endl; ;
    tone1(patientA);
    tone2(patientA);
    tone3(patientA);
    patientA.m_diagnosis = diagnose(patientA);
  
    showResult(patientA);
    
    cout << "\nWould you like to do more testing? (y/n): ";
    cin >> input;
    if (input != 'y')
      loop = false;
  }
  cout << "Please thank your patient for allowing us to shove a roach down";
  cout << "\ntheir throat, and ask them to come again" << endl;
  cout << "goodbye\n" << endl;
  return 0;
}