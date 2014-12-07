//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: hospital_room.cpp                       Class: CS 1570, Section D
//Purpose: Body file for hospital_room class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hospital_room.h"
#include "x_rayer.h"


using namespace std;

template <class T_machine>
void hospital_room<T_machine>::admit(Patient & p,Doctor & d)
{
  short numApps, numAppsAferDeath = 0;
  short oz_schraut = rand()%(MAXSCHRAUT-MINSCHRAUT+1)+MINSCHRAUT;

  if(p.get_physical_health() > 0 && p.getMoney() >=
    m_the_machine.get_cost_per_use())
  {
    if(m_schrautOz - oz_schraut <= 0)
    {
      oz_schraut = m_schrautOz;
      m_schrautOz = 0;
    }
    else
      m_schrautOz -= oz_schraut;

    d.drink_schraut(oz_schraut);
    numApps = d.get_oz_schraut()-5;
    if(numApps < 0)
      numApps = 0;
    if(oz_schraut)
      numApps *= 2;

    for(int i = 0; i < numApps; i++)
    {
      if(p.get_physical_health())
        m_the_machine.apply(p);
      else
        numAppsAferDeath++;
    }

    numApps -= numAppsAferDeath;
    if(numApps > 0)
    {
      m_the_machine.charge_patient(p);
      d.increase_money(m_the_machine.get_cost_per_use()/2);
    }
  }
  else
    numApps = 0;
  cout << "Number of Applications: " << numApps << endl;
  return;
}

template <class U_machine>
ostream& operator <<(ostream& o,const hospital_room <U_machine> & h)
{
  o<<h.m_the_machine<<"    Ounces of Schraut!: "<<h.m_schrautOz;
  return o;
}
