//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: doctor.cpp                Class: CS 1570, Section D
//Purpose: Body file for doctor class

#include "doctor.h"

using namespace std;

Doctor::Doctor(const string& theName)
{
  money = 0;
  name = theName;
}

void Doctor::puke()
{
  oz_schraut = 0;

  return;
}

void Doctor::drink_schraut(const short& amount)
{
  oz_schraut += amount;

  if(oz_schraut >= MAX_OZ_SCHRAUT)
  {
    puke();
  }

  return;
}

short Doctor::get_oz_schraut() const
{
  return oz_schraut;
}

void Doctor::increase_money(const float& amount)
{
  money += amount;

  return;
}