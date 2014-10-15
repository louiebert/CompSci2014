//Programmer: LOUIE BERTONCIN       Date: 10/14/2014
//File: lab07_functions.cpp         Class: CS 1580, Section D
//Purpose: Function definitions file for structs and functions lab

#include <iostream>
#include "lab07.h"
#include "lab07.hpp"

using namespace std;

void greeting()
{
  cout << "\n\nWelcome to the Grayscale Pixel Converter,\nwhere all your black"
    " and white dreams come to life!\n\n" << endl;

  return;
}

void display_menu(int & user_choice)
{
  cout << "Please choose from the options below...\n" << endl;
  cout << "1. Convert a pixel" << endl;
  cout << "2. I'm all done" << endl << endl;
  cout << "Your choice: ";
  cin >> user_choice;
  cout << endl;
  return;
}

void getPixel(Pixel & pxl)
{
  int red;
  int green;
  int blue;

  cout << "Please insert the RGB values for your favorite pixel..." << endl;
  cout << "Red value (0-255): ";
  cin >> red;
  cout << "Green value (0-255): ";
  cin >> green;
  cout << "Blue value (0-255): ";
  cin >> blue;
  pxl.red = static_cast<unsigned char>(red);
  pxl.green = static_cast<unsigned char>(green);
  pxl.blue = static_cast<unsigned char>(blue);
  cout << endl;

  return;
}

unsigned char rgbToGray(const Pixel p)
{
  return rgbToGray(p.red, p.green, p.blue);
}

void output(const Pixel p, const unsigned char grayValue)
{
  cout << "The pixel with RGB value of (" << static_cast<int>(p.red) << ", "
    << static_cast<int>(p.green) << ", " << static_cast<int>(p.blue) <<
    ") converted to grayscale is: " << static_cast<int>(grayValue)
    << endl << endl;

  return;
}

void goodbye()
{
  cout << "Thanks for using the best pixel converter this planetary system's"
    " got!!" << endl;

  return;
}
