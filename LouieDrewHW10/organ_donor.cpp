//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: organ_donor.cpp           Class: CS 1570, Section D
//Purpose: Body file for organ_donor class

void Organ_Donor::charge_patient(Patient& patient) const
{
  patient.pay_out(m_cost_per_use);

  return;
}

void Organ_Donor::apply(Patient& patient)
{
  patient.modify_mental_health(MENTAL_HEALTH_MODIFIER);
  patient.modify_physical_health(rand()%(PHYSICAL_HEALTH_MOD_MAX + 1 -
    PHYSICAL_HEALTH_MOD_MIN) + PHYSICAL_HEALTH_MOD_MIN);
  if(rand()%100 < KILL_CHANCE)
    patient.kill();
  patient.m_weight -= WEIGHT_MODIFIER;

  m_num_uses++;

  return;
}

ostream& operator << (ostream& out, const Organ_Donor& donor)
{
  out << "Organ Donor:(Cost Per Use: " << donor.m_cost_per_use << ", Uses: " <<
    donor.m_num_uses << ")";

  return out;
}