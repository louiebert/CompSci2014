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
  bool choice_invalid = false, either_parent, active = true;
  float creatine, bmi, left_leg_length, right_leg_length;
  short bacon_lbs;

  greeting();
  do
  {
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
          cout << "\nYour Body Mass Index is: " <<
            bodyMassIndex(weight, height) << "!!\n" << endl;
        break;

        case 2:
          cout << "You chose Creatinine Clearance\n" << endl;
          cout << "Please input your age (yrs): ";
          cin >> age;
          cout << "And your weight (kg): ";
          cin >> weight;
          cout << "And your serum creatine value: ";
          cin >> creatine;
          cout << "\nYour Creatinine Clearance is: " <<
            creatinineClearance(age, weight, creatine) << "!!\n" << endl;
        break;

        case 3:
          cout << "You chose Coronary Risk\n" << endl;
          cout << "Please input your BMI: ";
          cin >> bmi;
          cout << "Did either of your parents have heart disease?" << endl;
          cout << "(1 for yes, 0 for no): ";
          cin >> either_parent;
          cout << "And the number of pounds of bacon you ate this morning: ";
          cin >> bacon_lbs;
          cout << "\nYour Coronary Risk is: " <<
            coronaryRisk(bmi, either_parent, bacon_lbs) << "!!\n" << endl;
        break;

        case 4:
          cout << "You chose Totter Index!\n" << endl;
          cout << "Please input your left leg length (inches): ";
          cin >> left_leg_length;
          cout << "Please input your right leg length (inches): ";
          cin >> right_leg_length;
          cout << "\nYour Totter Index is: " <<
            totterIndex(left_leg_length, right_leg_length) << "!!\n" << endl;
        break;

        case 5:
          active = false;
        break;

        default:
        cout << "Your choice was not valid, please try again." << endl;
        choice_invalid = true;
      }
    } while (choice_invalid);
  } while (active);

  goodbye();

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
  return (140-age)*(static_cast<float>(weight)/72)*creatine;
}

int coronaryRisk(float bmi, bool either_parent, short bacon_lbs)
{
  int score = 0;

  score += (bmi > 30 ? 2 : 0);
  score += (either_parent ? 1 : 0);
  score += bacon_lbs;

  return score;
}

float totterIndex(float left_leg_length, float right_leg_length)
{
  float totter_index;

  if (left_leg_length == 0 || right_leg_length == 0)
  {
    totter_index = 0;
  }
  else
  {
    totter_index = left_leg_length/right_leg_length;
  }

  return totter_index;
}

void goodbye()
{
  cout << "It was nice doing calculations for you, so long now!!" << endl;
  return;
}
