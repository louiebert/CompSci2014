// Programmer: Brendan Curran             Date: 10/7/2014
// File: liposuctioner.h    		          Class: CS 1570 Sec C
// Description: contains the liposuctioner class and constants used by it


#ifndef LIPOSUCTIONER_H
#define LIPOSUCTIONER_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int LIPODEFAULT_COST = 750;
const int LWEIGHTLOSSPERCENT = 10;
const int LMHEALTHINCREASE = 20;
const string LIPONAME = "Liposuctioner";

class liposuctioner
{
  private:
    float m_costPerUse;
    short m_numUses;
    string m_name;
  public:
    //Description: Default constructor
    //Pre: none
    //Post: number of uses is set to zero, and the standard name
    //and cost per use is assigned from constants above
    liposuctioner();
    
    //Description: Charges patient for operation
    //Pre: patient passed by reference, must have enough money for operation
    //Post: Operation cost is deducted from the patients money
    void chargePatient(patient &pat);
    
    //Description: Runs the operation on the patient and applies its effects
    //Pre: patient passed by reference, patient should be alive to start
    //Post: patients weight will decrease by 10%, and incnreases their mental
    //condition by 20. Every 62nd patient will be killed by this machine
    void apply(patient & pat);
    
    //Accessor for cost per use
    int getCost() {return m_costPerUse;}
    
    //Accessor for the number of times the machine has been used
    int getNumUses() {return m_numUses;}
    
    //Accessor for the name of the machine
    string getName() {return m_name;}
    
    //Description: Overloaded insertion operator for the liposuctioner class
    //Pre: Liposuctioner passed
    //Post: Outputs the number of times the machine has been used
    friend ostream& operator << (ostream& stream, liposuctioner& machine);
};

#endif