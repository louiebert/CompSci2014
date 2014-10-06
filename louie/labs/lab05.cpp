//Programmer: LOUIE BERTONCIN     Date: 9/24/2014
//File: Lab 05 Functions          Class: CS 1580, Section D
//Purpose: Use functions to find area and perimeter of a rectangle

#include <iostream>
using namespace std;

// Description : Prints a greeting
// Pre : none
// Post : Displays a greeting
void greeting();

// Description : displays the menu
// Pre : none
// Post : displays the menu options
void display_menu();

// Description : display a message and get the value of a side
// Pre : none
// Post : value of the side is returned
float get_side();

// Description : Find and display the area (f_side1 * f_side2)
// Pre : both f_side1 and f_side2 are positives
// Post : calculated area is displayed
float calculate_area(float length, float width);

// Description : Find and display the perimeter (2*f_side1) +(2*f_side2)
// Pre : both f_side1 and f_side2 are positives
// Post : calculated perimeter is displayed
float calculate_perimeter(float length, float width);

// Description : Prints a greeting
// Pre : none
// Post : Displays a greeting
void salutation();

int main()
{
  // Variable declarations
  int choice;
  bool invalid_choice = false, active = true;
  float length;
  float width;

  // Actual program
  greeting();

  do
  {
    do
    {
      invalid_choice = false;
      display_menu();
      cin >> choice;

      switch (choice)
      {
        // Calculates the area
        case 1:
        cout << "\nYou chose to calculate area!\n" << endl;
        cout << "Please define the first side: ";
        length = get_side();
        cout << "And the second side: ";
        width = get_side();
        cout << "\nAnd the area of your rectangle is: " <<
          calculate_area(length, width) << "!!\n\n" << endl;
        break;

        // Calculates the perimeter
        case 2:
        cout << "\nYou chose to calculate perimeter!\n" << endl;
        cout << "Please define the first side: ";
        length = get_side();
        cout << "And the second side: ";
        width = get_side();
        cout << "\nAnd the perimeter of your rectangle is: " <<
          calculate_perimeter(length, width) << "!!\n\n" << endl;
        break;

        // Quits the program (jumping out of the larger do-while loop)
        case 3:
        active = false;
        break;

        // Informs the user of invalid input and requests again
        default:
        cout << "\nYou did not choose from the options provided. Try again.\n"
          << endl;
        invalid_choice = true;
      }
    } while (invalid_choice);
  } while (active);

  salutation();
}

void greeting()
{
  cout << "Welcome to the rectangle calculator!!\n" << endl;
  return;
}

void display_menu()
{
  cout << "Rectangle calculating options" << endl;
  cout << "=============================\n" << endl;
  cout << "1. Area" << endl;
  cout << "2. Perimeter" << endl;
  cout << "3. Nevermind, I'm done\n" << endl;
  cout << "Please choose a number from above: ";
}

float get_side()
{
  float side;
  cin >> side;
  if (side < 0)
    side *= -1;
  return side;
}

float calculate_area(float length, float width)
{
  return length*width;
}

float calculate_perimeter(float length, float width)
{
  return (2*length+2*width);
}

void salutation()
{
  cout << "\nThanks for calculating rectangles! It was a real pleasure!\n"
    << endl;
  return;
}
