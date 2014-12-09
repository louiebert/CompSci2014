// Programmer: Brendan Curran              Date: 10/28/2014
// File: h7header.h                        Class: CS 1570 Sec C
// Description: contains constant for the size of the dna sequence
// along with a struct person that represents all the data
// about them used for diagnosing zombie-ism
// and prototypes for functions used in the program


#ifndef H7HEADER_H
#define H7HEADER_H

const int dnaSequence = 128;
const int studyMax = 5000;

struct person
{
  char m_dna[dnaSequence];
  bool m_brains;
  int m_gait, m_odor;  
};

//Description: Assigns all data in struct person
//Pre: person passed by reference
//Post: m_dna array filled with random values, 30% chance g, 23% chance t,
//27% chance a, 20% chance c_str, m_brains assigned true or false, 50/50 chance
//m_gait assigned 0-2, m_odor assigned 0-3 both random, evenly distributed, and
//inclusive ranges
void assignData (person & p);

//Description: calculates various results from the data, and prints to screen
//including the number studied and various percentages of infection
//Pre: parameter array of persons, in each data is already assigend,
//size however many are in the study,
//and integer number of people who are in the study
//Post: outputs to the screen number of peopel tested, and percentages for
//how many eat brains, have bad smell, don't walk normally, diagnosed as 
//zombie only by qualities, diaged only by dna, and diaged by both
void results (const person p[], const int numstudy);

#endif