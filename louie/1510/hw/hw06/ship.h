//Programmer: LOUIE BERTONCIN     Date: 5/3/2015
//File: ship.h                    Class: CS 1510, Section C
//Purpose: Header file for Ship Class

#ifndef SHIP_H
#define SHIP_H

#include <iostream>

using namespace std;

class Ship {
  public:
    Ship* next;

    Ship(): fuelUnits(0), arrivalTime(0), fuelTimeUnits(0), waitTime(0),
      name(NULL), next(NULL) {}
    Ship(int& f, int& a, string& n) : fuelUnits(f), fuelTimeUnits(f*3),
      arrivalTime(a), waitTime(0), name(n), next(NULL) {}
    Ship(const Ship& rhs);
    void fuel();
    bool isDoneFueling();
    int getFuelUnits();
    int getArrivalTime();
    int calcWaitTime(int& currentTime);
    int getWaitTime();
    string getName();

  private:
    int fuelUnits;
    int fuelTimeUnits;
    int arrivalTime;
    int waitTime;
    string name;
};

#include "ship.hpp"

#endif