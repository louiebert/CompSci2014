//Programmer: LOUIE BERTONCIN     Date: 10/26/2014
//File: h7.cpp                    Class: CS 1570, Section D
//Purpose: Main file for human creation and zombie analysis

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "h7.h"

using namespace std;

int main()
{
  srand(time(NULL));

  Human subjects[MAXSUBJECTS];
  int numSubjects;

  greeting();

  do
  {
    numSubjects = getNumSubjects();
    int numBrains = 0, numSmell = 0, numWalk = 0, numExternal = 0, numDNA = 0,
      numBoth = 0;

    for(int i = 0; i < numSubjects; i ++)
    {
      bool hasDNA = false;
      subjects[i] = createHuman(hasDNA);
      numBrains += (subjects[i].wants_brains ? 1 : 0);
      numSmell += (subjects[i].body_odor == SMELLTYPE3 ||
        subjects[i].body_odor == SMELLTYPE4 ? 1 : 0);
      numWalk += (subjects[i].gait_type != GAITTYPE1 ? 1 : 0);
      numExternal += (subjects[i].wants_brains &&
        (subjects[i].body_odor == SMELLTYPE3 ||
        subjects[i].body_odor == SMELLTYPE4) &&
        subjects[i].gait_type != GAITTYPE1 ? 1 : 0);
      numDNA += (hasDNA ? 1 : 0);
      numBoth += (subjects[i].wants_brains &&
        (subjects[i].body_odor == SMELLTYPE3 ||
        subjects[i].body_odor == SMELLTYPE4) &&
        subjects[i].gait_type != GAITTYPE1 && hasDNA ? 1 : 0);
    }

    calculateSubjects(numBrains, numSmell, numWalk, numExternal, numDNA,
      numBoth, numSubjects);

  }while(testAgain());

  goodbye();

  return 0;
}
