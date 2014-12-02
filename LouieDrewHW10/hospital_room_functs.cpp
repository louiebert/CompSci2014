//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: hospital_room.cpp                       Class: CS 1570, Section D
//Purpose: Body file for hospital_room class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hospital_room.h"
#include "x_rayer.h"
using namespace std;

void hospital_room::admit(patient & p)
{
  m_the_machine.charge_patient(p);
  m_the_machine.apply(p);
  return;
}
ostream& operator <<(ostream& o,const hospital_room & h)
{
  o<<h.m_the_machine<<"    Ounces of Schraut!: "<<h.m_schrautOz;
  return o;
}
