// Programmer: Brendan Curran             Date: 10/7/2014
// File: doctor.cpp     		              Class: CS 1570 Sec C
// Description: 


#include "doctor.h"
#include <iostream>

using namespace std;

void doctor::consumeSchraut(int amount)
{
  m_schrautConsumed +=amount;
  if (m_schrautConsumed >=25)
    (*this).puke();
}

ostream& operator << (ostream& stream, doctor &doc)
{
  stream << "Doctor " << doc.m_name << " has consumed ";
  stream << doc.m_schrautConsumed << " ounces of schraut " << " and has $";
  stream << doc.m_money;
  return stream;
}