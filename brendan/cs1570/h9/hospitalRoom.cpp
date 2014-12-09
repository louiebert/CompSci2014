// Programmer: Brendan Curran             Date: 11/19/2014
// File: hospitalRoom.cpp		              Class: CS 1570 Sec C
// Description: 

#include "hospitalRoom.h"
#include <iostream>
using namespace std;

hospitalRoom::hospitalRoom()
{
  m_ouncesOfSchraut = 10.0;
}

void hospitalRoom::admit(patient &pat)
{
  m_machine.apply(pat);
  m_machine.chargePatient(pat);
}

ostream& operator << (ostream& stream, hospitalRoom& hr)
{
  stream << "Ozs of Schraut = " << hr.m_ouncesOfSchraut << endl;
  stream << hr.m_machine;
  return stream;
}