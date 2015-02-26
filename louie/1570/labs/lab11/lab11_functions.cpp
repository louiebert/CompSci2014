//Programmer: LOUIE BERTONCIN     Date: 11/11/2014
//File: lab11_functions.h         Class: CS 1580, Section D
//Purpose: Functions file for OOP lab.

#include <iostream>
#include "lab11.h"

using namespace std;

void greeting()
{
  cout << ""Hey there! Let's make a speed record for a superficial company!"
    << endl << endl;

  return;
}

Speed_recorder make_speed_recorder()
{
  int compID, numEntries, spdEntry;
  cout << "First, what's the company ID? ";
  cin >> compID;
  Speed_recorder spd(compID);
  do
  {
    cout << "Now, how many speed entries would you like to make? ";
    cin >> numEntries;
    cout << endl;
  } while(numEntries <= 0);
  for(int i = 0; i < numEntries; i++)
  {
    cout << "Entry " << i+1 << ": ";
    cin >> spdEntry;
    spd.addSpeed(spdEntry);
  }

  return spd;
}

void summary(const Speed_recorder & spd_rcrd)
{
  cout << "The company with ID of " << spd_rcrd.getId() << " has the following"
    " stats:" << endl;
  cout << "\tTotal Speed Entries: " << spd_rcrd.getTotalEntries() << endl;
  cout << "\tAverage Speed: " << spd_rcrd.getAverageSpeed() << endl << endl;
  return;
}

bool add_speeds()
{
  char answer;
  cout << "Would you like to add more speeds to this company? (y/n) ";
  cin >> answer;

  return tolower(answer) == 'y';
}

void more_speeds(Speed_recorder & spd_rcrd)
{
  int numEntries, spdEntry;
  do
  {
    cout << ""How many speed entries would you like to add on? ";
    cin >> numEntries;
    cout << endl;
  } while(numEntries <= 0);
  for(int j = 1; j < numEntries+1; j++)
  {
    cout << "Entry " << spd_rcrd.getTotalEntries()+1 << ": ";
    cin >> spdEntry;
    spd_rcrd.addSpeed(spdEntry);
  }

  return;
}

bool again()
{
  char answer;
  cout << ""Would you like to make another speed record? (y/n) ";
  cin >> answer;

  return tolower(answer) == 'y';
}

void goodbye()
{
  cout << ""It was a pleasure making fraudulent speed records with you. Have a"
    " nice day!" << endl << endl;

  return;
}
