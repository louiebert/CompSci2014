// Programmers: ALEX SHAW, LOUIE BERTONCIN            Date: 11-8-14
// File: hw8.cpp                                      Class:  CS1570 Section B
// Purpose: Contains the program that takes in user's health complaint,
// outputs a random prognosis, prescribes and outputs a random drug, and
// outputs the prescription strength.

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "hw8.h"
using namespace std;

int main()
{
  string filename;
  string complaints;
  int num_words;
  char complaintStr[COMPLAINT_LENGTH][WORD_LENGTH];
  srand(time(NULL));

  cout << "Welcome to what might be your last day alive. Please have a seat."
       << endl;
  input_complaint(complaints);
  num_words = make_array(complaints.c_str(), complaintStr);
  disp_words(complaintStr, num_words);
  filename = keyword(complaintStr, num_Words);
  disp_prog(const string & filename);
  disp_drug(num_words);
  if(random_choice(1, 100) > 25)
  {
    disp_surg();
  }
  return 0;
}
