//Programmer: LOUIE BERTONCIN     Date: 10/11/2014
//File: h6.cpp                    Class: CS 1570, Section D
//Purpose: This file contains the main function for the program that detects
//  protein levels in a fake patient to diagnose Jejunal Hemorrhage Syndrome.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "h6.h"

using namespace std;

int main()
{
  srand(time(NULL));

  bool active = true, did_hear = true;
  int choice, prot1, prot3, prot4, prot5;
  float prot2;
  proteins patient_prots;
  string name;

  greeting();

  do
  {
    do
    {
      display_menu(choice);
    }while (choice != 1 && choice != 2);

    if (choice == 1)
    {
      get_name(name);
      a_flat(prot1, prot2, prot3);
      if (did_hear)
      {
        middle_g(prot2, prot4);
      }
      if (did_hear)
      {
        c_flat(prot1, prot4, prot5);
      }
      if (did_hear)
      {
        printDiagnosis(diagnose(make_a_proteins(prot1, prot2, prot3, prot4,
          prot5, patient_prots)), name, patient_prots);
      }
    }
    else
      active = false;

  } while (active);

  goodbye();

  return 0;
}
