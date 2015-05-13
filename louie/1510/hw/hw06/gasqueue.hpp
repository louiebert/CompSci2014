//Programmer: LOUIE BERTONCIN     Date: 5/3/2015
//File: gasqueue.hpp              Class: CS 1510, Section C
//Purpose: Definitions for GasQueue Class functions

#include <iostream>
#include "gasqueue.h"

using namespace std;


GasQueue::~GasQueue()
{
  if(longestWait != NULL)
    delete longestWait;
  if(shortestWait != NULL)
    delete shortestWait;
  while(front != NULL)
    pop();
}

int GasQueue::getLength()
{
  return length;
}

bool GasQueue::isEmpty()
{
  if(length > 0)
    return false;
  return true;
}

void GasQueue::addShip(int fuel, int arrvlTime, string nm)
{
  ++length;
  if (front == NULL)
  {
    front = new Ship(fuel, arrvlTime, nm);
    return;
  }
  Ship* temp = front;
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = new Ship(fuel, arrvlTime, nm);
}

void GasQueue::passTime()
{
  ++currentTime;
  if(front == NULL)
    return;
  front->fuel();
  if(front->isDoneFueling())
  {
    front->calcWaitTime(currentTime);
    if(longestWait == NULL)
      longestWait = new Ship(*front);
    if(shortestWait == NULL)
      shortestWait = new Ship(*front);
    if(longestWait->getWaitTime() < front->getWaitTime())
    {
      delete longestWait;
      longestWait = NULL;
      longestWait = new Ship(*front);
    }
    if(shortestWait->getWaitTime() > front->getWaitTime())
    {
      delete shortestWait;
      shortestWait = NULL;
      shortestWait = new Ship(*front);
    }

    cout << "At time " << currentTime << " " << front->getName() <<
      " is done fueling." << endl;

    pop();
  }
}

Ship* GasQueue::getLongestWait()
{
  return longestWait;
}

Ship* GasQueue::getShortestWait()
{
  return shortestWait;
}

void GasQueue::pop()
{
  if(isEmpty())
    return;
  Ship* temp = front;
  front = front->next;
  delete temp;
  --length;
}

