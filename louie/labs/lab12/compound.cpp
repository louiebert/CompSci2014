//Programmer: LOUIE BERTONCIN     Date: 11/18/2014
//File: compound.cpp              Class: CS 1580, Section D
//Purpose: Implementation file for the Compound class.

#include <string>
#include <iostream>
#include "compound.h"

using namespace std;

Compound Compound::operator + (const Compound& other)
{
  Compound total;
  total.name = name;
  total.name.append("-");
  total.name.append(other.name);
  for(int i = 0; i < ELEMENT_COUNT; i++)
    total.elements[i] = elements[i] + other.elements[i];
  total.kg = kg + other.kg;

  return (total);
}

Compound& Compound::operator = (const Compound& reference)
{
  name = reference.name;
  kg = reference.kg;
  for(int i = 0; i < ELEMENT_COUNT; i++)
    elements[i] = reference.elements[i];

  return (*this);
}

Compound& operator * (Compound& comp, const float amount)
{
  comp.kg *= amount;
  return (comp);
}

ostream& operator << (ostream& out, const Compound& comp)
{
  out << comp.name << " (" << comp.kg << ")";
  int tempArray[ELEMENT_COUNT] = {0};
  for(int i = 0; i < ELEMENT_COUNT; i++)
  {
    tempArray[comp.elements[i]]++;
  }
  bool yesComma = false;
  for(int j = 1; j < ELEMENT_COUNT; j++)
  {
    if(tempArray[j] != 0)
      out << (yesComma ? ", " : " ") << j << " " << tempArray[j];
      yesComma = true;
  }

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
