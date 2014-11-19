//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: x_rayer.cpp               Class: CS 1570, Section D
//Purpose: Body file for x_rayer class

#include "x_rayer.h"

using namespace std;


X_rayer()
{
  num_uses = DEF_NUM_USES;
  cost_per_use = DEF_COST_OF_USE;
}

void charge_patient(Patient & ptnt) const
{
  ptnt.pay_out(cost_per_use);
  return;
}

void apply(Patient & ptnt) const
{
  if(rand()%101 < 10)
    ptnt.modify_health(ptnt.get_condition()/-2);
  return;
}
