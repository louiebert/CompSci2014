// Programmer: Brendan Curran             Date: 11/19/2014
// File: hospitalRoom.h      		              Class: CS 1570 Sec C
// Description: 

#ifndef HOSPITALROOM_H
#define HOSPITALROOM_H
#include "xray.h"
#include "patient.h"
#include <iostream>
#include "doctor.h"

using namespace std;

template <class T_machine>
class hospitalRoom
{
  private:
    T_machine m_machine;
    float m_ouncesOfSchraut;
  public:
    //Description: default constructor
    //Pre: none
    //Post: ounces of schraut is assigned 10
    hospitalRoom(): m_ouncesOfSchraut(10) {}
    
    //Description: runs xray machine on patient and charges them
    //Pre: patient passed by reference
    //Post: xRay functions apply and chargePatient are run on patient
    void admit(patient & pat, doctor& doc);
    
    //Description: defines insertion operator for hospital room
    //outputs the amount of schraut currently in the room and the
    //number of uses on the xray machine
    template <class T_friend>
    friend ostream& operator << (ostream& stream, hospitalRoom<T_friend>& hr);
    
};

#include "hospitalRoom.hpp"
#endif