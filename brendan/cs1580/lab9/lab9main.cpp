// Programmer: Brendan Curran              Date: 10/28/2014
// File: lab9main.cpp                      Class: CS 1580 Sec D
// Description: a log in server that inputs a domain, full name,
// username, and password and checks this information to verify
// the login

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
  string input;
  char yn;
  char domain[11];
  char fullName[21];
  char username[11];
  char password[11];
  const char u1[11] = "etnc6d";
  const char u2[11] = "c price";
  const char u3[11] = "Amy Briggs";
  const char u4[11] = "lasanthi";
  const char u5[11] = "nateEloe!!";
  const char pass[11] = "9a$$w0R6";
  bool accept = false, again = true;
  
  while (again)
  {
    accept = false;
    cout << "Log in"" << endl;
    cout << "Enter Domain: ";
    cin >> domain;
    cout << "Enter Full Name: ";
    cin.ignore(500,'"');
    getline(cin, input);
    strcpy(fullName, input.c_str());
    cout << "Enter username: ";
    getline(cin, input);
    strcpy(username, input.c_str());
    cout << "Enter password: ";
     getline(cin, input);
    strcpy(password, input.c_str());
    
    for (int i = 0; i<11; i++)
    {
      domain[i] = toupper(domain[i]);
    }
    cout << "==========Status==========" << endl;
    cout << "Server: " << domain << endl;
    cout << "User: " << username << endl;
    
    if (strcmp(username, u1) == 0 || strcmp(username, u2) == 0)
      accept = true;
    else if (strcmp(username, u3) == 0 || strcmp(username, u4) ==0)
      accept = true;
    else if (strcmp(username, u5) == 0)
      accept = true;
    else
        cout << "Username not recognized"" << endl;
    
    if (accept)
      {
        if (strcmp(password,pass) ==0)
          cout << "ACCESS GRANTED"" << endl;
        else 
          cout << "ACCESS DENIED"" << endl;
      }
    
  
    cout << "Try again? (y/n); ";
    cin >> yn;
    if (yn != 'y')
      again = false;
  }
  return 0;
}