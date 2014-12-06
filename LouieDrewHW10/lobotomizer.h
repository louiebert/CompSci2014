//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: lobotomizer.h             Class: CS 1570, Section D
//Purpose: Header file for lobotomizer class

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

#include <iostream>
#include "Patient.h"
#include "hw10.h"

// get_random_name() returns a random name from the project's data file.
// Pre: None.
// Post: Returns a random string from the project's data file.

// The default constructor sets m_num_uses to 0 and m_cost_per_use to
//   COST_OF_USE.
// Pre: None.
// Post: Sets default values for the new Lobotomizer object.

// get_cost_per_use() returns the Lobotomizer object's m_cost_per_use.
// Pre: None.
// Post: Returns m_cost_per_use.

// charge_patient() reduces the provided Patient object's m_money by
//   m_cost_per_use.
// Pre: None.
// Post: Reduces Patient object's money.

// apply() increases Patient object's mental and physical health by 10, has a 3%
//   chance of setting the patient's mental health to 0, and a 10% chance of
//   adding another name onto the current patient's name.
// Pre: None.
// Post: Increases patient's mental and physical health by 10 and has a chance
//   to change other fun things about the patient.

// Insertion operator prints a Lobotomizer object
// Pre: None.
// Post: Format- Lobotomizer(Cost Per Use: <m_cost_per_use>, Uses: <m_num_uses>)

const float COST_OF_USE = 200;
const int MENTAL_HEALTH_MODIFIER = 10;
const int PHYSICAL_HEALTH_MODIFIER = 3;

class Lobotomizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;
    string get_random_name() const;
  public:
    Lobotomizer():m_num_uses(0),m_cost_per_use(COST_OF_USE){};
    float get_cost_per_use() const{return m_cost_per_use;}
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (ostream& out, const Lobotomizer& lobot);
};

#endif
