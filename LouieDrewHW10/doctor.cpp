//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: doctor.cpp                              Class: CS 1570, Section D
//Purpose: Body file for doctor class

#include "doctor.h"

using namespace std;

Doctor::Doctor(const string& theName)
{
  m_money = 0;
  m_name = theName;
}

void Doctor::puke()
{
  m_oz_schraut = 0;

  return;
}

void Doctor::drink_schraut(const short& amount)
{
  m_oz_schraut += amount;

  if(m_oz_schraut >= MAX_OZ_SCHRAUT)
  {
    puke();
  }

  return;
}

void Doctor::increase_money(const float& amount)
{
  m_money += amount;

  return;
}
