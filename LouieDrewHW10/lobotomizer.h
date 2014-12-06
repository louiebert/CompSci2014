//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: lobotomizer.h             Class: CS 1570, Section D
//Purpose: Header file for lobotomizer class

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

#include <iostream>
#include "Patient.h"
#include "hw10.h"

const float COST_OF_USE = 200;
const int MENTAL_HEALTH_MODIFIER = 10;
const int PHYSICAL_HEALTH_MODIFIER = 3;

class Lobotomizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;
    string get_random_name();
  public:
    Lobotomizer():m_num_uses(0),m_cost_per_use(COST_OF_USE){};
    float get_cost_per_use(){return m_cost_per_use;}
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (ostream& out, const Lobotomizer& lobot);
};

#endif