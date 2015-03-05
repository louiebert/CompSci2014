//Programmer: LOUIE BERTONCIN     Date: 10/26/2014
//File: h7.h                      Class: CS 1570, Section D
//Purpose: Header file for human creation and zombie analysis

#ifndef H7_H
#define H7_H

using namespace std;

const int NUMDNA = 128;
const char DNA1 = 'G';
const char DNA2 = 'T';
const char DNA3 = 'A';
const char DNA4 = 'C';
const int DNA_1_PROB = 30;
const int DNA_2_PROB = 23;
const int DNA_3_PROB = 27;
const int DNA_4_PROB = 20;
const string SMELLTYPE1 = "pleasant";
const string SMELLTYPE2 = "neutral";
const string SMELLTYPE3 = "slight putrifaction";
const string SMELLTYPE4 = "rotten";
const string GAITTYPE1 = "normal";
const string GAITTYPE2 = "shuffle";
const string GAITTYPE3 = "crawling";
const int MAXSUBJECTS = 5000;

struct Human
{
  char dna[NUMDNA];
  string body_odor;
  bool wants_brains;
  string gait_type;
};

// The greeting() function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// getNumSubjects() prompts the user for how many subjects they want to test,
//   then returns that number. Max return value = MAXSUBJECTS.
// Pre: None
// Post: Returns the number of test subjects.
int getNumSubjects();

// createHuman() creates a human with random attributes and returns the human.
//   If the human has the DNA1, DNA2, DNA3, DNA4 pattern the dnaPtrn is true.
// Pre: None
// Post: Returns a randomly generated human.
Human createHuman(bool & dnaPtrn);

// createDNA() returns either a DNA1, DNA2, DNA3, or DNA4 based on the percent
//   chance of each letter defined in the constants.
// Pre: None
// Post: Returns a DNA1, DNA2, DNA3, or DNA4 char.
char createDNA();

// createBO() returns a randomly selected body odor from the four defined body
//   odor smells as a string.
// Pre: None
// Post: Returns a body odor string.
string createBO();

// doesWantBrains() returns either true or false, randomly selected.
// Pre: None
// Post: Returns a random true or false.
bool doesWantBrains();

// createGait() returns a randomly selected gait from the three defined gait
//   types as a string.
// Pre: None
// Post: Returns a gait string.
string createGait();

// calculateSubjects() takes in the number of subjects that want to eat brains,
//   smell bad, walk funny, pass zombie external tests, pass zombie DNA tests,
//   pass both external and DNA tests, and the total number of subjects. It then
//   prints the test data to the console.
// Pre: None of these numbers should theoretically be bigger than the total.
// Post: Prints test data for the subjects.
void calculateSubjects(const int & numBrains, const int & numSmell,
  const int & numWalk, const int & numExternal, const int & numDNA,
  const int & numBoth, const int & total);

// testAgain() prompts user to test again. Returns true if yes.
// Pre: none
// Post: Returns true or false based on user input.
bool testAgain();

// The goodbye() function prints a farewell to the console.
// Pre: None
// Post: Prints a message to the console
void goodbye();

#endif
