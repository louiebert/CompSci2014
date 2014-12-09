// Programmer: Brendan Curran             Date: 10/7/2014
// File: organDonor.cpp 		              Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include <cstdlib>
#include "organDonor.h"

using namespace std;

organDonor::organDonor()
{
  m_costPerUse = ODDEFAULT_COST;
  m_numUses = 0;
  m_name = ODNAME;
}
void organDonor::chargePatient(patient &pat)
{
  pat.payOut(m_costPerUse);
}

void organDonor::apply(patient& pat)
{
  int randNum1, randNum2;
  randNum1 = rand()%PHEALTHMAXLOSS;
  randNum2 = rand()%100;
  
  pat.modifyHealth(-randNum1);
  pat.modifyMHealth(MHEALTHINCREASE);
  
  if (randNum2 < ODDEATHCHANCE)
    pat.modifyHealth(-pat.getHealth());
  
  pat.modifyWeight(-ODWEIGHTLOSS);
  m_numUses ++;
}

ostream& operator << (ostream& stream, organDonor & machine)
{
  stream << "organ donor machine number of uses: " << machine.m_numUses;
  return stream;
}