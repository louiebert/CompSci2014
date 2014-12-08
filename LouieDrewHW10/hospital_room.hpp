//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: hospital_room.cpp                       Class: CS 1570, Section D
//Purpose: Body file for Hospital_Room class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hospital_room.h"
#include "x_rayer.h"


using namespace std;

template <class T_machine>
void Hospital_Room<T_machine>::admit(Patient& p, Doctor& dr)
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

    dr.drink_schraut(oz_schraut);
    numApps = dr.get_oz_schraut()-5;
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
      dr.increase_money(m_the_machine.get_cost_per_use()/2);
    }
  }
  else
    numApps = 0;
  cout << "Number of Applications: " << numApps << endl;
  return;
}

template <class U_machine>
ostream& operator <<(ostream& out,const Hospital_Room <U_machine> & hr)
{
  out << hr.m_the_machine << "\n\tRemaining ounces of Schraut!: " <<
    hr.m_schrautOz;
  return out;
}
