//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: hospital_room.h                         Class: CS 1570, Section D
//Purpose: Header file for Hospital_Room class

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H
#include "doctor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor creates a default hospital room with 10oz of schraut and a
//   default machine.
// Pre: None.
// Post: A new hospital room is created.

// admit() charges the patient for using the_machine and uses the_machine.
// Pre: None.
// Post: the_machine is used on the patient and the patient is charged.

// Insertion operator for Hospital_Room outputs the machine and the ounces of
//   schraut left in the room.
// Pre: None.
// Post: Outputs a Hospital_Room object.

const float INIT_SCHRAUT=10.0;
const short MAXSCHRAUT=3;
const short MINSCHRAUT=1;

template <class T_machine>
class Hospital_Room
{
  private:
    T_machine m_the_machine;
    float m_schrautOz;
  public:
    Hospital_Room(): m_schrautOz(INIT_SCHRAUT){}
    void admit(Patient & p,Doctor & dr);
    template <class U_machine>
    friend ostream& operator <<(ostream& out,const Hospital_Room
      <U_machine>& hr);
};

#include "hospital_room.hpp"

#endif
