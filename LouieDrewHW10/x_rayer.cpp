//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/17/2014
//File: x_rayer.cpp                             Class: CS 1570, Section D
//Purpose: Body file for x_rayer class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "x_rayer.h"
using namespace std;

void X_Rayer::charge_patient(Patient & patient)const
{
  patient.pay_out(m_cost_per_use);
  return;
}

void X_Rayer::apply(Patient & patient)
{
  const short PERCENT_FAIL=1;
  int randNum = rand()%100;
  if(randNum<PERCENT_FAIL)
    patient.modify_physical_health(-patient.get_physical_health()/2);
  m_num_uses++;

  return;
}

ostream& operator << (ostream& out, const X_Rayer& x)
{
  out << "X_Rayer(Cost Per Use: " << x.m_cost_per_use << ", Uses: " <<
    x.m_num_uses << ")";

  return out;
}
