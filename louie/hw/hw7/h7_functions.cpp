//Programmer: LOUIE BERTONCIN     Date: 10/26/2014
//File: h7_functions.cpp          Class: CS 1570, Section D
//Purpose: Functions file for human creation and zombie analysis

#include <iostream>
#include <cstdlib>
#include "h7.h"

using namespace std;

void greeting()
{
  cout << "Welcome to the zombie crowd tester program!!\n\n" << endl;

  return;
}

int getNumSubjects()
{
  int numSubjects;
  cout << "Please enter the number of subjects that you'd like to test today!"
    << endl;
  cout << "(Maximum " << MAXSUBJECTS << "): ";
  cin >> numSubjects;
  cout << endl;
  numSubjects = (numSubjects > MAXSUBJECTS ? MAXSUBJECTS : numSubjects);
  numSubjects = (numSubjects < 0 ? 0 : numSubjects);

  return numSubjects;
}

Human createHuman(bool & dnaPtrn)
{
  Human aHuman;

  for(int i = 0; i < NUMDNA; i++)
  {
    aHuman.dna[i] = createDNA();
    if (i > 2 && aHuman.dna[i] == DNA4)
      dnaPtrn = (aHuman.dna[i-1] == DNA3 && aHuman.dna[i-2] == DNA2 &&
        aHuman.dna[i-3] == DNA1 ? true : false);
  }
  aHuman.body_odor = createBO();
  aHuman.wants_brains = doesWantBrains();
  aHuman.gait_type = createGait();

  return aHuman;
}

char createDNA()
{
  char randChar = DNA4;
  int randInt = rand()%100;

  if(randInt < DNA_1_PROB)
    randChar = DNA1;
  else if(randInt >= DNA_1_PROB && randInt < DNA_1_PROB+DNA_2_PROB)
    randChar = DNA2;
  else if(randInt >= DNA_1_PROB+DNA_2_PROB && randInt <
    DNA_1_PROB+DNA_2_PROB+DNA_3_PROB)
    randChar = DNA3;

  return randChar;
}

string createBO()
{
  string bodyOdor = SMELLTYPE4;
  int randInt = rand()%4;

  if(!randInt)
    bodyOdor = SMELLTYPE1;
  else if(randInt == 1)
    bodyOdor = SMELLTYPE2;
  else if(randInt == 2)
    bodyOdor = SMELLTYPE3;

  return bodyOdor;
}

bool doesWantBrains()
{
  return rand()%2;
}

string createGait()
{
  string gait = GAITTYPE3;
  int randInt = rand()%3;

  if (!randInt)
    gait = GAITTYPE1;
  else if(randInt == 1)
    gait = GAITTYPE2;

  return gait;
}

void calculateSubjects(const int & numBrains, const int & numSmell,
  const int & numWalk, const int & numExternal, const int & numDNA,
  const int & numBoth, const int & total)
{
  cout << "\nOut of all " << total << " subjects tested: " << endl;
  cout << "\t" << (static_cast<float>(numBrains)/total)*100 << "% want to eat "
    "brains." << endl;
  cout << "\t" << (static_cast<float>(numSmell)/total)*100 << "% have a smell "
    "described as " << SMELLTYPE3 << " or " << SMELLTYPE4 << "." << endl;
  cout << "\t" << (static_cast<float>(numWalk)/total)*100 << "% walk funny."
    << endl;
  cout << "\t" << (static_cast<float>(numExternal)/total)*100 << "% qualify as "
    "zombies based on external observation." << endl;
  cout << "\t" << (static_cast<float>(numDNA)/total)*100 << "% qualify as "
    "zombies based on DNA testing." << endl;
  cout << "\t" << (static_cast<float>(numBoth)/total)*100 << "% qualify as "
    "zombies by both external observation and DNA testing." << endl << endl;
  cout << "Glad to do testing for you." << endl << endl;

  return;
}

bool testAgain()
{
  bool again;

  cout << "Would you like to run another test? (1 = yes, 0 = no): ";
  cin >> again;

  return again;
}

void goodbye()
{
  cout << "\nGlad we got to enjoy each other's company today!\n"
    "Hope to see you again soon!!\n" << endl;

  return;
}
