//Programmer: LOUIE BERTONCIN     Date: 11/11/2014
//File: Speed_recorder.h          Class: CS 1580, Section D
//Purpose: Functions for Speed_recorder class to represent a company's
//  Speedometer.

#include <iostream>
#include "Speed_recorder.h"

using namespace std;

Speed_recorder::Speed_recorder(const int company_id)
{
  id = company_id;
  numberOfEntries = 0;
  averageSpeed = 0;
}

void Speed_recorder::addSpeed(int speed)
{
  numberOfEntries++;
  averageSpeed = (averageSpeed*(numberOfEntries-1) + speed)/numberOfEntries;
  return;
}

int Speed_recorder::getId() const
{
  return id;
}

int Speed_recorder::getTotalEntries() const
{
  return numberOfEntries;
}

float Speed_recorder::getAverageSpeed() const
{
  return averageSpeed;
}
