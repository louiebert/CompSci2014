//Programmer: LOUIE BERTONCIN       Date: 10/14/2014
//File: lab07.hpp                   Class: CS 1580, Section D
//Purpose: .hpp file for structs and functions lab

#include <iostream>
#include "lab07.h"

using namespace std;

template < typename T >
T rgbToGray(const T red, const T green, const T blue)
{
  return (REDCONVERT * red) + (GREENCONVERT * green) + (BLUECONVERT * blue);
}
