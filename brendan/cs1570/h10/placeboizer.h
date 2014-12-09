// Programmer: Brendan Curran             Date: 10/7/2014
// File: placeboizer.h    		            Class: CS 1570 Sec C
// Description: contains the placeboizer class


#ifndef PLACEBOIZER_H
#define PLACEBOIZER_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int PDEFAULT_COST = 500;
const int PWEIGHTGAIN = 50;
const string PLNAME = "Placeboizer";

class placeboizer
{
  private:
    float m_costPerUse;
    short m_numUses;
    string m_name;
  public:
    //Description: Default constructor. 
    //Pre: none
    //Post: Assigns default cost per use
    //number of uses to 0, and the default name
    placeboizer();
    
    //Description: charges the patient for this machine's services
    //Pre: none
    //Post: deducts the cost per use of this machine from the patient's money
    void chargePatient(patient &pat);
    
    //Description: Administers this machine to the patient and its effects
    //Pre: Alive patient passed by reference
    //Post: the patient's mental health value will increase by an amount equal 
    //to half the difference between their current mental health and the maximum mental health. 
    //[ MH += (100-MH)/2; ]
    //The patient will also gain 50 pounds
    void apply(patient & pat);
    
    //Accessor function for the cost per use of the machine
    int getCost() {return m_costPerUse;}
    
    //Accessor function for the number of times the machine has been used
    int getNumUses() {return m_numUses;}
    
    //Accessor function for the name of the machine
    string getName() {return m_name;}
    
    //Description: overloaded insertion operator for this class
    //Pre: m_numUses defined
    //Post: outputs the number of times the machine has been used
    friend ostream& operator << (ostream& stream, placeboizer& machine);
};

#endif