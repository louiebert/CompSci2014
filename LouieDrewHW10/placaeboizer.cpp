//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: placaeboizer.cpp          Class: CS 1570, Section D
//Purpose: Body file for placaeboizer class

#include "placaeboizer.h"

void Placaeboizer::charge_patient(Patient& patient) const
{
  patient.pay_out(m_cost_per_use);

  return;
}

void Placaeboizer::apply(Patient& patient)
{
  patient.modify_mental_health((patient.MAX_MCONDITION -
    patient.get_mental_health)/2);
  patient.modify_weight(WEIGHT_MODIFIER);
  m_num_uses++;

  return;
}

ostream& operator << (ostream& out, const Placaeboizer& placae)
{
  out << "Placaeboizer:(Cost Per Use: " << placae.m_cost_per_use << ", Uses: "
    << placae.m_num_uses << ")";

  return out;
}