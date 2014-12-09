// Programmer: Brendan Curran             Date: 10/7/2014
// File: placeboizer.cpp 		              Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include <cstdlib>
#include "placeboizer.h"

using namespace std;

placeboizer::placeboizer()
{
  m_costPerUse = PDEFAULT_COST;
  m_numUses = 0;
  m_name = PLNAME;
}

void placeboizer::chargePatient(patient &pat)
{
  pat.payOut(m_costPerUse);
}

void placeboizer::apply(patient& pat)
{
  pat.modifyWeight(PWEIGHTGAIN);
  pat.modifyMHealth((100-pat.getMHealth())/2);
  m_numUses ++;
}

ostream& operator << (ostream& stream, placeboizer & machine)
{
  stream << "placeboizer machine number of uses: " << machine.m_numUses;
  return stream;
}