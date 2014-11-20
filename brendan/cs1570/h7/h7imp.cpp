// Programmer: Brendan Curran              Date: 10/28/2014
// File: h7imp.cpp                         Class: CS 1570 Sec C
// Description: contains function implementation for research program

#include <iostream>
#include "h7header.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void assignData(person & p)
{
  
  //bounds for random chance of each dna piece
  //g chance = glimit, t chance = tlimit-glimit
  //and so forth, climit must be 100
  const int glimit = 30;
  const int tlimit = 53;
  const int alimit = 80;
  const int climit = 100;
  
  int dnaRand;
  
  p.m_odor = rand()%4;
  p.m_brains = rand()%2;
  p.m_gait = rand()%3;
  
  //assigns each piece of dna array
  for (int i = 0; i< dnaSequence; i++)
  {
    dnaRand = rand()%100;
    if (dnaRand < glimit)
      p.m_dna[i] = 'g';
    else if (dnaRand <tlimit)
      p.m_dna[i] = 't';
    else if (dnaRand < alimit)
      p.m_dna[i] = 'a';
    else if (dnaRand < climit)
      p.m_dna[i] = 'c';
  }
}

void results (const person p[], const int numstudy)
{
  float brainPercent, odorPercent, gaitPercent, qualPercent, dnaPercent;
  float bothPercent;
  int brainCount=0, odorCount=0, gaitCount=0, qualCount=0, dnaCount=0;
  int bothCount=0;
  bool dnaTest;
  
  for (int i = 0; i<numstudy; i++)
  {
    dnaTest = false;
    
	//adding up each individual stat
    if (p[i].m_brains)
      brainCount++;
    if (p[i].m_odor>1)
      odorCount++;
    if (p[i].m_gait !=0)
      gaitCount++;
    
	//testing dna for zombieism
    for (int j = 0; j<dnaSequence-3; j++)
    {
      if(p[i].m_dna[j] == 'g' && p[i].m_dna[j+1] =='t')
      {
        if(p[i].m_dna[j+2] == 'a' && p[i].m_dna[j+3]== 'c')
          dnaTest=true;
      }          
    }
    
    //checking quality and dna relationship
    if (p[i].m_brains && p[i].m_odor>1 && p[i].m_gait !=0)
      {
	    //diagnose by both
        if (dnaTest)
		  bothCount++;
        //diagnose by only qualities
        else
          qualCount++;
      }
    //diagnose by only dna
	else if (dnaTest)
      dnaCount++;
  }
  
  
  //calculating percentages
  brainPercent = 100*static_cast<float>(brainCount)/numstudy;
  odorPercent = 100*static_cast<float>(odorCount)/numstudy;
  gaitPercent = 100*static_cast<float>(gaitCount)/numstudy;
  dnaPercent = 100*static_cast<float>(dnaCount)/numstudy;
  qualPercent = 100*static_cast<float>(qualCount)/numstudy;
  bothPercent = 100*static_cast<float>(bothCount)/numstudy;
  
  //outputting results
  cout <<"Out of a total of 5000 people tested:\n" << endl;
  cout << brainPercent << "% want to eat brains. " << endl;
  cout << odorPercent << "% have a slightly ripe or rotting smell "<< endl;
  cout << gaitPercent << "% do not walk normally " << endl;
  cout << dnaPercent << "% qualify as zombies only by the DNA test "<< endl;
  cout << qualPercent << "% qualify as zombies only by their gait, smell, ";
  cout << "and what they want to eat" << endl;
  cout << bothPercent << "% qualify as zombies by the dna test and how ";
  cout << "they walk, smell, and what they want to eat\n"<< endl;  
}