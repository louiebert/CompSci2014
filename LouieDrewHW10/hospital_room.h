//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: hospital_room.h                         Class: CS 1570, Section D
//Purpose: Header file for hospital_room class

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H
#include "x_rayer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const float INIT_SCHRAUT=10;

//Description: The hospital_room constructor creates a default hospital
//room with 10oz of schraut and a default machine.
//Precondition: None
//Postcondition: A new hospital room is created.

//Description: The admit function charges the patient for using the x_rayer
//             the_machine and uses the_machine.
//Precondition: None
//Postcondition: The x_rayer is used on the patient and the patient is
//               charged.

//Description: This funciton redefines the insertion operator for hospital
//             to output the state of the x_rayer and ounces of schraut.
//Precondition: None
//Postcondition: The insertion operator is defined for hospital_room.
class hospital_room
{
  public:
    hospital_room(const float s=INIT_SCHRAUT): m_schrautOz(s){}
    void admit(patient & p);
    friend ostream& operator <<(ostream& o,const hospital_room & h);
  private:
    x_rayer m_the_machine;
    float m_schrautOz;
};
#endif
