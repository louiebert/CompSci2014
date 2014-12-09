// Programmer: Brendan Curran             Date: 10/7/2014
// File: liposuctioner.h    		            Class: CS 1570 Sec C
// Description: 


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
    liposuctioner();
    void chargePatient(patient &pat);
    void apply(patient & pat);
    int getCost() {return m_costPerUse;}
    int getNumUses() {return m_numUses;}
    string getName() {return m_name;}
    friend ostream& operator << (ostream& stream, liposuctioner& machine);
};

#endif