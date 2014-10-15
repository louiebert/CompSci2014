//Programmer: LOUIE BERTONCIN     Date: 10/11/2014
//File: h6_functions.cpp          Class: CS 1570, Section D
//Purpose: This file contains the definitions of the functions used in the
// program to diagnose Jejunal Hemorrhage Syndrome.

#include <iostream>
#include <cstdlib>
#include "h6.h"

using namespace std;

void greeting()
{
  cout << "Welcome to the Jejunal Hemorrhage Syndrome diagnoser!!\n\n" << endl;
  return;
}

void display_menu(int & user_choice)
{
  cout << "Please choose from the options below...\n" << endl;
  cout << "1. Diagnose a patient" << endl;
  cout << "2. I'm all done" << endl << endl;
  cout << "Your choice: ";
  cin >> user_choice;
  cout << endl;
  return;
}

void get_name(string & patient_name)
{
  cout << "Please type in the patient's name: ";
  cin >> patient_name;
  cout << endl;
  return;
}

void a_flat(int & p1, float & p2, int & p3)
{
  p1 = rand()%(PROTEIN1MAX+1);
  p1 = (p1 < 10 ? 0 : p1);
  p2 = static_cast<float>(rand()%(PROTEIN2MAX+1))/10;
  p3 = rand()%(PROTEIN3MAX+1);
  return;
}

void a_flat_mistake(bool & heard)
{
  heard = (rand()%100 < 5 ? false : true);
  if (!heard)
  {
    cout << "Proteins 1, 2, and 3 were not collected properly. Results are"
      " inconclusive. Come back again sometime." << endl;
  }
  return;
}

void middle_g(float & p2, int & p4)
{
  float temp_p2 = p2;
  p2 = static_cast<float>(rand()%(PROTEIN2MAX+1))/10;
  p2 = (p2 < temp_p2 ? p2 : temp_p2);
  p4 = rand()%(PROTEIN4MAX+1-PROTEIN4MIN) + PROTEIN4MIN;
  return;
}

void middle_g_mistake(bool & heard)
{
  heard = (rand()%100 < 5 ? false : true);
  if (!heard)
  {
    cout << "Proteins 2 and 4 were not collected properly. Results are"
      " inconclusive. Come back again sometime." << endl;
  }
  return;
}

void c_flat(int & p1, int & p4, int & p5)
{
  int temp_p1 = p1;
  int temp_p4 = p4;
  p1 = rand()%(PROTEIN1MAX+1);
  p1 = (p1 > temp_p1 ? p1 : temp_p1);
  p4 = rand()%(PROTEIN4MAX+1-PROTEIN4MIN) + PROTEIN4MIN;
  p4 = (p4 > temp_p4 ? p4 : temp_p4);
  p5 = rand()%(PROTEIN5MAX+1);
  return;
}

void c_flat_mistake(bool & heard)
{
  heard = (rand()%100 < 5 ? false : true);
  if (!heard)
  {
    cout << "Proteins 1, 4, and 5 were not collected properly. Results are"
      " inconclusive. Come back again sometime." << endl;
  }
  return;
}

proteins make_a_proteins(const int & p1, const float & p2, const int & p3,
  const int & p4, const int & p5, proteins & prots)
{
  prots.protein1 = p1;
  prots.protein2 = p2;
  prots.protein3 = p3;
  prots.protein4 = p4;
  prots.protein5 = p5;

  return prots;
}

bool diagnose(const proteins & prots)
{
  bool results = 0;

  if (prots.protein5 < 2)
  {
    if (prots.protein4 > 20 && prots.protein4 < 40 && prots.protein3 > 6)
    {
      results = 1;
    }
  }
  else if (prots.protein1 + prots.protein2 + prots.protein3 < 75)
  {
    results = 1;
  }

  results = (prots.protein2 <= 14.6 ? 1 : results);

  results = (prots.protein1 == 0 ? 0 : results);

  return results;
}

void printDiagnosis(const bool & isAffected, const string & patient_name,
  const proteins & prots)
{
  cout << "\nPatient " << patient_name << " has the following proteins:" <<endl;
  cout << "Protein 1: " << prots.protein1 << endl;
  cout << "Protein 2: " << prots.protein2 << endl;
  cout << "Protein 3: " << prots.protein3 << endl;
  cout << "Protein 4: " << prots.protein4 << endl;
  cout << "Protein 5: " << prots.protein5 << endl;
  if (isAffected)
  {
    cout << "\n...And they are diagnosed with Jejunal Hemorrhage Syndrome.\n"
    "Hope they have fun with the rest of their life!!" << endl << endl;
  }
  else
  {
    cout << "\n...And they are NOT diagnosed with Jejunal Hemorrhage Syndrome."
      "\nThink of yourself as much more fortunate than some of the other"
      " patients!\nFeel free to make fun of them."<< endl
      << endl;
  }

  return;
}

void goodbye()
{
  cout << "It was nice diagnosing for you, so long now!!" << endl;
  return;
}
