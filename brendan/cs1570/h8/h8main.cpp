// Programmer: Brendan Curran             Date: 11/11/2014
// File: h8main.cpp                       Class: CS 1570 Sec C
// Description: asks a user for their medical complaint, grabs a random
// diagnosis from a data file, creates a random drug and surgery to prescribe
// to the user 

#include <iostream>
#include "h8headers.h"
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
  string ComplaintTemp;
  char complaint[COMPLAINTLENGTH];
  char shortComp[COMPLAINTLENGTH];
  char diagnosis[20];
  char drug[20];
  char surgery[20];
  char ans;
  int compSize, numPills;
  bool again = true;
  srand(time(NULL));
  
  greeting();
  
  while (again)
  {
	strcpy(drug, " ");
    ComplaintTemp = getComplaint();
  
    strcpy(complaint, ComplaintTemp.c_str());
    compSize = strlen(complaint);
    strcpy(shortComp, complaint);
    
    shortComplaint(shortComp, compSize, numPills);
    
    diagnose(diagnosis);
    prescribe(drug, surgery);
    output(shortComp, diagnosis, numPills, drug, surgery);
    
    cout << "Would you like to use this program again: (y/n) : ";
    cin >> ans;
    if (ans != 'y' && ans != 'Y')
      again = false;
	cin.ignore(500, '"');
  }
  return 0;
}