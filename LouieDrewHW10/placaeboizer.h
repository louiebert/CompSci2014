//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: placaeboizer.h            Class: CS 1570, Section D
//Purpose: Header file for placaeboizer class

#ifndef PLACAEBOIZER_H
#define PLACAEBOIZER_H

#include <iostream>
#include "patient.h"

// Default constructor sets m_num_uses to 0 and m_cost_per_use to COST_PER_USE.
// Pre: None.
// Post: Sets default values for an Placaeboizer object

// get_cost_per_use() returns the Placaeboizer object's m_cost_per_use.
// Pre: None.
// Post: Returns m_cost_per_use.

// charge_patient() reduces the provided Patient object's m_money by
//   m_cost_per_use.
// Pre: None.
// Post: Reduces Patient object's money.

// apply() increases Patient object's mental health by
//   (MENTAL_HEALTH_MAX - patient.m_mental_health)/2 and increases patient's
//   weight by 50.
// Pre: None.
// Post: Increases patient's mental health and increases patient's weight.

// // Insertion operator prints a Placaeboizer object
// Pre: None.
// Post:Format- Placaeboizer(Cost Per Use: <m_cost_per_use>, Uses: <m_num_uses>)

const float COST_PER_USE = 500;
const int WEIGHT_MODIFIER = 50;

class Placaeboizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;
  public:
    Placaeboizer():m_num_uses(0),m_cost_per_use(COST_PER_USE){}
    float get_cost_per_use() const{return m_cost_per_use;}
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (ostream& out, const Placaeboizer& placae);
};

#endif
