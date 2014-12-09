// Programmer: Brendan Curran             Date: 10/7/2014
// File: organDonor.h    		              Class: CS 1570 Sec C
// Description: 


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
    organDonor();
    void chargePatient(patient &pat);
    void apply(patient & pat);
    int getCost() {return m_costPerUse;}
    int getNumUses() {return m_numUses;}
    string getName() {return m_name;}
    friend ostream& operator << (ostream& stream, organDonor& machine);
};

#endif