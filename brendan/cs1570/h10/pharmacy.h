// Programmer: Brendan Curran             Date: 10/7/2014
// File: pharmacy.h    		            Class: CS 1570 Sec C
// Description: contains the pharmacy class and its constants


#ifndef PHARMACY_H
#define PHARMACY_H

#include "patient.h"
#include <iostream>
#include <string>
using namespace std;

const int PHARMDEFAULT_COST = 150;
const int PILLINTERVALSTART = 50; //minimum number of pills housed
const int PILLINTERVALSIZE = 51;  //how large the interval is
                                  //maximum is interval size -1 + start
const string PHARMNAME = "Pharmacy";

class pharmacy
{
  private:
    float m_costPerUse;
    short m_numUses;
    short m_numPills; //number of pills left in the pharmacy
    string m_name;
  public:
    //Description: Default constructor
    //Pre: none
    //Post: cost per use is set to default, number of uses is set to 0
    //num pills is randomly assigned 
    pharmacy();
    
    //Description: Charges the patient for this machine's services
    //Pre: Patient passed by reference and has enough money for cost
    //Post: cost per use of this machine is deducted from the patients money
    void chargePatient(patient &pat);
    
    //Description: Administers this machine to the patient and its effects
    //Pre: Patient passed by refence who is alive
    //Post: as long as pills remain, a random pill will be given
    //Pill 1: physical health(ph) increases by 10, mental health (mh) decreases
    //by 10
    //Pill 2: ph increases by 20, mh set to 0
    //Pill 3: ph set to 50
    //Pill 4: mh set to 100 and weight increased by 100
    //If no pills remain, the patient will eat a cotton ball tha
    //reduces mh by 23 and increases weight by 44
    void apply(patient & pat);
    
    //Accesor function for the cost per use
    int getCost() {return m_costPerUse;}
    
    //Accesor function for the number of times the machine has been used
    int getNumUses() {return m_numUses;}
    
    //Accesor function for the name of the machine
    string getName() {return m_name;}
    
    //Description: Overloaded insertion operator for this class
    //Pre: pharmacy is defined
    //Post: outputs the number of times the machine has been used,
    //and the number of pills remaining
    friend ostream& operator << (ostream& stream, pharmacy& machine);
};

#endif