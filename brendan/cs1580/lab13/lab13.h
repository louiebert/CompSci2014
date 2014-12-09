// Programmer: Brendan Curran              Date: 12/3/2014/2014
// File: lab13.h                           Class: CS 1580 Sec D
// Description: 

#ifndef LAB13_H
#define LAB13_H

#include <iostream>
#include <string>

using namespace std;

struct horse
{
  string m_name;
	char m_gender;
  friend ostream& operator<<(ostream& stream, horse& value);
  void act();
};

struct cat
{
    string m_name;
    char m_gender;
    friend ostream& operator<<(ostream& stream, horse& value);
    void act();
};

#include "lab13.hpp"
#endif