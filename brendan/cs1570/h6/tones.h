#ifndef H6_H
#define H6_H

// Programmer: Brendan Curran              Date: 10/13/2014
// File: tones.h                           Class: CS 1570 Sec C
// Description: prototypes the necessary functions for JHS testing
// and defines the struct that the data is contained in

#include <iostream>
using namespace std;

//This struct contains the patients name and the 5 protein values
//that will be recorded during testing
struct patient
{
  string m_name;
  int m_p1;
  float m_p2;
  int m_p3;
  int m_p4;
  int m_p5;
  bool m_diagnosis;
};

//Description: patient struct will be given to the function, and function will 
//assign protein values if test is successful, there is a 5% chance of failure
//Pre: struct patient passed by reference
//Post: proteins 1, 2, and 3, of patient data will be assigned random values
//p1 will be a random integer [0,100], and will not be represented if < 10
//p2 will be a random float [0,100.0]
//p3 will be a random integer [0,10]
//if test fails proteins will be assigned value of -1
void tone1 (patient & data);

//Description: patient struct will be given to the function, and function will 
//assign protein value to p4, and will assign new value to p2 if generated 
//larger than pre-existing p2 value
//there is a 5% chance of failure in this test
//Pre: struct patient passed by reference
//Post: protein 4 will be assigned random value, and p2 will be assigned new 
//value if randomly generated number is lower than current p2 value
//p4 will be a random integer [10,40]
//p2 will be random float [0,100] if new value is less than current p2 value
//or p2 doesn't have a valid value yet (prior test for p2 failed)
//if failure the protein value will be assigned -1, unless that protein already
//has a valid value
void tone2 (patient & data);

//Description: patient struct will be given to the function, and function will 
//assign protein value to p5, and will assign new value to p1 and p4 if
//generated larger than pre-existing p1 and p4 value
//there is a 5% chance of failure
//Pre: struct patient passed by reference
//Post: protein 5 will be assigned random value, and p1 and p4 will be assigned
//new value if randomly generated number is larger than current value
//p1 will be reassigned [0,100] if new value is greater than existing or 
//value was not originally valid, anything less than ten is not readable
//and will be set to 0
//p4 will be reassigned [0,50] if larger than existing or does not have a valid
//value
//p5 will be random integer [0,10]
//if test fails, p1 and p4 will be left at their existing value from prior test
//p5 will be inconclusive and set to -1
void tone3 (patient & data);

//Description: greets the user
//Pre: none
//Post: prints message to user saying hello and welcome
void greet();

//Description: gets patient name
//Pre: none
//Post: return string patients name
string getName();

//Description: analyzes the data in the patients file and determines
//if the patient has JHS
//Pre: struct containing all protein levels determined from test
//proteins will be
//p1 [0,100]
//p2 [0,100.0] only float, rest are integers
//p3 [0,10]
//p4 [10,50]
//p5 [0,10]
//protein value will be -1 if inconclusive test
//Post: returns bool if patient has disease, true = positive for disease
bool diagnose(patient data);

//Description: outputs all patient data
//Pre: patient struct with complete data set
//Post: outputs all protein values, patient name, and diagnosis
void showResult(patient data);
#endif