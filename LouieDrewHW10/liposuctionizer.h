//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: liposuctionizer.h         Class: CS 1570, Section D
//Purpose: Header file for liposuctionizer class

#ifndef LIPOSUCTIONIZER_H
#define LIPOSUCTIONIZER_H

#include <iostream>
#include "patient.h"

// Default constructor sets m_num_uses to 0 and m_cost_per_use to COST_PER_USE.
// Pre: None.
// Post: Sets default values for an Liposuctionizer object

// get_cost_per_use() returns the Liposuctionizer object's m_cost_per_use.
// Pre: None.
// Post: Returns m_cost_per_use.

// charge_patient() reduces the provided Patient object's m_money by
//   m_cost_per_use.
// Pre: None.
// Post: Reduces Patient object's money.

// apply() decreases Patient object's weight by 10%, increases patient's mental
//   health by 20, and every 61 times the machine is used, it kills the patient.
// Pre: None.
// Post: Decreases weight, increases mental health, and has a chance to kill.

// Insertion operator prints a Liposuctionizer object
// Pre: None.
// Post: Format -
//   Liposuctionizer(Cost Per Use: <m_cost_per_use>, Uses: <m_num_uses>)

const float LIP_COST_PER_USE = 750;
const float LIP_WEIGHT_PERCENT_MODIFIER = 0.1;
const int LIP_MENTAL_HEALTH_MODIFIER = 20;
const int LIP_REPEATS_TIL_DEATH = 61;

class Liposuctionizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;
  public:
    Liposuctionizer():m_num_uses(0),m_cost_per_use(LIP_COST_PER_USE){}
    float get_cost_per_use() const{return m_cost_per_use;}
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (ostream& out, const Liposuctionizer& lipo);
};

#endif
