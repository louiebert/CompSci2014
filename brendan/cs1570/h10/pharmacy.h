// Programmer: Brendan Curran             Date: 10/7/2014
// File: pharmacy.h    		            Class: CS 1570 Sec C
// Description: 


#ifndef PHARMACY_H
#define PHARMACY_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int PHARMDEFAULT_COST = 150;
const int PILLINTERVALSIZE = 51;
const int PILLINTERVALSTART = 50;
const string PHARMNAME = "Pharmacy";

class pharmacy
{
  private:
    float m_costPerUse;
    short m_numUses;
    short m_numPills;
    string m_name;
  public:
    pharmacy();
    void chargePatient(patient &pat);
    void apply(patient & pat);
    int getCost() {return m_costPerUse;}
    int getNumUses() {return m_numUses;}
    string getName() {return m_name;}
    friend ostream& operator << (ostream& stream, pharmacy& machine);
};

#endif