// Programmer: ALEX SHAW                   Date: 11-16-14
// File: x_rayer.cpp                       Class: CS1570 Section B
// Purpose: This file contains the implementation of the functions belonging to
//  the class that simulates an x-ray machine.

#include "x_rayer.h"
#include "hospital_room.h"
#include "patient.h"
#include "hw09.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

x_rayer::x_rayer(const int uses, const float cost)
{
  m_num_uses = uses;
  m_cost_per_use = cost;
}

void x_rayer::charge_patient(patient & p) const
{
  p.pay_out(m_cost_per_use);
  return;
}

void x_rayer::apply(patient & p) const
{
  if (random_num() <= APPLY_RANGE)
  {
    p.modify_health();
  }
  return;
}
ostream & operator<<(ostream & o, x_rayer & x)
{
  o << "This x-ray machine costs $" << x.m_cost_per_use << " per use and has "
    << " been used " << x.m_num_uses << " times." << endl;
  return o;
}

void x_rayer::increment_uses(const int num)
{
  m_num_uses += num;
}
