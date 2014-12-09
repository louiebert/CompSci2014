// Programmer: Brendan Curran              Date: 12/3/2014/2014
// File: lab13.hpp                          Class: CS 1580 Sec D
// Description: 


using namespace std;

#include <iostream>
#include "lab13.h"
#include <cstdlib>

void horse::act()
{
  int selection = rand()%5;
  switch (selection)
  {
    case 0:
      cout << m_name << " is jumping the fence" << endl;
      break;
    case 1:
      cout << m_name << " is reading a book" << endl;
      break;
    case 2:
      cout << m_name << " is throwing a mad rave" << endl;
      break;
    case 3:
      cout << m_name << " is just sitting there" << endl;
      break;
    case 4:
      cout << m_name << " is killing people" << endl;
      break;
  }
}

void cat::act()
{
  int selection = rand()%5;
  switch (selection)
  {
    case 0:
      cout << m_name << " is doing parkour" << endl;
      break;
    case 1:
      cout << m_name << " is riding one of the horses" << endl;
      break;
    case 2:
      cout << m_name << " is hiding in a bush" << endl;
      break;
    case 3:
      cout << m_name << " is in a tree" << endl;
      break;
    case 4:
      cout << m_name << " is toasting some bagels" << endl;
      break;
  } 
}
ostream& operator<<(ostream& stream, horse& value)
{
  stream << value.m_name;
  stream << " (" << value.m_gender << ")";
  return stream;
}

ostream& operator<<(ostream& stream, cat& value)
{
  stream << value.m_name;
  stream << " (" << value.m_gender << ")";
}