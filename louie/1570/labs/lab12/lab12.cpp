//Programmer: LOUIE BERTONCIN     Date: 11/18/2014
//File: lab12.cpp                 Class: CS 1580, Section D
//Purpose: Main file for Chemistry file.

#include <iostream>
#include <fstream>
#include "compound.h"

using namespace std;

int main()
{
  Compound blank, first, second, third;
  cout << "BLANK: " << blank << endl << endl;

  cout << "First Compound: ";
  cin >> first;
  cin.ignore(500, '"');
  cout << "Second Compound: ";
  cin >> second;

  third = first + second;

  cout << endl << "Compound 1: " << first << endl;
  cout << "Compound 2: " << second << endl;
  cout << ""Addition Result:" " << third << endl;
  cout << ""Multiplication Result:" " << third*13.4 << endl;



  return 0;
}