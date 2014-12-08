// Programmer: Brendan Curran             Date: 11/19/2014
// File: hospitalRoom.h      		              Class: CS 1570 Sec C
// Description: 

#ifndef HOSPITALROOM_H
#define HOSPITALROOM_H
#include "xray.h"
#include "patient.h"
#include <iostream>

using namespace std;

class hospitalRoom
{
  private:
    xRayer m_machine;
    float m_ouncesOfSchraut;
  public:
    //Description: default constructor
    //Pre: none
    //Post: ounces of schraut is assigned 0
    hospitalRoom();
    
    //Description: runs xray machine on patient and charges them
    //Pre: patient passed by reference
    //Post: xRay functions apply and chargePatient are run on patient
    void admit(patient & pat);
    
    //Description: defines insertion operator for hospital room
    //outputs the amount of schraut currently in the room and the
    //number of uses on the xray machine
    friend ostream& operator << (ostream& stream, hospitalRoom& hr);
};

#endif