//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: pharmacy.h                Class: CS 1570, Section D
//Purpose: Header file for pharmacy class

#ifndef PHARMACY_H
#define PHARMACY_H

#include <iostream>
#include "patient.h"

// Default constructor sets m_num_uses to 0 and m_cost_per_use to COST_PER_USE.
// Pre: None.
// Post: Sets default values for an Pharmacy object

// get_cost_per_use() returns the Pharmacy object's m_cost_per_use.
// Pre: None.
// Post: Returns m_cost_per_use.

// charge_patient() reduces the provided Patient object's m_money by
//   m_cost_per_use.
// Pre: None.
// Post: Reduces Patient object's money.

// apply() decreases m_num_pills by 1. 25% to do one of the following: increase
//   patient's physical health by 10 and decrease mental health by 10; increase
//   patient's physical health by 20 and set mental health to 0; set patient's
//   physical health to 50; set patient's mental health to 100 and increase
//   weight by 100. If the Pharmacy is out of pills, patient's mental health
//   decreases by 23 and weight increases by 44.
// Pre: None.
// Post: Decreases number of pills by 1 and could do a number of other things to
//   the patient (listed above)

// Insertion operator prints a Pharmacy object
// Pre: None.
// Post: Format - Pharmacy(Cost Per Use: <m_cost_per_use>, Uses: <m_num_uses>,
//   Pills Left: <m_num_pills>)

const float PH_COST_PER_USE = 150;
const int PH_PILL_NUM_MIN = 50;
const int PH_PILL_NUM_MAX = 100;
const int PH_PHYSICAL_HEALTH_MODIFIER_A = 10;
const int PH_MENTAL_HEALTH_MODIFIER_A = -10;
const int PH_PHYSICAL_HEALTH_MODIFIER_B = 20;
const int PH_PHYSICAL_HEALTH_MODIFIER_C = 50;
const int PH_MENTAL_HEALTH_MODIFIER_D = 100;
const int PH_WEIGHT_MODIFIER_D = 100;
const int PH_MENTAL_HEALTH_MODIFIER_E = -23;
const int PH_WEIGHT_MODIFIER_E = 44;

class Pharmacy
{
  private:
    float m_cost_per_use;
    short m_num_uses;
    short m_num_pills;
  public:
    Pharmacy();
    float get_cost_per_use() const{return m_cost_per_use;}
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (ostream& out, const Pharmacy& pharm);
};

#endif