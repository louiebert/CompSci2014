//Programmer: LOUIE BERTONCIN                 Date: 10/8/2014
//File: Lab 06 Pass by Reference and Random   Class: CS 1580, Section D
//Purpose: Create random numbers and correctly use pass by reference functions

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Description: This function prints a greeting
// Pre: none
// Post: Displays a greeting
void greeting();

// Description: This function takes in parameters to make a circle.
// Pre: r is expected to be greater than zero
// Post: Defines variables h, k, and r
void readCircle(int & h, int & k, int & r);

// Description: This function assigns random values from 0-10 to x and y.
// Pre: none
// Post: Defines variables x and y
void generatePoint(int & x, int & y);

// Description: This function calculates if given point exists in the
//   defined circle.
// Pre: none
// Post: Outputs -1 if inside, 0 if on the circle, and 1 if outside
int calculateLocation(const int h, const int k, const int r, const int x,
  const int y);

// Description: This function prints a message based on the location of the
//    point relative to the circle.
// Pre: Point needs to be -1, 0, or 1
// Post: Defines variables x and y
void displayLocation(const int point, const int x, const int y);

// This function prints a farewell to the console
// Pre: None
// Post: Prints a message to the console
void goodbye();

int main()
{
  srand(time(NULL));

  int xDisplacement;
  int yDisplacement;
  int radius;
  int xVal;
  int yVal;

  greeting();

  readCircle(xDisplacement, yDisplacement, radius);

  for(int i = 0; i < 10; i++)
  {
    generatePoint(xVal, yVal);
    displayLocation(calculateLocation(xDisplacement, yDisplacement, radius,
      xVal, yVal), xVal, yVal);
  }

  goodbye();

  return 0;
}

void greeting()
{
  cout << "Welcome to the Point Finder, where all your points can be located!"
    "\n\n" << endl;
  return;
}

void readCircle(int & h, int & k, int & r)
{
  cout << "Please input your favorite values for a circle...\n" << endl;
  cout << "The displacement from the x-origin: ";
  cin >> h;
  cout << "The displacement from the y-origin: ";
  cin >> k;
  cout << "And finally your favorite radius for a circle: ";
  cin >> r;
  return;
}

void generatePoint(int & x, int & y)
{
  x = rand() % 10;
  y = rand() % 10;
  return;
}

int calculateLocation(const int h, const int k, const int r, const int x,
  const int y)
{
  int returnVal = 1;

  if ((x-h)*(x-h)+(y-k)*(y-k) == r*r)
  {
    returnVal = 0;
  }
  else if ((x-h)*(x-h)+(y-k)*(y-k) < r*r)
  {
    returnVal = -1;
  }

  return returnVal;
}

void displayLocation(const int point, const int x, const int y)
{
  string location = "on";
  if (point == -1)
  {
    location = "inside";
  }
  else if (point == 1)
  {
    location = "outside";
  }
  cout << "The point (" << x << "," << y << ") is " << location << " the "
    "circle!" << endl;

  return;
}

void goodbye()
{
  cout << "\nIt was nice doing calculations for you, so long now!!" << endl;
  return;
}
