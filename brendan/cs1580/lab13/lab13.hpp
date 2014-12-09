// Programmer: Brendan Curran              Date: 12/3/2014/2014
// File: lab13.hpp                          Class: CS 1580 Sec D
// Description: 


using namespace std;

#include <iostream>
#include "lab13.h"

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