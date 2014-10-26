// Programmer: Brendan Curran              Date: 10/14/2014
// File: lab7main.cpp                      Class: CS 1580 Sec D
// Description: 

#include <iostream>
#include "lab7header.h"
#include "lab7template.hpp"
using namespace std;

int main()
{
  Pixel pix; //declaring a struct type Pixel
  unsigned char gray;
  bool loop = true;
  char choice;
  cout <<"Welcome to the pixel grayscale converter\n" << endl;
 
 while (loop)
  {
    pix = getPixel(); //gets pixel from user
    gray = rgbToGray(pix); //gets grayscale value of pixel
    output(pix, gray); //outputs pixel and grayscale value
    cout <<"Would you like to enter another pixel? (y/n): ";
    cin >> choice;
    if (choice != 'y')
      loop = false;
  }
}