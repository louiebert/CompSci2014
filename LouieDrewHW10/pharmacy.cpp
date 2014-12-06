//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: pharmacy.cpp              Class: CS 1570, Section D
//Purpose: Body file for pharmacy class

#include "pharmacy.h"

Pharmacy::Pharmacy()
{
  m_num_uses = 0;
  m_cost_per_use = 150;
  m_num_pills = rand()%(PH_PILL_NUM_MAX+1-PH_PILL_NUM_MIN) + PH_PILL_NUM_MIN;
}

void Pharmacy::charge_patient(Patient& patient) const
{
  patient.pay_out(m_cost_per_use);

  return;
}

void Pharmacy::apply(Patient& patient)
{
  if(m_num_pills > 0)
  {
    int chance = rand()%100;
    m_num_pills--;
    if(chance < 25)
    {
      patient.modify_physical_health(PH_PHYSICAL_HEALTH_MODIFIER_A);
      patient.modify_mental_health(PH_MENTAL_HEALTH_MODIFIER_A);
    }
    else if(chance < 50 && chance >= 25)
    {
      patient.modify_physical_health(PH_PHYSICAL_HEALTH_MODIFIER_B);
      patient.modify_mental_health(-patient.get_mental_health());
    }
    else if(chance < 75 && chance >= 50)
    {
      patient.modify_physical_health(PH_PHYSICAL_HEALTH_MODIFIER_C -
        patient.get_physical_health());
    }
    else
    {
      patient.modify_mental_health(PH_MENTAL_HEALTH_MODIFIER_D -
        patient.get_mental_health());
      patient.modify_weight(PH_WEIGHT_MODIFIER_D);
    }
  }
  else
  {
    patient.modify_mental_health(PH_MENTAL_HEALTH_MODIFIER_E);
    patient.modify_weight(PH_WEIGHT_MODIFIER_E);
  }

  m_num_uses++;

  return;
}

ostream& operator << (ostream& out, const Pharmacy& pharm)
{
  out << "Pharmacy:(Cost Per Use: " << pharm.m_cost_per_use << ", Uses: " <<
    pharm.m_num_uses << ", Pills Left: " << pharm.m_num_pills << ")";

  return out;
}
