//Programmer: LOUIE BERTONCIN     Date: 4/17/2015
//File: robotcalc.cpp             Class: CS 1510, Section C
//Purpose: Runs the main program

#include <iostream>
#include <string>
#include "datastack.h"

using namespace std;

void readin();

int main()
{
  readin();

  return 0;
}

void readin()
{
  string input;
  bool finish = false;

  DataStack<int>* dataStack = new DataStack<int>();

  while(!finish)
  {
    cin >> input;
    if (input == "+")
      dataStack->add();
    else if (input == "-")
      dataStack->subtract();
    else if (input == "*")
      dataStack->multiply();
    else if (input == "/")
      dataStack->divide();
    else if (input == "%")
      dataStack->modulo();
    else if (input == "!")
      dataStack->negate();
    else if (input == "SUM")
      dataStack->sum();
    else if (input == "R")
      dataStack->reverse();
    else if (input == "#")
      cout << dataStack << endl;
    else if (input == "$")
      dataStack->clear();
    else if (input == "@")
      finish = true;
    else
    {
      if (isdigit(input[0]))
      {
        dataStack->push(atoi(input.c_str()));
      }
    }
  }
}
