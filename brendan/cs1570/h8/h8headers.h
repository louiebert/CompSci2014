// Programmer: Brendan Curran             Date: 11/11/2014
// File: h8headers.h                      Class: CS 1570 Sec C
// Description: contains function prototypes to be used in the
// h8 function along with a constant for the complaint length to be 
// input by users

#ifndef H8HEADERS_H
#define H8HEADERS_H

using namespace std;

const int COMPLAINTLENGTH = 100;

//Description: Greets the user
//Pre: None
//Post: Prints greeting mesasge to screen
void greeting();

//Description: Gets the medical complaint from the user
//Pre: none
//Post: a string complaint is taken in from user and returned
string getComplaint();

//Description: gathers up to five words from the patients complaint and puts
//them together in a character array
//Pre: ntca containing the patients complaint (no word >20 characters), 
//integer size of the array
//Post: ntca is altered to five random words
void shortComplaint(char complaintToChange[], int size, int &numPills);

//Description: searches complaint for 5 words, leg, head, torso,  hand, and
//nose, then grabs a random diagnosis pertaining to the first of these words
//found from corresponding data file
//Pre: complaint.txt file that contains the patients complaint 
//and a ntca that diagnosis will be written to
//Post: diagnosis ntca will be filled with diagnosis generated
void diagnose(char diagnosis[]);

//Description: will generate random drug name, along with chose a random 
//surgery from data files
//Pre: ntca for drug name, ntca for surgery
//Post: drug and surgery ntca will be filled with generated values
void prescribe(char drug[], char surgery[]);

//Description: outputs all information to patient, their diagnosis
//proscription, and surgery recommendation
//Pre: ntca containing shortened complaint, diagnosis, numpills, drug name,
//and surgery
//Post: prints out all information to user
void output(const char sComplaint[], const char diagnosis[], \
  const int numPills, const char drug[], const char surgery[]);

#endif