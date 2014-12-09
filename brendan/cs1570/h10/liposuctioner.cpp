// Programmer: Brendan Curran             Date: 10/7/2014
// File: liposuctioner.cpp 		            Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include <cstdlib>
#include "liposuctioner.h"

using namespace std;

liposuctioner::liposuctioner()
{
  m_costPerUse = LIPODEFAULT_COST;
  m_numUses = 0;
  m_name = LIPONAME;
}

void liposuctioner::chargePatient(patient &pat)
{
  pat.payOut(m_costPerUse);
}

void liposuctioner::apply(patient& pat)
{
  int weightReduction = (pat.getWeight()*LWEIGHTLOSSPERCENT)/100;
  pat.modifyWeight(-weightReduction);
  pat.modifyMHealth(20);
  if (m_numUses == 61)
    pat.modifyHealth(-100);
  m_numUses ++;
}

ostream& operator << (ostream& stream, liposuctioner & machine)
{
  stream << "liposuctioner machine number of uses: " << machine.m_numUses;
  return stream;
}