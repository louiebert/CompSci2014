//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: liposuctionizer.cpp       Class: CS 1570, Section D
//Purpose: Body file for liposuctionizer class

#include "liposuctionizer.h"

void Liposuctionizer::charge_patient(Patient& patient) const
{
  patient.pay_out(m_cost_per_use);

  return;
}

void Liposuctionizer::apply(Patient& patient)
{
  patient.modify_weight(-patient.get_weight()*LIP_WEIGHT_PERCENT_MODIFIER);
  patient.modify_mental_health(LIP_MENTAL_HEALTH_MODIFIER);

  m_num_uses++;
  if(!m_num_uses%LIP_REPEATS_TIL_DEATH)
    patient.modify_physical_health(-patient.get_physical_health());

  return;
}

ostream& operator << (ostream& out, const Liposuctionizer& lipo)
{
  out << "Liposuctionizer:(Cost Per Use: " << lipo.m_cost_per_use << ", Uses: "
    << lipo.m_num_uses << ")";

  return out;
}
