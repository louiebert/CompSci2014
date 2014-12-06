//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: patient.cpp                             Class: CS 1570, Section D
//Purpose: Body file for patient class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "patient.h"
using namespace std;


Patient::Patient()
{
  short count=0;
  short numNames=0;
  short randNum;
  ifstream in;
  m_condition=rand()%(MAX_CONDITION-MIN_CONDITION+1)+MIN_CONDITION;
  m_money=rand()%(MAX_MONEY-MIN_MONEY+1)+MIN_MONEY;
  if(m_condition==0)
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
  return;
}

void Patient::kill()
{
  if(m_condition==0)
    m_is_alive=false;
  return;
}

void Patient::modify_health(const int condition_dif)
{
  m_condition+=condition_dif;
  kill();
  return;
}

ostream& operator <<(ostream& o,const Patient& p)
{
  o<<p.m_name<<" has $"<<p.m_money<<", a health value of "<<p.m_condition
  <<", and is "<<(p.m_is_alive?"":"not ")<<"alive.";
  return o;
}
