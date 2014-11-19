// Programmer: ALEX SHAW                   Date: 11-16-14
// File: hospital_room.cpp                 Class: CS1570 Section B
// Purpose: This file contains the implementations of the functions
// belonging to the class that simulates a hospital room.

#include "x_rayer.h"
#include "hospital_room.h"
#include "patient.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

hospital_room::hospital_room(const float oz_schraut)
{
  m_oz_schraut = oz_schraut;
}

void hospital_room::admit(patient & p) const
{
  m_the_machine.charge_patient(p);
  m_the_machine.apply(p);
  m_the_machine.increment_uses();         //Increment the number of
  return;
}

ostream& operator<<(ostream & o, const hospital_room & h)
{
  o << "This room has an x-ray machine and " << h.m_oz_schraut << " oz of"
       << " Schraut." << endl;
  o << h.m_the_machine;
  return o;
}
