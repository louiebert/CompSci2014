//Programmer: LOUIE BERTONCIN     Date: 5/3/2015
//File: gasqueue.h                Class: CS 1510, Section C
//Purpose: Header file for GasQueue Class

#ifndef GASQUEUE_H
#define GASQUEUE_H

#include <iostream>
#include "ship.h"

using namespace std;

class GasQueue {
  public:
    GasQueue(): currentTime(0), length(0), front(NULL), longestWait(NULL),
      shortestWait(NULL) {}
    ~GasQueue();
    int getLength();
    bool isEmpty();
    void addShip(int fuel, int arrvlTime, string nm);
    void passTime();
    Ship* getLongestWait();
    Ship* getShortestWait();

    Ship* front;
    void pop();
  private:
    int currentTime;
    int length;
    Ship *longestWait;
    Ship *shortestWait;
};

#include "gasqueue.hpp"

#endif