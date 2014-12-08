//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Declares the patient-class object for our simulation and all
// member functions and variables for the simulation of a doctor and patient
// entering a hospital room and using the machine in that room
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "hw10.h"
using namespace std;

//----------------------------Global Constants-------------------------------//
const int MAX_INITIAL_FUNDS = 4000;
const int WEIGHT_MIN = 120;
const int PERFECT_HEALTH = 100;
const int DEAD = 0;
const char PATIENT_NAME_FILE[] = "names.dat";

//-----------------------------Documentation---------------------------------//
// Patient() is the default constructor for Patient
// Preconditions: None
// Postconditions: Values for m_money, m_condition, and m_name randomly
// assigned; value for m_isAlive is assigned based on value for m_condition

// The pay_out functions deducts a specified amount from patient's assets
// Preconditions: Parameter amount is valid integer
// Postconditions: Value for m_money is reduced by amount

// modify_health deducts a specified amount from patient's condition
// Preconditions: Parameter conditionModifier is valid integer
// Postconditions: Value for m_condition is reduced by conditionModifier;
// if m_condition == DEAD, function kill is called (see below)

// modify_weight alters the patient's weight
// Pre-conditions: An integer value
// Post-conditions: Modifies the weight of the patient

// modify_mental alters the patient's mental health value
// Pre-conditions: An integer value
// Post-conditions: Modifies the mental health value of the patient

// getCondition is the accessor for condition
// Preconditions: None
// Postcondition: Value of m_condition is returned

// getMoney is the accessor for the money
// Pre-conditions: None
// Post-conditions: Value of m_money is returned

// randomlyChooseName will randomly choose a name from PATIENT_NAME_FILE
// Preconditions: None
// Postconditions: A string name from PATIENT_NAME_FILE is returned

// Overloaded operator for << (as friend function)
// Preconditions: None
// Postconditions: Patient's member variable values will be output to o
// (thereby modifying ostream o)

// kill will change patient's alive status if condition is DEAD
// Preconditions: None
// Postconditions: Value for m_isAlive is set to false if m_condition is ==
// DEAD; otherwise, its value is unchanged

//--------------------------Class Definition---------------------------------//
class Patient
{
  public:

    Patient();
    bool pay_out(const float amount);
    void modify_health(const int conditionModifier);
    void modify_weight(const int conditionModifier);
    void modify_mental(const int conditionModifier);
    void set_mental(const int set) {m_mental_health = set; return;}
    void set_physical(const int set) {m_condition = set; return;}
    void set_weight(const int set) {m_weight = set; return;}
    string randomlyChooseName();
    void forgot_name();
    int getCondition() const { return(m_condition); }
    int getMental() const { return m_mental_health; }
    int getMoney() const { return m_money; }
    friend ostream& operator << (ostream& o,
                                 const Patient& p);

  private:
    void kill();
    float m_money;         // amount of money patient has
    short m_weight;        // How much the patient weighs
    short m_mental_health; // The patient's mental health number
    bool m_isAlive;        // whether or not patient is alive
    bool m_isVegetable;    // whether or not the patient is a vegetable
    int m_condition;       // DEAD..PERFECT_HEALTH
    string m_name;         // patient's name (no spaces)
};

#endif
