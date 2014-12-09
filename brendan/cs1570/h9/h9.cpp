// Programmer: Brendan Curran             Date: 11/19/2014
// File: h9.cpp        		              Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include "hospitalRoom.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  srand(time(NULL));  
  
  hospitalRoom room1;
  
  patient pat1, pat2, pat3;
  cout << "Room status: " <<endl << room1 << endl << endl;
  cout << pat1 << endl << endl;
  cout << pat2 << endl << endl;
  cout << pat3 << endl << endl;
  
  for (int i= 0; i<5; i++)
  {
    room1.admit(pat1);
  }
  
  cout << room1 << endl << endl;
  cout << pat1 << endl;
  
  
  return 0;
}