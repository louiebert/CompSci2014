//Programmer: LOUIE BERTONCIN     Date: 11/18/2014
//File: compound.cpp              Class: CS 1580, Section D
//Purpose: Implementation file for the Compound class.

#include <string>
#include <iostream>
#include "compound.h"

using namespace std;

Compound& Compound::operator + (const Compound& other)
{
  name = name.append("-");
  name = name.append(other.name);
  for(int i = 0; i < ELEMENT_COUNT; i++)
    elements[i] = elements[i] + other.elements[i];
  kg = kg + other.kg;

  return (*this);
}

Compound& operator * (Compound& comp, const float amount)
{
  comp.kg *= amount;
  return (comp);
}

ostream& operator << (ostream& out, const Compound& comp)
{
  out << comp.name << " (" << comp.kg << ") ";
  int tempArray[ELEMENT_COUNT];
  for(int i = 0; i < ELEMENT_COUNT; i++)
  {
    tempArray[comp.elements[i]]++;
  }
  for(int j = 0; j < ELEMENT_COUNT; j++)
  {
    if(tempArray[j] != 0)
      out << j << " " << tempArray[j] << " ";
  }
  out << comp.kg;

  return out;
}

istream& operator >> (istream& in, Compound& comp)
{
  getline(in, comp.name, ' ');
  int amount = 0, atomicNum = 0, multiplier = 0, elementsCounter = 0;
  in >> amount;
  for(int i = 0; i < amount; i++)
  {
    in >> atomicNum;
    in >> multiplier;
    for(int j = 0; j < multiplier; j++)
    {
      comp.elements[elementsCounter] = atomicNum;
      elementsCounter++;
    }
  }
  in >> comp.kg;

  return in;
}
