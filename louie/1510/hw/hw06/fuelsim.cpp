//Programmer: LOUIE BERTONCIN     Date: 5/3/2015
//File: fuelsim.cpp               Class: CS 1510, Section C
//Purpose: Runs the main program

#include <iostream>
#include "gasqueue.h"

using namespace std;

void queueShip(Ship* ship, GasQueue* a, GasQueue* b, GasQueue* c);

int main()
{
  int numShips;
  int timePassed = 0;
  cin >> numShips;

  GasQueue* mainLine = new GasQueue();
  for(int i = 0; i < numShips; ++i)
  {
    int arrivalTime;
    string name;
    int fuelUnits;
    cin >> arrivalTime;
    cin >> name;
    cin >> fuelUnits;
    mainLine->addShip(fuelUnits, arrivalTime, name);
  }

  GasQueue* lineA = new GasQueue();
  GasQueue* lineB = new GasQueue();
  GasQueue* lineC = new GasQueue();
  while(mainLine->isEmpty() == false || lineA->isEmpty() == false ||
    lineB->isEmpty() == false || lineC->isEmpty() == false)
  {
    ++timePassed;
    if(mainLine->front != NULL && timePassed ==
      mainLine->front->getArrivalTime())
    {
      queueShip(mainLine->front, lineA, lineB, lineC);
      mainLine->pop();
    }
    lineA->passTime();
    lineB->passTime();
    lineC->passTime();
  }

  Ship* longWait = lineA->getLongestWait();
  if(lineB->getLongestWait() != NULL)
    if(lineB->getLongestWait()->getWaitTime() > longWait->getWaitTime())
      longWait = lineB->getLongestWait();
  if(lineC->getLongestWait() != NULL)
    if(lineC->getLongestWait()->getWaitTime() > longWait->getWaitTime())
      longWait = lineC->getLongestWait();
  cout << "\nLongest wait: " << longWait->getName() << ", " <<
    longWait->getWaitTime() << " mins." << endl;

  Ship* shortWait = lineA->getShortestWait();
  if(lineB->getShortestWait() != NULL)
    if(lineB->getShortestWait()->getWaitTime() < shortWait->getWaitTime())
      shortWait = lineB->getShortestWait();
  if(lineC->getShortestWait() != NULL)
    if(lineC->getShortestWait()->getWaitTime() < shortWait->getWaitTime())
      shortWait = lineC->getShortestWait();
  cout << "Shortest wait: " << shortWait->getName() << ", " <<
    shortWait->getWaitTime() << " mins." << endl;

  delete mainLine;
  delete lineA;
  delete lineB;
  delete lineC;

  return 0;
}

void queueShip(Ship* ship, GasQueue* a, GasQueue* b, GasQueue* c)
{
  GasQueue* lineToPush = a;
  if(b->getLength() < lineToPush->getLength())
    lineToPush = b;
  if(c->getLength() < lineToPush->getLength())
    lineToPush = c;
  lineToPush->addShip(ship->getFuelUnits(), ship->getArrivalTime(),
    ship->getName());

  if(lineToPush == a)
    cout << "At time " << ship->getArrivalTime() << " " << ship->getName() <<
      " joins port A." << endl;
  else if(lineToPush == b)
    cout << "At time " << ship->getArrivalTime() << " " << ship->getName() <<
      " joins port B." << endl;
  else
    cout << "At time " << ship->getArrivalTime() << " " << ship->getName() <<
      " joins port C." << endl;
}

