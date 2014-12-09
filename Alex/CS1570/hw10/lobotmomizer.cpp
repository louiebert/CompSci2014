//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: lobotomizer.cpp    Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Description: Contains the implemenation for the class that simulates
// a Lobotomizer within the program that simulates a patient and a doctor
// visiting hospital rooms.

#include "Lobotomizer.h"
#include "hw10.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

bool Lobotomizer::charge_patient(Patient & p) const
{
  bool paid;
  paid = p.pay_out(LOB_COST_PER_USE);
  return paid;
}

void Lobotomizer::apply(Patient & p)
{
  m_num_uses++;
  p.modify_mental(INCREMEMENT_MENTAL_HEALTH);
  p.modify_health(INCREMENT_PHYSICAL_HEALTH);
  if(rand_num(0, 100) <= VEG_CHANCE)
    p.modify_mental(VEG_STATUS);
  if(rand_num(0, 100) <= NAME_ALTER_CHANCE)
      p.forgot_name();
  return;
}

ostream & operator << (ostream & o, const Lobotomizer & l)
{
  o << "The Lobotomizer has been used " << l.m_num_uses << "at $"
       << l.m_cost_per_use <<" per use.";
  return o;
}
