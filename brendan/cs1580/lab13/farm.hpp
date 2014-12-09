// Programmer: Brendan Curran              Date: 12/3/2014/2014
// File: farm.hpp                          Class: CS 1580 Sec D
// Description: 

#include <iostream>
#include "farm.h"

using namespace std;

template <class T_animal>
void farm<T_animal>::addAnimal(T_animal anim)
{
  my_herd[m_herdSize] = anim;
  m_herdSize++;
}

template <class T_animal>
void farm<T_animal>::printAnimals()
{
  for (int i=0; i<m_herdSize; i++)
  {
    cout << my_herd[i] << endl;
  }
}
