// Programmer: Brendan Curran             Date: 10/7/2014
// File: lobotomizer.h    		            Class: CS 1570 Sec C
// Description: contains the lobotomizer class and its constants

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
    //Description: Default constructor, assigns name from constants
    //sets num uses to 0 and cost per use to assigned constant
    lobotomizer();
    
    //Description: Charges the patient for this machine's services
    //Pre: patient passed by reference
    //Post: Reduces the patients money by the cost per use of this machine
    void chargePatient(patient &pat);
    
    //Description: Applies the machine to patient and its effects
    //Pre: patient passed by refence, patient is alive
    //Post: Mental health will increase by 10 and physical health will be 
    //increased by 3, there is a 3% chance the patient will turn into a 
    //vegetable, where the mental health is reduced to 0
    //there is also a 10% chance the patient will forget their name
    //to indicate this a new name will be concatenated onto their old name
    void apply(patient & pat);
    
    //Acessor function for the cost of the machine
    int getCost() {return m_costPerUse;}
    
    //Acessor for the number of times the machine has been used
    int getNumUses() {return m_numUses;}
    
    //Acessor function for the name of the machine
    string getName() {return m_name;}
    
    //Description: Overloaded insertion operator for the machine
    //Pre: lobotomizer used with << operator
    //Post: the number of uses on the machine will be printed
    friend ostream& operator << (ostream& stream, lobotomizer& machine);
};

#endif