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
  if (m_condition > 100)
    m_condition = 100;
  kill();
  return;
}

void patient::modifyMHealth (const int amount)
{
  m_mentalCondition += amount;
  if (m_mentalCondition > 100)
    m_mentalCondition = 100;
  return;
}

void patient::modifyWeight (const int amount)
{
  m_weight += amount;
  if (m_weight < 1)
    m_weight = 1;
  return;
}

void patient::kill()
{
  if (m_condition <= 0)
    m_isAlive = false;
  return;
}

void patient::forgetName()
{
  int numNames, selection;
  string read;
  ifstream in;
  string hyphen = "_";
  
  strcat(m_name, hyphen.c_str());
  
  in.open("names.txt");
 
  in >> numNames;
  selection = rand()%numNames;
  
  for (int i =0; i< numNames; i++)
  {
    in >> read;
    if (i == selection)
      strcat (m_name, read.c_str());
  }
  in.close(); 
  return;
}

ostream& operator << (ostream& stream, patient& pat)
{
  stream << pat.m_name << " weighs " << pat.m_weight << " pounds w/ MH= ";
  stream << pat.m_mentalCondition << " and PH= " << pat.m_condition;
  stream << " and has $" << pat.m_money; 
  if (!pat.getAlive())
    stream << endl << pat.m_name << " is DEAD";
  return stream;
}