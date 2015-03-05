//Programmer: LOUIE BERTONCIN       Date: 10/28/2014
//File: lab09.h                     Class: CS 1580, Section D
//Purpose: Header file for the log in program.

#ifndef LAB9_H
#define LAB9_H

using namespace std;

const int DOMAIN_LENGTH = 10;
const int NAME_LENGTH = 20;
const int USERNAME_LENGTH = 10;
const int PASSWORD_LENGTH = 10;
const char USERNAME1[] = "etnc6d";
const char USERNAME2[] = "c_price";
const char USERNAME3[] = "Amy_Briggs";
const char USERNAME4[] = "lasanthi";
const char USERNAME5[] = "nateEloe!!";
const char PASSWORD[] = "9a$$w0R6";

// greeting() outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// get_domain_name() prompts the user for a domain name and sets the parameter
//   to the user's input.
// Pre: None
// Post: Sets paramater to a null-terminated character array of the user's input
//   with maximimum length of DOMAIN_LENGTH
void get_domain_name(char domain[]);

// get_name() prompts the user for a name and sets the parameter to the user's
//   input.
// Pre: None
// Post: Sets paramater to a null-terminated character array of the user's input
//   with maximimum length of NAME_LENGTH
void get_name(char name[]);

// get_username() prompts the user for a username and sets the parameter
//   to the user's input.
// Pre: None
// Post: Sets paramater to a null-terminated character array of the user's input
//   with maximimum length of USERNAME_LENGTH
void get_username(char usrnm[]);

// get_password() prompts the user for a password and sets the parameter
//   to the user's input.
// Pre: None
// Post: Sets paramater to a null-terminated character array of the user's input
//   with maximimum length of PASSWORD_LENGTH
void get_password(char pswrd[]);

// username_correct() checks if the username paramater matches any of the
//   hardcoded ones; if so, returns true, else false.
// Pre: usr[] should be a null-terminated character array.
// Post: Returns true if usr[] matches a correct username. False otherwise.
bool username_correct(const char usr[]);

// password_correct() checks if the password paramater matches the hardcoded
//   one; if so, returns true, else false.
// Pre: pswrd[] should be a null-terminated character array.
// Post: Returns true if pswrd[] matches the correct password. False otherwise.
bool password_correct(const char pswrd[]);

// print_results() prints whether or not the username and password are correct.
// Pre: usr is if the username is correct, pswrd is if the pswrd is correct.
// Post: Prints the results of the attempted login.
bool print_results(const bool & isusr, const bool & ispswrd, const char srvr[],
  const char usr[]);

#endif
