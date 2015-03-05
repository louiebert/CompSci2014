//Programmer: LOUIE BERTONCIN     Date: 9/29/2014
//File: H5 Health-o-Matic         Class: CS 1570, Section D
//Purpose: Use functions to calculate various health equations

#include <iostream>
using namespace std;

// This function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// This function displays a menu for the user to choose from.
// Pre: None
// Post: Menu of calculation options appears in the console
void display_menu();

// This function calculates and returns Body Mass Index.
// Pre: Height cannot be zero
// Post: Body Mass Index is returned
float bodyMassIndex(const int weight, const int height);

// This function calculates and returns Creatinine Clearance.
// Pre: Age is assumed to be less than 140
// Post: Returns calculated Creatinine Clearance
float creatinineClearance(const int age, const int weight,const float creatine);

// This function calculates and returns Coronary Risk.
// Pre: None
// Post: Returns calculated Coronary Risk
int coronaryRisk(const float bmi,const bool either_parent,
  const short bacon_lbs);

// This function calculates and returns Totter Index.
// Pre: None
// Post: Returns calculated Totter Index
float totterIndex(const float left_leg_length, const float right_leg_length);

// This function prints a farewell to the console
// Pre: None
// Post: Prints a message to the console
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
          cout << "You chose Body Mass Index!"" << endl;
          cout << "Please input your weight (lbs): ";
          cin >> weight;
          cout << "And your height (inches): ";
          cin >> height;
          cout << ""Your Body Mass Index is: " <<
            bodyMassIndex(weight, height) << "!!"" << endl;
        break;

        case 2:
          cout << "You chose Creatinine Clearance"" << endl;
          cout << "Please input your age (yrs): ";
          cin >> age;
          cout << "And your weight (kg): ";
          cin >> weight;
          cout << "And your serum creatine value: ";
          cin >> creatine;
          cout << ""Your Creatinine Clearance is: " <<
            creatinineClearance(age, weight, creatine) << "!!"" << endl;
        break;

        case 3:
          cout << "You chose Coronary Risk"" << endl;
          cout << "Please input your BMI: ";
          cin >> bmi;
          cout << "Did either of your parents have heart disease?" << endl;
          cout << "(1 for yes, 0 for no): ";
          cin >> either_parent;
          cout << "And the number of pounds of bacon you ate this morning: ";
          cin >> bacon_lbs;
          cout << ""Your Coronary Risk is: " <<
            coronaryRisk(bmi, either_parent, bacon_lbs) << "!!"" << endl;
        break;

        case 4:
          cout << "You chose Totter Index!"" << endl;
          cout << "Please input your left leg length (inches): ";
          cin >> left_leg_length;
          cout << "Please input your right leg length (inches): ";
          cin >> right_leg_length;
          cout << ""Your Totter Index is: " <<
            totterIndex(left_leg_length, right_leg_length) << "!!"" << endl;
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
  cout << "Welcome to the Health-o-Matic machine!!"" << endl;
  return;
}

void display_menu()
{
  cout << "Here are all the wonders you have at your fingertips!"" << endl;
  cout << "1. Body Mass Index" << endl;
  cout << "2. Creatinine Clearance" << endl;
  cout << "3. Coronary Risk" << endl;
  cout << "4. Totter Index" << endl;
  cout << "5. Quit"" << endl;
  cout << "Please choose an option from above: ";
  return;
}

float bodyMassIndex(const int weight, const int height)
{
  return (static_cast<float>(weight)/(height*height))*703;
}

float creatinineClearance(const int age, const int weight, const float creatine)
{
  return (140-age)*(static_cast<float>(weight)/72)*creatine;
}

int coronaryRisk(const float bmi,const bool either_parent,const short bacon_lbs)
{
  int score = 0;

  score += (bmi > 30 ? 2 : 0);
  score += (either_parent ? 1 : 0);
  score += bacon_lbs;

  return score;
}

float totterIndex(const float left_leg_length, const float right_leg_length)
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
