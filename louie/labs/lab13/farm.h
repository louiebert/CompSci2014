//Programmer: LOUIE BERTONCIN     Date: 12/2/2014
//File: farm.h                    Class: CS 1580, Section D
//Purpose: Header file for Farm class

#ifndef FARM_H
#define FARM_H

#include <iostream>

using namespace std;

const int MAX = 50;

template<class T_animal>
class Farm
{
  public:
    Farm():m_herdSize(0){}
    void addAnimal(T_animal anim);
    void printAnimals();
  private:
    T_animal m_myHerd[MAX];
    int m_herdSize;
};

#include "farm.hpp"

#endif