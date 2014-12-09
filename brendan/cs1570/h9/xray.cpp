// Programmer: Brendan Curran             Date: 11/19/2014
// File: xray.cpp        		              Class: CS 1570 Sec C
// Description: defines functions and default constructor for the xray class

#include "xray.h"
#include <cstdlib>
#include "patient.h"
#include <iostream>

using namespace std;

xRayer::xRayer()
{
  m_numUses =0;
  m_costPerUse=DEFAULT_COST;
}

void xRayer::apply(patient & pat)
{
  int halfCond = pat.getCondition()/2;
  m_numUses++;
  
  
  if (rand()%100 <XRAY_DANGER_PERCENT)
    pat.modifyHealth(-1*halfCond);
}

void xRayer::chargePatient(patient &pat)
{
  pat.payOut(m_costPerUse);
}
ostream& operator << (ostream& stream, xRayer& machine)
{
  stream << "Number of machine uses: " << machine.m_numUses;
  return stream;
}
