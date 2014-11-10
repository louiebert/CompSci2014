//Programmer: LOUIE BERTONCIN       Date: 11/5/2014
//File: lab10.cpp                   Class: CS 1580, Section D
//Purpose: Main file for the shift program.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lab10.h"

using namespace std;

int main()
{
  int shiftNum, count = 0;
  ifstream inputStream;
  ofstream outputStream;

  greeting();

  shiftNum = get_shift_amount();
  do
  {
    inputStream.clear();
    inputStream.open(get_input_filename().c_str());
    count++;
  } while (!inputStream && count < 5);

  if(count >= 5)
  {
    goodbye();
    exit(1);
  }

  outputStream.open(get_output_filename().c_str());

  decrypt(inputStream, outputStream, shiftNum);

  inputStream.close();
  outputStream.close();

  goodbye();

  return 0;
}
