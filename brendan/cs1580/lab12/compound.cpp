// Programmer: Brendan Curran              Date: 11/19/2014
// File: element.cpp                       Class: CS 1580 Sec D
// Description: 

#include "compound.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;



compound::compound()
{
  m_name = "unknown";
  m_elements[0] = 0;
  for (int i = 1; i< ELEMENT_COUNT; i++)
    m_elements[i] = 0;
  m_mass = 0;
}

compound compound::operator * (const float amount)
{
  m_mass = m_mass*amount;
  return(*this);
}

compound& compound::operator + (const compound&other)
{
  char c1name[40];
  strcpy(c1name, m_name.c_str());
  char c2name[40];
  strcpy (c2name, other.m_name.c_str());
  
  strcat(c1name, "-");
  m_name = strcat(c1name, c2name);  
  
  for (int i= 0; i < ELEMENT_COUNT; i++)
  {
    m_elements[i] = m_elements[i]+ other.m_elements[i];
  }
  
  m_mass = m_mass + other.m_mass;
  
  return(*this);
}

ostream& operator << (ostream& stream, compound& value)
{
  stream << value.m_name << " (" << value.m_mass << ") ";
  
  for (int i = 0; i< ELEMENT_COUNT; i++)
  {
    if (value.m_elements[i] != 0)
    {
      stream << i+1 << " " << value.m_elements[i] << ", ";
    }
  }
  return stream;
}

istream& operator >> (istream& stream, compound& value)
{
  int numElements;
  int tempAmount;
  int tempID;
  stream >> value.m_name;
  stream >> numElements;
  for (int i = 0; i< numElements; i++)
  {
    stream >> tempID;
    stream >> tempAmount;
    value.m_elements[tempID-1]= tempAmount;
  }
  stream >> value.m_mass;
  
  return (stream);
}
