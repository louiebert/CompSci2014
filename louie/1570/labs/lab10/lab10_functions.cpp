//Programmer: LOUIE BERTONCIN       Date: 11/5/2014
//File: lab10_functions.cpp         Class: CS 1580, Section D
//Purpose: Functions file for the shift program.

#include <iostream>
#include <fstream>
#include "lab10.h"

using namespace std;

void greeting()
{
  cout << """Welcome to the decryption program.""" << endl;

  return;
}

int get_shift_amount()
{
  int shift;
  cout << "Please enter the number of characters you'd like to shift by: ";
  cin >> shift;

  return shift;
}

string get_input_filename()
{
  string input;
  cout << "Enter the input filename: ";
  cin >> input;

  return input;
}

string get_output_filename()
{
  string output;
  cout << "Enter the output filename: ";
  cin >> output;

  return output;
}

void decrypt(ifstream & input, ofstream & output, const int & shift)
{
  char letter[80];
  input >> letter;
  while(!input.eof())
  {
    for(int i = 0; i < 80; i++)
    {
      if(letter[i] >= LOWERMIN && letter[i] <= LOWERMAX)
      {
        letter[i] += shift;
        if(letter[i] > LOWERMAX)
          letter[i] -= ALPHABETLENGTH;
        else if(letter[i] < LOWERMIN)
          letter[i] += ALPHABETLENGTH;
      }
      else if(letter[i] >= UPPERMIN && letter[i] <= UPPERMAX)
      {
        letter[i] += shift;
        if(letter[i] > UPPERMAX)
          letter[i] -= ALPHABETLENGTH;
        else if(letter[i] < UPPERMIN)
          letter[i] += ALPHABETLENGTH;
      }
    }
    output << letter << " ";

    input >> letter;
  }

  return;
}

void goodbye()
{
  cout << """Yay! Decryption complete!""" << endl;

  return;
}
