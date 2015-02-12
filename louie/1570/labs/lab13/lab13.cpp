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
  do
  {
    cout << "How many horses would you like to have? ";
    cin >> numHorses;
  }while(numHorses > 50 || numHorses < 0);
  for(int i = 0; i < numHorses; i++)
  {
    Horse newHorse;
    cin >> newHorse;
    horseFarm.addAnimal(newHorse);
  }

  Farm<Cat> catFarm;
  do
  {
    cout << "How many cats would you like to have? ";
    cin >> numCats;
  }while(numCats > 50 || numCats < 0);
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

