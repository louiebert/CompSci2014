// Programmer: Brendan Curran              Date: 11/19/2014/2014
// File: compound.h		                   Class: CS 1580 Sec D
// Description: 


#ifndef COMPOUND_H
#define COMPOUND_H

#include <string>
#include <iostream>

using namespace std;

const int ELEMENT_COUNT=112;

class compound
{
  public:
    //Description: Default constructor
    //Pre: None
    //Post: Name is initialized to unknown, mass is initialized to zero,
    //and all elements are initialized to zero
    compound();
    friend ostream& operator << (ostream& stream, compound& value);
    friend istream& operator >> (istream& stream, compound& value); 
    compound operator *(const float amount);
    compound& operator + (const compound& other);
  private:
    std::string m_name;
    int m_elements[ELEMENT_COUNT];
    float m_mass;
    

    
  
};

#endif