// Programmer: Brendan Curran               Date: 9/17/2014
// File: lab2.cpp loops and menus           Class: CS 1580 Sec D

#include <iostream>
using namespace std;

int main()
{
  char choice;
  int fivetest;
  bool loopcontrol =true;
  
  cout << "\nHello user\n";
  do
  {
    cout << "\nWhat would you like to do\na. divisible by 5 test\nb. output secret messege\nc. Exit\n";
	cin >> choice;
	
	if (choice == 'a')
	{
	  cout << "\nEnter an integer: ";
	  cin >> fivetest;
	  if (fivetest%5 == 0)
	    cout << fivetest << " is divisible by 5\n";
	  else 
	    cout << fivetest << " is not divisible by 5\n";
	}
	else if (choice == 'b')
	  cout << "\nPotato is life\n";
	else if (choice == 'c')
	  loopcontrol = false;
  }
  while (loopcontrol == true);
  cout << "goodbye\n";
  return 0;
}
