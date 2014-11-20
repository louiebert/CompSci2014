// Programmer: Brendan Curran              Date: 11/19/2014
// File: lab12.cpp                         Class: CS 1580 Sec D
// Description: 

#include "compound.h"
#include <iostream>

using namespace std;

int main()
{
  compound comp0, comp1, comp2, comp3;
  cout << "Empty compound: " << comp0 << endl << endl;
  cout << "Enter compound 1: ";
  cin >> comp1;
  cout << "Enter compound 2: ";
  cin >> comp2;
  cout << endl;
  cout << "compound 1: " << comp1 << endl;
  cout << "compound 2: " << comp2 << endl;
  comp3 = comp1+comp2;
  cout << "Addition result: " << comp3 << endl;
  comp3 = comp3*13.4;
  cout << "Multiplication result; " << comp3 << endl;
  return (0);
  
  
}