// File: lab6.cpp                           Class: CS 1580 Sec D
// Programmer: Brendan Curran               Date: 10/8/2014/2014
// Description: use pass by reference and rand number generator
// to test if random points are inside of a circle input by the user

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Description: passes by reference three variables, which get assigned to
//values input by user to create circle with equation (x-h)^2 + (y-k)^2 = r^2
//Pre-Condition: three integer parameters passed by reference, h, k, and r
//Post-Condition: h, k, and r are assigned values by user
void readCircle (int & h, int & k, int & r);

//Description: generates a random point (x,y) each between 0-10
//Pre-Condition: passed by reference two integer parameters
//Post-Condition: x and y are assigned random values
void generatePoint(int & x, int & y);

//Description: Checks where point (x,y) lies in reference to a circle
//with equation (x-h)^2 + (y-k)^2 = r^2, and returns value indicating location
//of the point in reference to the cicrle
//Pre-Condition: 5 integer paramaters, h, k, r representing a circle, x, y 
//representing a point
//Post-Condition: returns -1 for in, 0 for on, and 1 for outside of the circle
int location(int h, int k, int r, int x, int y);

//Description: outputs message to user showing point and its location
//to the cicrle
//Pre-Condition: int location from location function, and point x,y
//Post-Condition: outputs message to user 
void displayResult(int location, int x, int y);


int main()
{
	int h, k, r, x, y, check;
  
  srand(time(NULL));
  cout <<"Welcome to the circle tester\n" << endl;
  readCircle(h, k, r);
  for (int count = 0; count <10; count++)
  {
    generatePoint (x, y);
    check = location(h, k, r, x, y);
    displayResult(check, x, y);
  }
}

void readCircle(int & h, int & k, int & r)
{
  cout << "Input a circle defined as(x-h)^2 + (y-k)^2 = r^2" << endl;
  cout << "h = ";
  cin >> h;
  cout << "k = ";
  cin >> k;
  cout << "r = ";
  cin >> r;
}

void generatePoint( int & x, int & y)
{
  x = rand()%11;
  y = rand()%11;
}

int location(int h, int k, int r, int x, int y)
{
  int result = (x-h)*(x-h)+(y-k)*(y-k);
  if (result > r*r)
    return 1;
  else if (result == r*r)
    return 0;
  else if (result < r*r)
    return -1;
  else 
    return 0;
}

void displayResult(int location, int x, int y)
{
  if (location == -1)
    cout << "Point (" << x << "," << y << ") is inside the circle";
  else if (location == 0)
    cout << "Point (" << x << "," << y << ") is on the circle";
  else if (location == 1)
    cout << "Point (" << x << "," << y << ") is outside of the circle";
  cout << endl;
}
