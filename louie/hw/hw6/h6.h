//Programmer: LOUIE BERTONCIN     Date: 10/11/2014
//File: h6.h                      Class: CS 1570, Section D
//Purpose: This file contains the header info for the program that detects
//  protein levels in a fake patient to diagnose Jejunal Hemorrhage Syndrome.

#ifndef H6_H
#define H6_H

using namespace std;

const int PROTEIN1MAX = 100;
const int PROTEIN2MAX = 1000;
const int PROTEIN3MAX = 10;
const int PROTEIN4MIN = 10;
const int PROTEIN4MAX = 50;
const int PROTEIN5MAX = 10;

struct proteins
{
  int protein1;
  float protein2;
  int protein3;
  int protein4;
  int protein5;
};

// The greeting() function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// This function displays a menu for the user to choose from.
// Pre: None
// Post: Menu of procedure options appears in the console
void display_menu(int & user_choice);

// The function get_name() prompts the user for the patient's name and saves it.
// Pre: None
// Post: Saves the user's input to the parameter
void get_name(string & patient_name);

// The function a_flat() generates values for protein 1, 2, and 3.
// Pre: None
// Post: Changes the values of the variables provided.
void a_flat(int & p1, float & p2, int & p3);

// The function a_flat_mistake() makes the parameter false 5% of the time.
// Pre: None
// Post: Makes bool heard false 5% of the time, and if false, prints a message.
void a_flat_mistake(bool & heard);

// The function middle_g() generates values for protein 2 and 4.
// Pre: None
// Post: Changes the values of the variables provided.
void middle_g(float & p2, int & p4);

// The function middle_g_mistake() makes the parameter false 5% of the time.
// Pre: None
// Post: Makes bool heard false 5% of the time, and if false, prints a message.
void middle_g_mistake(bool & heard);

// The function c_flat() generates values for protein 1, 4, and 5.
// Pre: None
// Post: Changes the values of the variables provided.
void c_flat(int & p1, int & p4, int & p5);

// The function c_flat_mistake() makes the parameter false 5% of the time.
// Pre: None
// Post: Makes bool heard false 5% of the time, and if false, prints a message.
void c_flat_mistake(bool & heard);

// The function make_a_proteins() fills a proteins object with the first five
//   parameters of the function and returns it.
// Pre: None
// Post: Returns the provided protein values in a proteins object
proteins make_a_proteins(const int & p1, const float & p2, const int & p3,
  const int & p4, const int & p5, proteins & prots);

// The function diagnose() determines if the patient has JHS from their proteins
// Pre: Protein parameter needs to be created from the three tone functions.
// Post: Outputs a 1 if patient has JHS, a 0 if not.
bool diagnose(const proteins & prots);

// The function printDiagnosis() prints a message to the user, informing them
//   if they are diagnosed with Jejunal Hemorrhage Syndrome or not.
// Pre: Bool is 1 if they are affected, 0 if not.
// Post: Prints a friendly diagnosis with the patient's name.
void printDiagnosis(const bool & isAffected, const string & patient_name);

// The goodbye() function prints a farewell to the console.
// Pre: None
// Post: Prints a message to the console
void goodbye();

#endif
