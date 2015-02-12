//Programmer: LOUIE BERTONCIN       Date: 10/28/2014
//File: lab09_functions.cpp         Class: CS 1580, Section D
//Purpose: Functions file for the log in program.

#include <iostream>
#include <cstring>
#include <string>
#include "lab09.h"

using namespace std;

void greeting()
{
  cout << "\nLog into the server\n\n" << endl;

  return;
}

void get_domain_name(char domain[])
{
  cout << "========== Log In ==========" << endl;
  cout << "Domain name: ";
  cin >> domain;

  return;
}

void get_name(char name[])
{
  cin.ignore(500, '\n');
  cout << "Your name: ";
  cin.getline(name, NAME_LENGTH+1);

  return;
}

void get_username(char usrnm[])
{
  cout << "Username: ";
  cin.getline(usrnm, USERNAME_LENGTH+1);

  return;
}

void get_password(char pswrd[])
{
  cout << "Password: ";
  cin.getline(pswrd, PASSWORD_LENGTH+1);

  return;
}

bool username_correct(const char usr[])
{
  bool correct = false;

  correct = (!strcmp(usr, USERNAME1) ? true : correct);
  correct = (!strcmp(usr, USERNAME2) ? true : correct);
  correct = (!strcmp(usr, USERNAME3) ? true : correct);
  correct = (!strcmp(usr, USERNAME4) ? true : correct);
  correct = (!strcmp(usr, USERNAME5) ? true : correct);

  return correct;
}

bool password_correct(const char pswrd[])
{
  return !strcmp(pswrd, PASSWORD);
}

bool print_results(const bool & isusr, const bool & ispswrd, const char srvr[],
  const char usr[])
{
  cout << endl;
  if(isusr && ispswrd)
  {
    cout << "Server: " << srvr << endl;
    cout << "Username: " << usr << endl;
    cout << "LOGIN SUCCESS" << endl << endl;
  }
  else
  {
    cout << "Server: " << srvr << endl;
    cout << "Username: " << usr << endl;
    cout << "LOGIN FAILED. Try again" << endl << endl << endl;
  }


  return (isusr && ispswrd);
}
