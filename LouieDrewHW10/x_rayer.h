//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/17/2014
//File: x_rayer.h                               Class: CS 1570, Section D
//Purpose: Header file for X_Rayer class

#ifndef X_RAYER_H
#define X_RAYER_H
#include "patient.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Constructor makes an X_Rayer with a cost of 550 and 0 uses.
// Pre: None.
// Post: A new X_Rayer object is created with cost of 550 and 0 uses.

// get_cost_per_use() returns the X_Rayer object's m_cost_per_use.
// Pre: None.
// Post: Returns m_cost_per_use.

// charge_patient() reduces the provided Patient object's m_money by
//   m_cost_per_use.
// Pre: None.
// Post: Reduces Patient object's money.

// apply() increments num_uses by 1 and 10% of the time halves the patient's
//   condition.
// Pre: None.
// Post: num_uses is incremented and the patient's health may be diminished.

// Insertion operator outputs the cost and number of uses.
// Pre: None.
// Post: The insertion operator is overridden.

const float XR_COST_PER_USE = 550;

class X_Rayer
{
  private:
    float m_cost_per_use;
    short m_num_uses;
  public:
    X_Rayer():m_num_uses(0),m_cost_per_use(XR_COST_PER_USE){}
    float get_cost_per_use(){return m_cost_per_use;}
    void charge_patient(Patient & patient)const;
    void apply(Patient & patient);
    friend ostream& operator << (ostream& out, const X_Rayer& x);
};

#endif
