//Programmer: LOUIE BERTONCIN     Date: 12/2/2014
//File: farm.cpp                  Class: CS 1580, Section D
//Purpose: Body file for Farm class

#include "farm.h"

using namespace std;

template<class T_animal>
void Farm<T_animal>::addAnimal(T_animal anim)
{
  if(m_herdSize < MAX)
  {
    m_myHerd[m_herdSize] = anim;
    m_herdSize++;
  }

  return;
}

template<class T_animal>
void Farm<T_animal>::printAnimals()
{
  for(int i = 0; i < m_herdSize; i++)
  {
    cout << "\t" << i+1 << ": " << m_myHerd[i] << endl;
  }

  return;
}

template<class T_animal>
void Farm<T_animal>::action()
{
  for(int i = 0; i < m_herdSize; i++)
  {
    cout << m_myHerd[i].m_name << m_myHerd[i].act() << endl;
  }

  return;
}
