// Programmer: Brendan Curran             Date: 11/19/2014
// File: xray.cpp        		              Class: CS 1570 Sec C
// Description: 

#include "patient.h"
#include "xray.h"
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

patient::patient()
{
  int numNames, selection;
  string read;
  m_money = rand()%PATIENT_MAX_MONEY;
  
  m_condition = rand()%101;
  m_mentalCondition = rand()%101;
  m_weight = rand()%101 + 120;
  
  if (m_condition==0)
    m_isAlive = false;
  else
    m_isAlive = true;
  
  ifstream in;
  in.open("names.txt");
 
  in >> numNames;
  
  selection = rand()%numNames;
  
  for (int i =0; i< numNames; i++)
  {
    in >> read;
    if (i == selection)
      strcpy (m_name, read.c_str());
  }
  in.close(); 
  
}

void patient::payOut (const int amount)
{
  m_money -= amount;
  return;
}

void patient::modifyHealth (const int amount)
{
  m_condition += amount;
  kill();
  return;
}

void patient::kill()
{
  if (m_condition <= 0)
    m_isAlive = false;
  return;
}

int patient::getCondition() const
{
  return (m_condition);
}
ostream& operator << (ostream& stream, patient& pat)
{
  stream << "Patient name : " << pat.m_name << endl;
  stream << "Condition: " << pat.m_condition << endl;
  stream << "Status: " << (pat.m_isAlive ? "alive" : "dead") << endl;
  stream << "Money: $" << pat.m_money;
  return stream;
}