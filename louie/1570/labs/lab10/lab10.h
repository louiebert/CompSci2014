//Programmer: LOUIE BERTONCIN       Date: 11/5/2014
//File: lab10.h                     Class: CS 1580, Section D
//Purpose: Header file for the shift program.

#ifndef LAB10_H
#define LAB10_H

using namespace std;

const char LOWERMIN = 'a';
const char LOWERMAX = 'z';
const char UPPERMIN = 'A';
const char UPPERMAX = 'Z';
const int ALPHABETLENGTH = 26;

// greeting() outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// get_shif_amount() prompts user for the amount of letters to shift by.
// Pre: None
// Post: Returns the integer that the user inputs.
int get_shift_amount();

// get_input_filename() prompts user for the file name of the input data file.
// Pre: None
// Post: Returns the string that the user inputs.
string get_input_filename();

// get_output_filename() prompts user for the file name of the output data file.
// Pre: None
// Post: Returns the string that the user inputs.
string get_output_filename();

// decrypt() takes the message in the input file and shifts all the characters'
//   ASCII values by the int shift and prints the decrypted message in the
//   output file.
// Pre: ifstream input must be a stream pointing to a file full of chars.
//   ofstream output must be a stream pointing to the file in which the
//   decrypted message will be printed to. int shift is the number of ASCII
//   values each character must be shifted by to decode the message.
// Post: Prints decoded message in the file connected by the ofstream output.
void decrypt(ifstream & input, ofstream & output, const int & shift);

// The goodbye() function prints a farewell to the console.
// Pre: None
// Post: Prints a message to the console
void goodbye();

#endif
