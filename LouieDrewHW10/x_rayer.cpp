//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/17/2014
//File: x_rayer.cpp                             Class: CS 1570, Section D
//Purpose: Body file for x_rayer class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "x_rayer.h"
using namespace std;

void x_rayer::charge_patient(Patient & p)const
{
  p.pay_out(m_cost);
  return;
}
void x_rayer::apply(Patient & p)
{
  const short PERCENT_FAIL=1;
  int randNum = rand()%100;
  if(randNum<PERCENT_FAIL)
    p.modify_physical_health(-p.get_physical_health()/2);
  m_num_uses++;
  return;
}

ostream& operator <<(ostream& o,const x_rayer& x)
{
  o<<"Number of Uses: "<<x.m_num_uses<<"  Cost: $"<<x.m_cost;
  return o;
}
