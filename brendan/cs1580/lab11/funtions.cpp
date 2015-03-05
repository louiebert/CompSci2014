// Programmer: Brendan Curran              Date: 11/12/2014
// File: speedRecorder.h                   Class: CS 1580 Sec D
// Description: contains function definitions for main lab11 program

#include "functions.h"
#include "speedRecorder.h"
#include <iostream>

using namespace std;

void enterSpeeds (speedRecorder & company)
{
  bool again = true;
  int input;
  char ans;
  while (again)
  {
    cout << "Please enter a speed: ";
    cin >> input;
    company.addSpeed(input);
    cout << "Would you like to input another speed? (y/n): ";
    cin >> ans;
    if (ans!= 'y')
      again = false;
  }
  return;   
}

void displayInfo(const speedRecorder & company)
{
  cout << ""Company id: " << company.getId() << endl;
  cout << "Total entries: " << company.getTotalEntries() << endl;
  cout << "Average speed: " << company.getAverageSpeed() << endl;
  return;
}