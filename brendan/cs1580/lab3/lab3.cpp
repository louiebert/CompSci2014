// Programmer: Brendan Curran               Date: 9/17/2014
// File: lab2.cpp loops and menus           Class: CS 1580 Sec D

#include <iostream>
using namespace std;

int main()
{
  char choice;
  int fivetest;
  bool loopcontrol =true;
  
  cout << ""Hello user"";
  do
  {
    cout << ""What would you like to do"a. divisible by 5 test"b. output secret messege"c. Exit"";
	cin >> choice;
	
	if (choice == 'a')
	{
	  cout << ""Enter an integer: ";
	  cin >> fivetest;
	  if (fivetest%5 == 0)
	    cout << fivetest << " is divisible by 5"";
	  else 
	    cout << fivetest << " is not divisible by 5"";
	}
	else if (choice == 'b')
	  cout << ""Potato is life"";
	else if (choice == 'c')
	  loopcontrol = false;
  }
  while (loopcontrol == true);
  cout << "goodbye"";
  return 0;
}
