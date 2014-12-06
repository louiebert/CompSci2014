//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: organ_donor.h             Class: CS 1570, Section D
//Purpose: Header file for organ_donor class

#ifndef ORGAN_DONOR_H
#define ORGAN_DONOR_H

#include <iostream>
#include "patient.h"

// Default constructor sets m_num_uses to 0 and m_cost_per_use to COST_PER_USE.
// Pre: None.
// Post: Sets default values for an Organ_Donor object

// get_cost_per_use() returns the Organ_Donor object's m_cost_per_use.
// Pre: None.
// Post: Returns m_cost_per_use.

// charge_patient() reduces the provided Patient object's m_money by
//   m_cost_per_use.
// Pre: None.
// Post: Reduces Patient object's money.

// apply() increases Patient object's mental health by 10, decreases their
//   physical health by a random value between 0 and 20, has a 10% chance of
//   killing the patient, and decreases patient's weight by 10.
// Pre: None.
// Post: Increases patient's mental health, decreases physical, may kill, and
//   decreases patient's weight.

// // Insertion operator prints a Organ_Donor object
// Pre: None.
// Post: Format- Organ Donor(Cost Per Use: <m_cost_per_use>, Uses: <m_num_uses>)

const float COST_PER_USE = 100;
const int MENTAL_HEALTH_MODIFIER = 10;
const int PHYSICAL_HEALTH_MOD_MIN = 0;
const int PHYSICAL_HEALTH_MOD_MAX = 20;
const int KILL_CHANCE = 10;
const int WEIGHT_MODIFIER = 10;

class Organ_Donor
{
  private:
    float m_cost_per_use;
    short m_num_uses;
  public:
    Organ_Donor():m_num_uses(0),m_cost_per_use(COST_PER_USE){}
    float get_cost_per_use() const{return m_cost_per_use;}
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (ostream& out, const Organ_Donor& donor);
};

#endif