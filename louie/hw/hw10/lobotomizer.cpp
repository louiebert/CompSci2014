//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: lobotomizer.cpp           Class: CS 1570, Section D
//Purpose: Body file for lobotomizer class

#include "lobotomizer.h"

Lobotomizer::Lobotomizer()
{
  num_uses = 0;
  cost_of_use = COST_OF_USE;
}

void Lobotomizer::charge_patient(Patient& patient) const
{
  patient.pay_out(cost_of_use);
}

void Lobotomizer::apply(Patient& patient)
{
  patient.modify_mental_health(MENTAL_HEALTH_MODIFIER);
  patient.modify_health(HEALTH_MODIFIER);
  
}