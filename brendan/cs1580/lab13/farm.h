// Programmer: Brendan Curran              Date: 12/3/2014/2014
// File: farm.h                            Class: CS 1580 Sec D
// Description: 

#ifndef FARM_H
#define FARM_H

#include <string>

using namespace std;

const int MAX = 50;

template <class T_animal>

class farm
{
  public:
    farm():m_herdSize(0){}
    void addAnimal(T_animal anim);
    void printAnimals();
    int getHerdsize() const {return m_herdSize;}
    void action();
  private:
    T_animal my_herd[MAX];
    int m_herdSize;
};

#include "farm.hpp"
#endif