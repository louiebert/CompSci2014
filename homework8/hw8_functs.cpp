// Programmers: ALEX SHAW, LOUIE BERTONCIN            Date: 11-8-14
// File: hw8_functs.cpp                               Class:  CS1570 Section B
// Purpose: Contains the function definitions for the program that takes in
// user's health complaint, outputs a random prognosis, prescribes and outputs
// a random drug, and outputs the prescription strength.

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include "hw8.h"
using namespace std;

void greeting()
{
  cout << "\n----------------The Prognosis Machine----------------\n\n" << endl;
  return;
}

void open_connection(ifstream & the_stream, const string & filename)
{
  the_stream.open(filename.c_str());      //Attempt to connect to data file
  int counter = 0;
  while(!the_stream && counter < MAX_TRIES)      //Test connection
  {
    the_stream.clear();
    the_stream.open(filename.c_str());
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
  cout << "Enter complaint: ";
  getline(cin, input);
  return;
}

int make_array(const char source[], char target[][WORD_LENGTH])
{
  int i = 0, j = 0, k = 0;
  while(source[i] != '\0')
  {
    if(source[i] != ' ')
    {
      target[k][j] = source[i];
      if (!isalpha(source[i]) && source[i] != '-' && source[i] != '\'')
        target[k][j] = '\0';
      i++;
      j++;
    }
    else
    {
      target[k][j] = '\0';
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
  cout << "So,";
  for(int i = 0; i < wordsDisp; i++)
  {
    cout << " " << arr[random_choice(0, num_words - 1)];
  }
  cout << "?" << endl << endl;
  return;
}

string keyword(char sentences[][WORD_LENGTH], const int & num_words)
{
  string filename = "";
  int i = 0;
  while( i < num_words && filename == "")           //Set var equal to
  {                                                 // filename corresponding
    int j = 0;
    while(sentences[i][j] != '\0')
    {
      sentences[i][j] = tolower(sentences[i][j]);
      j++;
    }
    if(sentences[i] == BODY_PART1)                // to body part.
      filename = PART_FILE1;
    else if(sentences[i] == BODY_PART2)
      filename = PART_FILE2;
    else if(sentences[i] == BODY_PART3)
      filename = PART_FILE3;
    else if(sentences[i] == BODY_PART4)
      filename = PART_FILE4;
    else if(sentences[i] == BODY_PART5)
      filename = PART_FILE5;
    i++;
  }
  return filename;
}

bool disp_prog(const string & filename)
{
  bool real = true;
  if(filename != "")            //If user input keyword in complaint
  {
    char prognosis[PROG_ARR_LENGTH] = {};
    int total_el;
    ifstream fin;
    open_connection(fin, filename);
    total_el = num_el(fin);      //Tally the elements
    fin.close();
    open_connection(fin, filename);
    for(int i = 0; i < random_choice(1, total_el); i++)      //Select prognosis
    {
      fin.getline(prognosis, PROG_ARR_LENGTH-1);
    }
    cout << "It's clear you have " << prognosis << "." << endl;
    fin.close();
  }

  else
  {
    cout << "Go home. Get some sleep. Take some aspirin. Wimp." << endl;
    real = false;
  }
  return real;
}

int num_el(ifstream & fin)
{
  int total_el = 0;
  char next[PROG_ARR_LENGTH] = {};
  while(!fin.eof())
  {
    total_el++;
    fin.getline(next, PROG_ARR_LENGTH-1);
  }
  return total_el-1;
}

int random_choice(const int min, const int max)
{
  return (min + rand() % (max + 1 - min));
}

void disp_drug(const int & num)
{
  char temp[MAX_SYLLABLE_LENGTH] = {};
  char prescription[PRESCRIPT_ARR_LENGTH] = {};
  ifstream fin;
  open_connection(fin, PRESCRIPT_FILE);
  int num_syllables = num_el(fin);               //Counts elements in data file
  fin.close();
  open_connection(fin, PRESCRIPT_FILE);
  cout << "Your prescription is to take " << num << " pills per day of 20 mg ";
  for(int i = 0; i < MAX_SYLLABLES; i++)    //Generates drug name
  {
    for(int j = 0; j < (random_choice(1, num_syllables)); j++)
      fin >> temp;
    strcat(prescription, temp);
  }
  cout << prescription << "." << endl;
  fin.close();
  return;
}

void disp_surg()
{
  char surgery[SURGERY_ARR_LENGTH];
  ifstream fin;
  open_connection(fin, SURGERY_FILE);
  int num_surg = num_el(fin);               //Counts elements in data file
  fin.close();
  open_connection(fin, SURGERY_FILE);
  for(int i = 0; i < num_surg; i++)
  {
    fin >> surgery;
  }
  cout << "We recommend you undergo " << surgery << " for your own good."
       << endl;
  fin.close();
  return;
}

bool do_again()
{
  bool again = false;
  char answer;

  cout << "\nWant another prognosis? (y/n) ";
  cin >> answer;

  cin.ignore(500, '\n');

  return tolower(answer) == 'y';
}

void goodbye()
{
  cout << "\n\nIt was nice prognosing for you, so long now!!\n" << endl;
  return;
}
