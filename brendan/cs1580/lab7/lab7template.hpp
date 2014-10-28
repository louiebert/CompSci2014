// Programmer: Brendan Curran              Date: 10/14/2014
// File: lab7template.hpp                  Class: CS 1580 Sec D
// Description: contains template function for 

#ifndef LAB7TEMPLATE_HPP
#define LAB7TEMPLATE_HPP

//Description: converts 3 color values to a single gray intensity value
//Pre: three values of the same type, red, green, then blue value
//Post: returns the gray value of the same type as rgb type
template < typename T>
T rgbToGray(const T red, const T green, const T blue)
{
  T gray = (.2126*red)+(.7152*green)+(.0722*blue);
  return gray;
}

#endif