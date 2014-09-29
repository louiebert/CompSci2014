//Programmer: LOUIE BERTONCIN     Date: 9/29/2014
//File: H5 Health-o-Matic         Class: CS 1570, Section D
//Purpose: Use functions to calculate various health equations

#include <iostream>
using namespace std;

void greeting();
void display_menu();
float bodyMassIndex(int weight, int height);
float creatinineClearance(int age, int weight, float creatine);
int coronaryRisk(float bmi, bool either_parent, short bacon_lbs);
float totterIndex(float left_leg_length, float right_leg_length);
void goodbye();

int main()
{
  int choice;
  bool choice_invalid = false;

  greeting();

  do
  {
    choice_invalid = false;

    display_menu();
    cin >> choice;

    switch (choice)
    {
      case 1:
      break;

      case 2:
      break;

      case 3:
      break;

      case 4:
      break;

      case 5:
      break;

      default:
      choice_invalid = true;
    }
  } while (choice_invalid);
  return 0;
}

void greeting()
{
  cout << "Welcome to the Health-o-Matic machine!!" << endl << endl;
  return;
}

void display_menu()
{
  cout << "Here are all the wonders you have at your fingertips!\n" << endl;
  cout << "1. Body Mass Index" << endl;
  cout << "2. Creatinine Clearance" << endl;
  cout << "3. Coronary Risk" << endl;
  cout << "4. Totter Index" << endl;
  cout << "5. Quit\n" << endl;
  cout << "Please choose an option from above: ";
}

float bodyMassIndex(int weight, int height)
{

}

float creatinineClearance(int age, int weight, float creatine)
{
  
}
