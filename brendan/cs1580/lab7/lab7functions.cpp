// Programmer: Brendan Curran              Date: 10/14/2014
// File: lab7functions.cpp                 Class: CS 1580 Sec D
// Description: 

#include <iostream>
#include "lab7header.h"
#include "lab7template.hpp"
using namespace std;

unsigned char rgbToGray(const Pixel p)
{
  //running templated function using float values from struct pixel
  char temp = rgbToGray(p.m_red, p.m_green, p.m_blue);
  return temp;
}

void output(const Pixel p, const unsigned char grayValue)
{
  int temp = grayValue;
  cout << "<" << p.m_red << "," << p.m_green << "," << p.m_blue << "> ->";
  cout << temp << endl;
  cout << endl;
}

Pixel getPixel()
{
  Pixel temp;
  cout <<"Please enter a pixel: " << endl;
  cout <<"Red: ";
  cin >> temp.m_red;
  cout <<"Green: ";
  cin >> temp.m_green;
  cout <<"Blue: ";
  cin >> temp.m_blue;
  return temp;
}