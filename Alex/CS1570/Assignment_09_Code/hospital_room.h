// Programmer: ALEX SHAW                   Date: 11-16-14
// File: hospital_room.h                   Class: CS1570 Section B
// Purpose: This file contains the defintion of the class that simulates a
// hospital room.

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

#include "x_rayer.h"
#include "patient.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

// hospital_room() is a default constructor that initializes the member vars
//  holding the amount of Schraut! in a room and representing the room's x-ray
//  machine.
// Pre: None
// Post: Member vars of hospital_room object are initialized.

// admit() call functions that charges the patient for the x-ray and tests if
//  harm befalls patient.
// Pre: None.
// Post: Charges the patient for the x-ray and tests if harm befalls patient.

// operator <<() overloads the extraction operator to display a hospital_room
//  object's member vars
// Pre: Insertion operator must not also be overloaded as a non-member function
// Post: All of the member vars of an hospital_room object are displayed to the
//  screen.

class hospital_room
{
  public:
    hospital_room(const float oz_schraut = 10.00);
    void admit(patient & p) const;
    friend ostream& operator<<(ostream & o, const hospital_room & room);
  private:
    float m_oz_schraut;
    x_rayer m_the_machine;
};

#endif
