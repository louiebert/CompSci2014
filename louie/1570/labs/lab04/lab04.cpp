//Programmer: LOUIE BERTONCIN     Date: 9/24/2014
//File: Lab 04 For Loops          Class: CS 1580, Section D
//Purpose: Correctly use a for loop with a user input controlling it

#include <iostream>
using namespace std;

int main()
{
  short loops;
  bool choice_invalid = false;
  short choice;
  const string BRAND1 = "Apple";
  short numBrand1 = 0;
  const string BRAND2 = "Lenovo";
  short numBrand2 = 0;
  const string BRAND3 = "Dell";
  short numBrand3 = 0;
  const string BRAND4 = "HP";
  short numBrand4 = 0;

  cout << "\tWelcome to a generic voting machine!" << endl;
  cout << "====================================================="" << endl;
  cout << "Please input how many votes you'd like to count: ";
  cin >> loops;

  for(int i = 0; i < loops; i++)
  {
    do
    {
      choice_invalid = false;

      cout << "\tPlease choose your favorite computer brand" << endl;
      cout << "\t\t----------"" << endl;
      cout << "1. " << BRAND1 << endl;
      cout << "2. " << BRAND2 << endl;
      cout << "3. " << BRAND3 << endl;
      cout << "4. " << BRAND4 << endl << endl;
      cout << "What is your choice from above? ";
      cin >> choice;

      switch (choice)
      {
        case 1:
        numBrand1++;
        cout << BRAND1 << " now has " << numBrand1 << " votes!" <<endl;
        break;

        case 2:
        numBrand2++;
        cout << BRAND2 << " now has " << numBrand2 << " votes!" <<endl;
        break;

        case 3:
        numBrand3++;
        cout << BRAND3 << " now has " << numBrand3 << " votes!" <<endl;
        break;

        case 4:
        numBrand4++;
        cout << BRAND4 << " now has " << numBrand4 << " votes!" <<endl;
        break;

        default:
        cout << "Please choose among the options provided" << endl;
        choice_invalid = true;
      }

    } while (choice_invalid);
  }

  cout << ""And the results are in!!" << endl;
  cout << "++++++++++++++++++++++++++"" << endl;
  cout << BRAND1 << " has " << numBrand1 << " votes" << endl;
  cout << BRAND2 << " has " << numBrand2 << " votes" << endl;
  cout << BRAND3 << " has " << numBrand3 << " votes" << endl;
  cout << BRAND4 << " has " << numBrand4 << " votes" << endl << endl;

  if(numBrand1 >= numBrand2 && numBrand1 > numBrand3 && numBrand1 > numBrand4)
  {
    cout << BRAND1 << " is the winner!" << endl;
  }
  else if (numBrand2 > numBrand1 && numBrand2 >= numBrand3 &&
    numBrand2 > numBrand4)
  {
    cout << BRAND2 << " is the winner!" << endl;
  }
  else if (numBrand3 > numBrand1 && numBrand3 > numBrand2 &&
    numBrand3 >= numBrand4)
  {
    cout << BRAND3 << " is the winner!" << endl;
  }
  else
  {
    cout << BRAND4 << " is the winner!" << endl;
  }

  cout << ""Thanks for voting!!" << endl;

  return 0;
}
