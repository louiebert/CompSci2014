// Programmer: Brendan Curran             Date: 11/19/2014
// File: xray.h        		              Class: CS 1570 Sec C
// Description: contains the xray class

#ifndef XRAY_H
#define XRAY_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int XRAY_DANGER_PERCENT = 10;
const int DEFAULT_COST = 550;
const string XNAME = "xRayer";
class xRayer
{
  private:
    float m_costPerUse;
    short m_numUses;
    string m_name;
  public:
    
    //Description: default constructor
    //Pre: none
    //Post: m_numUses = 0; m_costPerUse = DEFAULT_COST
    xRayer();
    
    //Description: runs xray on patient
    //Pre: patient passed by reference
    //Post: m_numUses is increased by one
    //there is a 10% chance the patients condition will be halved
    void apply(patient & pat);
    
    //Description: charges the patient for xray services
    //Pre: patient passed by reference
    //Post: patient's money is docked m_costPerUse
    void chargePatient(patient &pat);
    
    //Accessor function for the cost per use of the machine
    int getCost() {return m_costPerUse;}
    
    //Accessor function for the number of times the machine has been used
    int getNumUses() {return m_numUses;}
    
    //Acessor function for the name of the machine
    string getName() {return m_name;}
    
    //Description: defines insertion operator
    //output is : number of machine uses: (m_numUses)
    friend ostream& operator << (ostream& stream, xRayer& machine);
    
};

#endif

