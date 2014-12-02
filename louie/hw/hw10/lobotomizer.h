//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: lobotomizer.h             Class: CS 1570, Section D
//Purpose: Header file for lobotomizer class

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

#include <iostream>
#include "Patient.h"

const int COST_OF_USE = 200;
const int MENTAL_HEALTH_MODIFIER = 10;
const int HEALTH_MODIFIER = 3;

class Lobotomizer
{
  private:
    float cost_per_use;
    short num_uses;
  public:
    Lobotomizer();
    void charge_patient(Patient& patient) const;
    void apply(Patient& patient);
    friend ostream& operator << (const ostream& out, const Lobotomizer& lobot);
};

#endif