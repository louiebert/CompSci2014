// Programmers: ALEX SHAW, LOUIE BERTONCIN            Date: 11-8-14
// File: hw8_functs.cpp                               Class:  CS1570 Section B
// Purpose: Contains the function definitions for the program that takes in
// user's health complaint, outputs a random prognosis, prescribes and outputs
// a random drug, and outputs the prescription strength.

#include <ctime>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "hw8.h"
using namespace std;

void open_connection(T & the_stream, const string & filename)
{
  the_stream.open(filename.c_string);      //Attempt to connect to data file
  int counter = 0;
  while(!the_stream && counter < MAX_TRIES)      //Test connection
  {
    the_stream.clear();
    the_stream.open(filename.c_string);
    counter++;
  }
  if(!the_stream)                          //Exit if unable to connect
  {
    cout << "Error: Unable to connect to " << filename << "."
         << "Exiting program." << endl;
    exit(1);
  }
}

void input_complaint(string & input)
{
  ignore(500, '\n');
  cout << "Enter complaint: ";
  getline(cin, input, '\n');
}

int make_array(const char source[], char target[][WORD_LENGTH])
{
  int i = 0, j = 0, k = 0;
  while(source[i] != '\0')
  {
    if(source[i] != ' ')
    {
      target[k][j] = tolower(source[i]);
      if (!isalpha(source[i]) && source[i] != '-')
        target[k][j] = '\0';
      i++;
      j++;
    }
    else
    {
      j = 0;
      i++;
      k++;
    }
  }
  return k+1;
}

void disp_words(const char arr[][WORD_LENGTH], const int & num_words)
{
  int wordsDisp = 0;                            //Number of words to display
  if((num_words / WORDS_DIVISOR) > MAX_WORDS)
    wordsDisp = MAX_WORDS;
  else if(1 == num_words)
    wordsDisp = 1;
  else
    wordsDisp = num_words / WORDS_DIVISOR;
  cout << "So, " << endl;
  for(int i = 0; i < wordsDisp; i++)
  {
    cout << arr[random_choice(0, num_words - 1)][] << " " << endl;
  }
  cout << "?" << endl;
  return;
}

string keyword(const char sentences[][WORD_LENGTH], const int & num_words)
{
  string filename = "";
  int i = 0;
  while( i < num_words && filename == "")           //Set var equal to
  {                                                 // filename corresponding
    if(sentences[i][] == BODY_PART1)                // to body part.
    {
      filename = DATA_FILE1;
    }

    else if(sentences[i][] == BODY_PART2)
    {
      filename = PART_FILE2;
    }

    else if(sentences[i][] == BODY_PART3)
    {
      filename = PART_FILE3;
    }

    else if(sentences[i][] == BODY_PART4)
    {
      filename = PART_FILE4;
    }

    else if(sentences[i][] == BODY_PART5)
    {
      filename = PART_FILE5;
    }
    i++;
  }
  return filename;
}

void disp_prog(const string & filename)
{
  if(filename != "")            //If user input keyword in complaint
  {
    char prognosis[PROG_ARR_LNGTH];
    ifstream fin;
    open_connection(fin, filename);
    int total_el = num_el(ifstream & fin);      //Tally the elements
    for(int i = 0; i < random_choice(1, total_el); i++)      //Select prognosis
    {
      fin >> prognosis;
    }
    cout << prognosis;
  }

  else
  {
    cout << "Go home. Get some sleep. Take some aspirin. Wimp." << endl;
  }
  fin.close();                    //Close the connection
  return;
}

int num_el(ifstream & fin)
{
  int total_el = 0;
  char next;
  while(fin >> next)
  {
    el++;
  }
  return total_el;
}

int random_choice(const int min, const int max)
{
  return (min + rand() % (max + 1 - min));
}

void disp_drug(const int & num)
{
  char temp[MAX_SYLLABLE_LENGTH];
  char prescription[PRESCRIPT_ARR_LENGTH];
  ifstream fin;
  open_connection(fin, SURGERY_FILE);
  int num_syllables = num_el(fin);               //Counts elements in data file
  cout << "Your prescription is to take " << num << " pills per day of 20 mg ";
  for(int i = 0; i < MAX_SYLLABLES; i++);    //Generates drug name
  {
    for(int j = 0; j < (random_choice(1, num_syllables )); j++)
      fin >> temp;
    strcat(prescription, temp);
  }
  cout << prescription << endl;
  fin.close();
  return;
}

void disp_surg()
{
  char surgery[SURGERY_ARR_LENGTH];
  ifstream fin;
  open_connection(fin, SURGERY_FILE);
  int num_surg = num_el(fin);               //Counts elements in data file
  for(int i = 0; i < num_surg; i++)
  {
    fin >> surgery;
  }
  cout << "We recommend you undergo " << surgery << " for your own good."
       << endl;
  fin.close()
  return;
}
