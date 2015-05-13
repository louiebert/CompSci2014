//Programmer: LOUIE BERTONCIN     Date: 5/3/2015
//File: ship.hpp                  Class: CS 1510, Section C
//Purpose: Definitions for Ship Class functions

#include <iostream>
#include "ship.h"

using namespace std;

Ship::Ship(const Ship& rhs)
{
  *this = rhs;
}

void Ship::fuel()
{
  if(fuelTimeUnits > 0)
    --fuelTimeUnits;
}

bool Ship::isDoneFueling()
{
  if(fuelTimeUnits > 0)
  {
    return false;
  }
  return true;
}

int Ship::getFuelUnits()
{
  return fuelUnits;
}

int Ship::getArrivalTime()
{
  return arrivalTime;
}

int Ship::calcWaitTime(int& currentTime)
{
  waitTime = currentTime - arrivalTime + 1;
  return waitTime;
}

int Ship::getWaitTime()
{
  return waitTime;
}

string Ship::getName()
{
  return name;
}