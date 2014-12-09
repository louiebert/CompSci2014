// Programmer: Brendan Curran             Date: 10/7/2014
// File: pharmacy.cpp 		              Class: CS 1570 Sec C
// Description: contains function definitions for the pharmacy class

#include <iostream>
#include <cstdlib>
#include "pharmacy.h"

using namespace std;

pharmacy::pharmacy()
{
  m_costPerUse = PHARMDEFAULT_COST;
  m_numUses = 0;
  int temp = rand()%PILLINTERVALSIZE;
  m_numPills = temp+PILLINTERVALSTART;
  m_name = PHARMNAME;
}

void pharmacy::chargePatient(patient &pat)
{
  pat.payOut(m_costPerUse);
}

void pharmacy::apply(patient& pat)
{
  //25% chance of getting each pill, (uniform distribution)
  int temp = rand()%4;
  if (m_numPills > 0)
  {
    switch (temp)
    {
      case 0:
        pat.modifyHealth(10);
        pat.modifyMHealth(-10);
        break;
      case 1:
        pat.modifyHealth(20);
        pat.modifyMHealth(-100);
        break;
      case 2:
        pat.modifyHealth(100);
        pat.modifyHealth(-50);
        break;
      case 3:
        pat.modifyWeight(100);
        pat.modifyMHealth(100);
        break;
    }
    m_numPills--;
  }
  else //patient eats cotton ball, lol
  {
    pat.modifyMHealth(-23);
    pat.modifyWeight(44);
  }
  m_numUses++;
}

ostream& operator << (ostream& stream, pharmacy & machine)
{
  stream << "pharmacy number of uses: " << machine.m_numUses;
  stream << ", number of pills remaining "<< machine.m_numPills;
  return stream;
}