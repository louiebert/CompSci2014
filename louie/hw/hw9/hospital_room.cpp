//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hospital_room.cpp         Class: CS 1570, Section D
//Purpose: Body file for hospital_room class

#include "hospital_room.h"

using namespace std;

Hospital_room::Hospital_room()
{
  oz_of_drink = DEF_OZ_OF_DRINK;
}

void Hospital_room::admit(Patient& ptnt) const
{
  the_machine.charge_patient(ptnt);
  the_machine.apply(ptnt);

  return;
}

ostream & operator << (ostream& out, const Hospital_room& room)
{
  out << "Hospital Room:\n\t" << room.the_machine << ",\n\toz of Schraut!: " <<
    room.oz_of_drink;
  return out;
}