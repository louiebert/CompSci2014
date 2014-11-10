// Programmers: ALEX SHAW, LOUIE BERTONCIN            Date: 11-8-14
// File: hw8.cpp                                      Class:  CS1570 Section B
// Purpose: Contains the program that takes in user's health complaint,
// outputs a random prognosis, prescribes and outputs a random drug, and
// outputs the prescription strength.

#include "hw8.h"
using namespace std;

int main()
{
  string filename;
  string complaints;
  bool hasProg = true;
  int num_words;
  char complaintStr[COMPLAINT_LENGTH][WORD_LENGTH];
  srand(time(NULL));

  do
  {
    greeting();
    cout << "Welcome to what might be your last day alive. Please have a "
      "seat.\n" << endl;
    input_complaint(complaints);
    num_words = make_array(complaints.c_str(), complaintStr);
    disp_words(complaintStr, num_words);
    filename = keyword(complaintStr, num_words);
    hasProg = disp_prog(filename);
    if (hasProg)
    {
      disp_drug(num_words);
      if(random_choice(1, 100) > 25)
      {
        disp_surg();
      }
    }
  }while(do_again());

  goodbye();

  return 0;
}
