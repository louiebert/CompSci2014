//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hospital_room.cpp         Class: CS 1570, Section D
//Purpose: Body file for hospital_room class

#include "patient.h"

using namespace std;

Hospital_room()
{
  oz_of_drink = DEF_OZ_OF_DRINK;
}

void admit(Patient & ptnt) const
{
  the_machine.charge_patient(ptnt);
  the_machine.apply(ptnt);

  return;
}
