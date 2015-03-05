//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: x_rayer.cpp               Class: CS 1570, Section D
//Purpose: Body file for x_rayer class

#include "x_rayer.h"

using namespace std;


X_rayer::X_rayer()
{
  num_uses = DEF_NUM_USES;
  cost_per_use = DEF_COST_OF_USE;
}

void X_rayer::charge_patient(Patient& ptnt) const
{
  ptnt.pay_out(cost_per_use);
  return;
}

void X_rayer::apply(Patient& ptnt) const
{
  if(rand()%101 < CHANCE_OF_MUTILATION)
    ptnt.modify_health(ptnt.get_condition()/-FACTOR_OF_MUTILATION);
  return;
}

ostream& operator << (ostream& out, const X_rayer& x_ray)
{
  out << "X-Rayer(# of uses: " << x_ray.num_uses << ", cost per use: " <<
    x_ray.cost_per_use << ")";
  return out;
}