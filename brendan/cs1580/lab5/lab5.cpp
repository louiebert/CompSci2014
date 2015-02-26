// Programmer: Brendan Curran               Date: 10/1/2014
// File: lab5.cpp                           Class: CS 1580 Sec D
// Description: Find area or perimeter of rectangle using funtions
#include <iostream>
using namespace std;
 
// Description: displays the menu 
// Pre : none 
// Post : displays the menu options 
void printMenu(); 

// Description: Find and display the area (f_side1 * f_side2) 
// Pre: both f_side1 and f_side2 are positives 
// Post: calculated area is displayed 
void Area(float f_side1, float f_side2); 

// Description : Find and display the perimeter (2*f_side1) +(2*f_side2) 
// Pre : both f_side1 and f_side2 are positives 
// Post : calculated perimeter is displayed 
void Perimeter(float f_side1, float f_side2); 

// Description : display a message and get the value of a side 
// Pre : none 
// Post : value of the side is returned 
float getSide(); 

int main()
{
  cout << ""Welcome to the area and perimeter calculator " << endl;
  bool repeat = true;
  do
  {
    int choice;
    float side1, side2;
    printMenu();
    cout << "your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
      case 1:
        side1 = getSide();
        side2 = getSide();
        Area(side1,side2);
        break;
      case 2:
        side1 = getSide();
        side2 = getSide();
        Perimeter(side1,side2);
        break;
      case 3:
        repeat = false;
        break;
      default:
        cout << "Invalid entry" << endl;
    }
    cout << endl;
  } while (repeat);
  cout << "goodbye "<< endl;
}

void printMenu()
{
  cout << "1. Find and display area "<< endl;
  cout << "2. Find and display perimiter " << endl;
  cout << "3. Cancel and Exit " << endl;
}

float getSide()
{
  float side = 0;
  do
  {
    if (side < 0)
      cout << "Invalid side length, must be positive"";
    cout << "Enter length of side: ";
    cin >> side;    
  } while (side <0);
  return side;
}

void Area(float f_side1, float f_side2)
{
  float area = f_side1*f_side2;
  cout << "area = " << area << endl;
}

void Perimeter (float f_side1, float f_side2)
{
  float perimeter = 2*f_side1+2*f_side2;
  cout << "perimeter = " << perimeter << endl;
}


