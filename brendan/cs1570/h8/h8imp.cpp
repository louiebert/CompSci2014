// Programmer: Brendan Curran             Date: 11/11/2014
// File: h8imp.cpp                        Class: CS 1570 Sec C
// Description: contains the implementation of all functions
// for the main h8 program

#include <iostream>
#include "h8headers.h"
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>


using namespace std;

void greeting()
{
  cout << "Welcome to Dr. Eloes office "<< endl;
}

string getComplaint()
{
  string complaint;
  cout << "Whait is ailing you today? :";
  getline(cin, complaint);
  cout << endl;
  return complaint;
}

void shortComplaint(char complaintToChange[], int size, int &numPills)
{
  int numOutput, numWords = 0, wordNumber;
  char tempWord[20], tempComplaint[100] = "So, ";
  
  ofstream out;
  ifstream in;
  
  out.open("complaint.txt");
  out << complaintToChange;
  out.close();
  
  for (int i=0; i< size; i++)
  {
    if (complaintToChange[i] == ' ')
      numWords++;
  }
  numWords++;
  numPills = numWords;
  
  if (numWords > 10)
    numOutput = 5;
  else
    numOutput = numWords/2;
  
  in.open("complaint.txt");
  for (int j= 0; j < numOutput; j++)
  {
    wordNumber = rand()%numWords;
    for (int i= 0; i<wordNumber+1; i++)
    {
      
      in >> tempWord;
      if (i == wordNumber)
      {
        strcat(tempWord, " ");
        strcat(tempComplaint, tempWord);
        in.close();
        in.open("complaint.txt");
      }
      
    }
  }
  in.close();
  strcpy (complaintToChange, tempComplaint);
  strcat (complaintToChange, "?");
}

void diagnose(char diagnosis[])  
{
  ofstream out;
  ifstream in;
  string read, toOpen;
  int numConditions, select;
  bool found = false;
  
  in.clear();
  in.open("complaint.txt");
  
  while(in >> read && !found)
  {
    if (read == "leg" || read == "legs")
    {
      toOpen = "Leg.dat";
      found = true;
    }
    else if (read == "head")
    {
      toOpen = "Head.dat";
      found = true;
    }
    else if (read == "torso")
    {
      toOpen = "Torso.dat";
      found = true;
    }
    else if (read == "hand" || read =="hands")
    {
      toOpen = "hand.dat";
      found = true;
    }
    else if (read == "nose")
    {
      toOpen = "nose.dat";
      found = true;
    }
    
  }
  in.close();
  in.clear();
  if (found)
  {
    in.open(toOpen.c_str());
    in >> numConditions;
    select = rand()%numConditions;
    for (int i = 0; i <= select; i++)
    {
      getline(in, read);
      if (i == select)
        strcpy(diagnosis, read.c_str());
    }
    in.close();
    in.clear();
  }
  else 
    strcpy(diagnosis, "you obviously have no real problem, take some aspirin"\
      " and get some sleep");
}

void prescribe(char drug[], char surgery[])
{
  int numScripts = 0, select, numConditions;
  string read;
  ifstream in;
  in.open("scripts.dat");
  while(in >> read)
  {
    numScripts++;
  }
  in.close();
 
  for (int j = 0; j < 4; j++)
  {
    in.clear();
    in.open("scripts.dat");
    select = rand()%numScripts;
    for (int i = 0; i<= select; i++)
    {
      in >> read;
      if (i == select)
        strcat(drug, read.c_str());
    }
    in.close();
  }
  
  
  in.open("surgeries.dat");
  in >> numConditions;
  select = rand()%numConditions;
    for (int i = 0; i <= select; i++)
    {
      getline(in, read);
      if (i == select)
        strcpy(surgery, read.c_str());
    }
    in.close();
  
  
}

void output(const char sComplaint[], const char diagnosis[], \
  const int numPills, const char drug[], const char surgery[])
{
  cout << sComplaint << "? It is clear you have "<< diagnosis << endl;
  cout << "Your prescription is to take " << numPills 
    << " pills a day of 20 mg." << drug << endl;
  cout <<"I would also recommend that you undergo a " << surgery << endl;
  cout <<"Nexttttttt!!???\n" << endl;
}