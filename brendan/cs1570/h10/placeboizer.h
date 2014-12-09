// Programmer: Brendan Curran             Date: 10/7/2014
// File: placeboizer.h    		            Class: CS 1570 Sec C
// Description: 


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
    placeboizer();
    void chargePatient(patient &pat);
    void apply(patient & pat);
    int getCost() {return m_costPerUse;}
    int getNumUses() {return m_numUses;}
    string getName() {return m_name;}
    friend ostream& operator << (ostream& stream, placeboizer& machine);
};

#endif