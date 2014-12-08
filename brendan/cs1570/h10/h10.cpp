// Programmer: Brendan Curran             Date: 10/7/2014
// File: h10.cpp        		              Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include "doctor.h"
#include "xray.h"
#include "patient.h"
#include "hospitalRoom.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(time(NULL));
  doctor doc("Eloe");
  hospitalRoom<xRayer> roomXray;
  patient patient1;

  cout << "before "<< patient1 << endl;
  cout << roomXray << endl;
  roomXray.admit(patient1, doc);
  cout << patient1 << endl;
  cout << roomXray << endl;
 
  return 0;
}