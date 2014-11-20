//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hospital_room.h           Class: CS 1570, Section D
//Purpose: Header file for hospital_room class

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

#include <fstream>
#include "patient.h"
#include "x_rayer.h"

const float DEF_OZ_OF_DRINK = 10.0;

// admit() calls the X_rayer's charge_patient() and apply() methods on the
//   given Patient object.
// Pre: Calling object must have the_machine defined.
// Post: the_machine's charge_patient() and apply() methods are called on ptnt.

// The << operator for the Hospital_room class prints an Hospital_room object.
// Pre: The ostream must be opened already and room must have all its
//   properties existing.
// Post: Prints the Hospital_room object through the given ostream object.

class Hospital_room
{
  private:
    X_rayer the_machine;
    float oz_of_drink;
  public:
    Hospital_room();
    void admit(Patient& ptnt) const;
    friend ostream& operator << (ostream& out, const Hospital_room& room);
};


#endif