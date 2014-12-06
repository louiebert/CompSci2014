//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: patient.cpp                             Class: CS 1570, Section D
//Purpose: Body file for patient class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include "patient.h"

using namespace std;

Patient::Patient()
{
  short count=0;
  short numNames=0;
  short randNum;
  ifstream in;
  m_physCondition=rand()%(MAX_PCONDITION-MIN_PCONDITION+1)+MIN_PCONDITION;
  m_mentCondition=rand()%(MAX_MCONDITION-MIN_MCONDITION+1)+MIN_MCONDITION;
  m_weight=rand()%(MAX_WEIGHT-MIN_WEIGHT+1)+MIN_WEIGHT;
  m_money=rand()%(MAX_MONEY-MIN_MONEY+1)+MIN_MONEY;
  if(m_physCondition==0)
    m_is_alive=false;
  else
    m_is_alive=true;
  in.open(name_file);
  while(in>>m_name)
  {
    numNames++;
  }
  in.close();
  randNum=rand()%numNames;
  in.open(name_file);
  in>>m_name;
  while(count!=randNum)
  {
    in>>m_name;
    count++;
  }
  count=0;
  numNames=0;
  in.close();
}

void Patient::pay_out(const float pay_amount)
{
  m_money-=pay_amount;
  if(m_money<0)
    m_money=0;
  return;
}

void Patient::kill()
{
  m_is_alive=false;
  return;
}

void Patient::modify_physical_health(const int condition_dif)
{
  m_physCondition+=condition_dif;
  if(m_physCondition<0)
    m_physCondition=0;
  if(m_physCondition == 0)
    kill();
  return;
}

void Patient::modify_mental_health(const int amount)
{
  m_mentCondition-=amount;
  if(m_mentCondition<0)
    m_mentCondition=0;
  return;
}

void Patient::add_to_name(const string name)
{
  m_name+=name;
  return;
}

void Patient::modify_weight(const int amount)
{
  m_weight+=amount;
  return;
}

void Patient::modify_mental_health(const int amount)
{
  m_mentCondition+=amount;
  if(m_mentCondition<0)
    m_mentCondition=0;
  return;
}

void Patient::add_to_name(const string name)
{
  m_name+=name
  return;
}

void Patient::modify_weight(const int amount)
{
  m_weight+=amount
  return;
}

ostream& operator <<(ostream& o,const Patient& p)
{
  o<<p.m_name<<" has $"<<p.m_money<<", a physcial health value of "<<
  p.m_physCondition<<" a mental health value of "<<p.m_mentCondition<<
  " weighs "<<p.m_weight<<" lbs "<<", and is "<<(p.m_is_alive?"":"not ")<<
  "alive.";
  return o;
}
