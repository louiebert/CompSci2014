//Programmer: LOUIE BERTONCIN       Date: 10/28/2014
//File: lab09.cpp                   Class: CS 1580, Section D
//Purpose: Main file for the log in program.

#include <iostream>
#include <cstring>
#include <string>
#include "lab09.h"

using namespace std;

int main()
{
  char domainName[DOMAIN_LENGTH+1];
  char name[NAME_LENGTH+1];
  char username[USERNAME_LENGTH+1];
  char password[PASSWORD_LENGTH+1];

  greeting();

  do
  {
    get_domain_name(domainName);
    get_name(name);
    get_username(username);
    get_password(password);
  }while(!print_results(username_correct(username), password_correct(password),
    domainName, name));

  return 0;
}
