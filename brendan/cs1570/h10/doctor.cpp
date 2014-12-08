// Programmer: Brendan Curran             Date: 10/7/2014
// File: doctor.cpp     		              Class: CS 1570 Sec C
// Description: 


#include "doctor.h"



void doctor::consumeSchraut(int amount)
{
  m_schrautConsumed +=amount;
  if (m_schrautConsumed >=25)
    (*this).puke();
}