// Programmer: Brendan Curran              Date: 11/12/2014
// File: lab11.cpp                         Class: CS 1580 Sec D
// Description: takes company id, then conducts survey of typing speeds
// for that company, then outputs the data
// has option to input more data for that company at the end,
// or take data for a new company

#include <iostream>
#include "speedRecorder.h"
#include "functions.h"


using namespace std;

int main()
{
  int input;
  char ans;
  bool again = true, moreSpeed = true;
  while (again)
  {
    cout << "what is the company id?: ";
    cin >> input;
    speedRecorder companyA(input);
    enterSpeeds(companyA);
    displayInfo(companyA);
    while (moreSpeed)
    {
      cout << "\n Would you like to enter more speeds (y/n) :";
      cin >> ans;
      if (ans == 'y')
      {
        enterSpeeds(companyA); 
        displayInfo(companyA);
      }
      else 
        moreSpeed =false;
    }
    cout << "\nWould you like to enter for a new company?(y/n): ";
    cin >> ans;
    if (ans != 'y')
      again = false;
  }
  
  cout << "Goodbye " << endl;
  return 0;
}