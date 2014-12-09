// Programmer: Brendan Curran             Date: 10/7/2014
// File: lobotomizer.cpp  		              Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include <cstdlib>
#include "lobotomizer.h"

using namespace std;

lobotomizer::lobotomizer()
{
  m_costPerUse = LDEFAULT_COST;
  m_name = LNAME;
  m_numUses = 0;
}
void lobotomizer::chargePatient(patient &pat)
{
  pat.payOut(m_costPerUse);
}

void lobotomizer::apply(patient& pat)
{
  int randNum;
  pat.modifyHealth(PHEALTHGAIN);
  pat.modifyMHealth(MHEALTHGAIN);
  
  randNum = rand()%100;
  
  if (randNum < 10)
    pat.modifyMHealth(-pat.getMHealth());
  
  if (randNum <3)
  {
    pat.forgetName();
  }
  m_numUses ++;
}

ostream& operator << (ostream& stream, lobotomizer & machine)
{
  stream << "Lobotomizer machine number of uses: " << machine.m_numUses;
  return stream;
}