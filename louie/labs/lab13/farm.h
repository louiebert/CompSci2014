//Programmer: LOUIE BERTONCIN     Date: 12/2/2014
//File: farm.h                    Class: CS 1580, Section D
//Purpose: Header file for Farm class

#ifndef FARM_H
#define FARM_H

#include <iostream>

using namespace std;

const int MAX = 50;

// Constructor creates a new Farm and sets m_herdSize to zero.
// Pre: None.
// Post: A new Farm object is created.

// addAnimal() inserts an animal into the next open spot in the m_myHerd array.
// Pre: Must be of same animal type as the Farm object is.
// Post: Another animal is added to the herd.

// printAnimals() calls the insertion operator on every animal in m_myHerd.
// Pre: None.
// Post: Every animal in m_myHerd gets printed.

// action() calls the act() function of each animal in m_myHerd.
// Pre: The animal object type must have a public act() function.
// Post: Each animal gets its act() function called.

template<class T_animal>
class Farm
{
  public:
    Farm():m_herdSize(0){}
    void addAnimal(T_animal anim);
    void printAnimals();
    void action();
  private:
    T_animal m_myHerd[MAX];
    int m_herdSize;
};

#include "farm.hpp"

#endif