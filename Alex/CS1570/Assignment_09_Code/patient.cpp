// Programmer: ALEX SHAW                   Date: 11-16-14
// File: patient.cpp                       Class: CS1570 Section B
// Purpose: This file contains the implementation of the functions belonging
// to the class that simulates a patient.

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

patient::patient(const float money, const int condition)
{
  m_money = money;
  m_condition = condition;
  kill();
  ifstream fin;
  open_connection(fin, NAMES_FILE);
  for(int i = 0; i < random_num(1, num_el(fin)); i++)
  {
    fin >> m_name;
  }
  fin.close();
}

void patient::pay_out(const float amt)
{
  m_money -= amt;
  return;
}

void patient::kill()
{
  if(!m_condition)
  {
    m_is_alive = 0;
  }
  return;
}

void patient::modify_health(const int factor)
{
  m_condition /= factor;
  kill();
  return;
}

ostream & operator<<(ostream & o, patient & p)
{
  o << p.m_name << " has $" << p.m_money << ", has a condition of "
    << p.m_condition << " and is " << ((p.m_is_alive)? "" : "not") << " alive."
    << endl;
  return o;
}
