// Programmer: Brendan Curran              Date: 10/28/2014
// File: h7main.cpp                        Class: CS 1570 Sec C
// Description: completes research to test for zombie-ism by
// qualities and dna testing, outputs results
// utilizes functions from implementation file

#include <iostream>
#include "h7header.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  int numstudy;
  
  srand(time(NULL));
  cout << "Welcome to Dr. Eloe's research study on zombie-ism" << endl;
  cout << "Enter the number of people in this study (1-5000): ";
  cin >> numstudy;
  cout << endl;
  person patientArray[studyMax];
  
  for (int i = 0; i<numstudy; i++)
  {
    assignData(patientArray[i]);
  }
  results (patientArray, numstudy);
  cout <<"We hope you enjoyed our research" << endl;
  
  
}
