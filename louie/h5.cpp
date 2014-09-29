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
  int choice, weight, height, age;
  bool choice_invalid = false, either_parent;
  float creatine, bmi, left_leg_length, right_leg_length;
  short bacon_lbs;

  greeting();

  do
  {
    choice_invalid = false;

    display_menu();
    cin >> choice;

    switch (choice)
    {
      case 1:
      cout << "You chose Body Mass Index!\n" << endl;
      cout << "Please input your weight (lbs): ";
      cin >> weight;
      cout << "And your height (inches): ";
      cin >> height;
      cout << "\nYour Body Mass Index is: " << bodyMassIndex(weight, height) <<
        "!!" << endl;
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
      cout << "Your choice was not valid, please try again." << endl;
      choice_invalid = true;
    }
  } while (choice_invalid);
  return 0;
}

void greeting()
{
  cout << "Welcome to the Health-o-Matic machine!!\n" << endl;
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
  return (static_cast<float>(weight)/(height*height))*703;
}

float creatinineClearance(int age, int weight, float creatine)
{
  float cClearance;

  return cClearance;
}

int coronaryRisk(float bmi, bool either_parent, short bacon_lbs)
{
  int coronaryRisk;

  return coronaryRisk;
}

float totterIndex(float left_leg_length, float right_leg_length)
{
  float totterIndex;

  return totterIndex;
}
