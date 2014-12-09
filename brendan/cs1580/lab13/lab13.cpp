// Programmer: Brendan Curran              Date: 12/3/2014/2014
// File: lab13.cpp                         Class: CS 1580 Sec D
// Description: 

#include "lab13.h"
#include "farm.h"
#include <iostream>

using namespace std;

int main()
{
  int input;
  string inName;
  horse tempHorse;
  cat tempCat;
  
  farm<horse> horseFarm;
  farm<cat> catFarm;
  
  cout <<"How many horses are on your farm?: ";
  cin >> input;
  
  for (int i=0; i<input; i++)
  {
    cout << "horse " << i+1 << " name: ";
    cin >> tempHorse.m_name;
    cout << "horse " << i+1 << " gender (m/f): ";
    cin >> tempHorse.m_gender;
    horseFarm.addAnimal(tempHorse);
  }
  cout << endl;
    
  cout <<"Haw many cats are on your farm?: ";
  cin >> input;
  
  for (int j=0; j<input; j++)
  {
    cout << "cat " << j+1 << " name: ";
    cin >> tempCat.m_name;
    cout << "cat " << j+1 << " gender (m/f): ";
    cin >> tempCat.m_gender;
    catFarm.addAnimal(tempCat);
  }
  
  cout << endl;
  cout << "you have "<< horseFarm.getHerdsize() << " horses" << endl;
  horseFarm.printAnimals();
  cout << endl << "you have "<< catFarm.getHerdsize() << " cats" << endl;
  catFarm.printAnimals();
  cout << endl << "goodbye";
  return 0;
}

