// Programmers: ALEX SHAW, LOUIE BERTONCIN            Date: 11-8-14
// File: hw8.h	                                      Class:  CS1570 Section B
// Purpose: Contains the global variables and function prototypes for the
// program that takes in user's health complaint, outputs a random prognosis,
// prescribes and outputs a random drug, and outputs the prescription strength.

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef HW8_H
#define HW8_H


//---------------------------Global Vars-------------------------------------//

const int COMPLAINT_LENGTH = 100;
const int WORD_LENGTH = 22;
const string BODY_PART1 = "head";
const string BODY_PART2 = "torso";
const string BODY_PART3 = "hand";
const string BODY_PART4 = "nose";
const string BODY_PART5 = "leg";
const string PART_FILE1 = "head.dat";
const string PART_FILE2 = "torso.dat";
const string PART_FILE3 = "hand.dat";
const string PART_FILE4 = "nose.dat";
const string PART_FILE5 = "leg.dat";
const string PRESCRIPT_FILE = "scripts.dat";
const string SURGERY_FILE = "surgeries.dat";
const string DEFAULT_PROG = "Go home. Get some sleep. Take some aspirin. Wimp.";
const int MAX_TRIES = 5;
const int MAX_WORDS = 5;
const int WORDS_DIVISOR = 2;
const int MAX_SYLLABLES = 4;
const int PROG_ARR_LENGTH = 30;
const int PRESCRIPT_ARR_LENGTH = 30;
const int MAX_SYLLABLE_LENGTH = 7;
const int SURGERY_ARR_LENGTH = 20;


//--------------------------Function Prototypes------------------------------//

// The greeting() function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// open_connection() opens and tests a connection to a data file.
// Pre: Data file must have same name as the filename variable.
// Post: Connects to specified data file or exits program if unable to connect.
void open_connection(ifstream & the_stream, const string & filename);

// input_complaint() reads in the user's compaint and stores it in var.
// Pre: The input stream must be cleared before taking in complaint.
// Post: User's complaint is assigned to var.
void input_complaint(string & input);

// make_array() takes a long source char array and creates a two dimensional
//   array with the words separated by spaces. Returns # of words in target.
// Pre: source[] must not have a word exceeding 21 characters. source[] also
//   shouldn't ever have two spaces in a row.
// Post: Makes a 2D array from the words of source. Punctuation is omitted in
//   the final target array. Returns number of indexes (words) in target.
int make_array(const char source[], char target[][WORD_LENGTH]);

// disp_words() displays a message to the screen composed of half of the words
//   (but not more than 5 words) from the user's complaint.
// Pre: Second dimension of arr[] needs to be ntca's. num_words must be
//   positive.
// Post: Displays a message to the screen composed of half of the words
//   (but not more than 5 words) chosen at random from user's complaint.
void disp_words(const char arr[][WORD_LENGTH], const int & num_words);

// keyword() searches the user's input for keywords and returns the keyword.
// Pre: Second dimension of arr[] needs to be ntca's. num_words must be
//   positive.
// Post: Returns name of file corresponding to name of body part found.
string keyword(char arr[][WORD_LENGTH], const int & num_words);

// disp_prog() displays a message to the screen with the user's prognosis and
//   returns false if there is no legitimate prognosis.
// Pre: The var holding the filename should match the actual filename.
//   The filename should be in the same directory as this program.
// Post: Displays a message to the screen with the user's prognosis and returns
//   false if there is no legitimate prognosis.
bool disp_prog(const string & filename);

// random_choice() chooses random number between a given minimum and maximum.
// Pre: rand() must be seeded. max must be greater than min.
// Post: Returns a random number between a given minimum and maximum.
int random_choice(const int min, const int max);

// num_el() determines how many data elements are in a data file.
// Pre: File stream must be connected to file.
// Post: Returns the number of elements in data file.
int num_el(ifstream & fin);

// disp_drug() randomly generates a name of a drug and displays that name to
//  the screen along with the number of pills to be taken.
// Pre: num should be positive.
// Post: Displays a name of a drug to the screen with the number of pills.
void disp_drug(const int & num);

// disp_surg() randomly generates a surgery for the patient to undergo
// Pre: None.
// Post: Displays name of surgery to screen.
void disp_surg();

// do_again() prompts the user if they'd like to run the program again. Returns
//   the user's response.
// Pre: None.
// Post: Returns user's boolean response to restart the program.
bool do_again();

// The goodbye() function prints a farewell to the console.
// Pre: None.
// Post: Prints a message to the console
void goodbye();

#endif
