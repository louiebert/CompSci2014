//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: lobotomizer.cpp           Class: CS 1570, Section D
//Purpose: Body file for lobotomizer class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "lobotomizer.h"

void Lobotomizer::charge_patient(Patient& patient) const
{
  patient.pay_out(m_cost_per_use);
}

void Lobotomizer::apply(Patient& patient)
{
  patient.modify_mental_health(MENTAL_HEALTH_MODIFIER);
  patient.modify_physical_health(PHYSICAL_HEALTH_MODIFIER);
  if(rand()%100 < 3)
  {
    patient.modify_mental_health(-patient.get_mental_health);
  }
  if(rand()%100 < 10)
  {
    patient.add_to_name(get_random_name());
  }

  return;
}

string Lobotomizer::get_random_name()
{
  ifstream in;
  string aName;
  int count = 0, pickNum;
  in.open(NAMES_FILE.c_str());
  getline(in, aName);
  while(!in.eof())
  {
    count++;
    in.ignore(500, '\n');
    getline(in, aName);
  }
  pickNum = rand()%(count+1);
  for(int i = 0; i <= pickNum; i++)
  {
    getline(in, aName);
  }

  return aName;
}

ostream& operator << (ostream& out, const Lobotomizer& lobot)
{
  out << "Lobotomizer(Cost Per Use: " << lobot.m_cost_per_use << ", Uses: " <<
    lobot.m_num_uses << ")";

  return out;
}