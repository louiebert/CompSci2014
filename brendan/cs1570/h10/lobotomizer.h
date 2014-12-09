// Programmer: Brendan Curran             Date: 10/7/2014
// File: lobotmizer.h    		              Class: CS 1570 Sec C
// Description: 

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int LDEFAULT_COST = 200;
const int PHEALTHGAIN = 3;
const int MHEALTHGAIN = 10;
const int VEGETABLE_CHANCE = 3;
const int FORGET_NAME_CHANCE = 10;
const string LNAME = "Lobotomizer";

class lobotomizer
{
  private:
    float m_costPerUse;
    short m_numUses;
    string m_name;
  public:
    lobotomizer();
    void chargePatient(patient &pat);
    void apply(patient & pat);
    int getCost() {return m_costPerUse;}
    int getNumUses() {return m_numUses;}
    string getName() {return m_name;}
    friend ostream& operator << (ostream& stream, lobotomizer& machine);
};

#endif