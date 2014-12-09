// Programmer: Brendan Curran             Date: 10/7/2014
// File: organDonor.h    		              Class: CS 1570 Sec C
// Description: contains the organ donor class and the constants it uses


#ifndef ORGANDONOR_H
#define ORGANDONOR_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int ODDEFAULT_COST = 100;
const int MHEALTHINCREASE = 10;
const int PHEALTHMAXLOSS = 20;
const int ODDEATHCHANCE = 2;
const int ODWEIGHTLOSS = 10;
const string ODNAME = "Organ Donor Machine";

class organDonor
{
  private:
    float m_costPerUse;
    short m_numUses;
    string m_name;
  public:
    //Description: Default constructor
    //Pre: none
    //Post: number of uses is set to 0, name is set to the default name
    //and cost per use is set to its default
    organDonor();
    
    //Description: Charges the patient for this machines services
    //Pre: patient passed by refence, patient has enough money to pay the costs
    //Post: the cost per use of the machine is dedecuted from the patients money
    void chargePatient(patient &pat);
    
    //Description: Applies the machine to the patient and its effects
    //Pre: Patient passed by reference and is not dead
    //Post: will increase the patient's mental health by 100 but will
    //decrease their physical health by a random amount on interval [0,20]
    //has a 2% chance of killing the patient, and will reduce the patient's 
    //weight by 10
    void apply(patient & pat);
    
    //Accessor function for the cost per use of machine
    int getCost() {return m_costPerUse;}
    
    //Accessor function for the number of times the machine has been used
    int getNumUses() {return m_numUses;}
    
    //Accessor function for the name of the machine
    string getName() {return m_name;}
    
    //Description: overloaded insertion operator for the organ donor class
    //Pre: organ donor used with operator <<
    //Post: outputs the number of times the machine has been used
    friend ostream& operator << (ostream& stream, organDonor& machine);
};

#endif