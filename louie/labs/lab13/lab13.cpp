//Programmer: LOUIE BERTONCIN     Date: 12/2/2014
//File: lab13.cpp                 Class: CS 1580, Section D
//Purpose: Main file for Lab13

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "lab13.hpp"
#include "farm.h"

using namespace std;

int main()
{
  srand(time(NULL));
  int numHorses, numCats;

  Farm<Horse> horseFarm;
  cout << "How many horses would you like to have? ";
  cin >> numHorses;
  for(int i = 0; i < numHorses; i++)
  {
    Horse newHorse;
    cin >> newHorse;
    horseFarm.addAnimal(newHorse);
  }

  Farm<Cat> catFarm;
  cout << "How many cats would you like to have? ";
  cin >> numCats;
  for(int i = 0; i < numCats; i++)
  {
    Cat newCat;
    cin >> newCat;
    catFarm.addAnimal(newCat);
  }

  cout << "\n\nHorse Farm:" << endl;
  horseFarm.printAnimals();
  horseFarm.action();

  cout << "\nCat Farm:" << endl;
  catFarm.printAnimals();
  catFarm.action();


  return 0;
}

