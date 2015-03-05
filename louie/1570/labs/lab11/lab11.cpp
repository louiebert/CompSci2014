//Programmer: LOUIE BERTONCIN     Date: 11/11/2014
//File: lab11.cpp                 Class: CS 1580, Section D
//Purpose: Main file for OOP lab.

#include <iostream>
#include "lab11.h"

using namespace std;

int main()
{
  greeting();

  do
  {
    Speed_recorder spd = make_speed_recorder();
    summary(spd);

    while(add_speeds())
    {
      more_speeds(spd);
      summary(spd);
    }
  } while(again());

  goodbye();

  return 0;
}
