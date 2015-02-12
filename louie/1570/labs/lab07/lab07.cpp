//Programmer: LOUIE BERTONCIN       Date: 10/14/2014
//File: lab07.cpp                   Class: CS 1580, Section D
//Purpose: Main file for structs and functions lab

#include <iostream>
#include "lab07.h"

using namespace std;

int main()
{
  int choice;
  bool active = true;
  Pixel clrPxl;

  greeting();

  do
  {
    do
    {
      display_menu(choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1)
    {
      getPixel(clrPxl);
      output(clrPxl, rgbToGray(clrPxl));
    }
    else
      active = false;
  } while (active);

  goodbye();

  return 0;
}
