// Programmer: ALEX SHAW      Student ID: 12423794
// Lab: 05                    Filename: lab05.cpp
// Due date: 10/1/14          Class: CS 1580, D
//
// Purpose: Prompt for values of length and width. Allow the user to
// choose whether to have the program calculate the area of the rectangle
// or the perimeter.


#include<iostream>
using namespace std;

//------------------------------Prototypes of functions-----------------------//

// Description : displays the menu
// Pre : none
// Post : displays the menu options
void displayMenu();

// Description : Find and display the area (width * length)
// Pre : both width and length are positive
// Post : calculated area is displayed
void area(const float width, const float length);

// Description : Find and display the perimeter (2*width) +(2*length)
// Pre : both width and length are positive
// Post : calculated perimeter is displayed
void perimeter(const float width, const float length);

// Description : display a message and get the value of a side
// Pre : none
// Post : value of the side is returned
float getSide();

int main()
{

//--------------------------Declare and/or initialize vars--------------------//
  float width = 0.0;
  float length = 0.0;
  int menu_choice = 0;        //Holds what choice the user picked from menu
  bool quit = false;          //Determines if user quits
  bool valid_choice = true;   //Determines if user input invalid menu choice

  do
  {
    valid_choice = true;      //Resets in case user input invalid choice

//------------------------Prompts for and stores length and width-------------//
    do
    {
      width = float getside();
      length = float getside();
    } while (width <= 0 || length <= 0);       //Continues prompting until user
                                               // enters valid choice

//---Continues displaying menu of possible calculations until user quits------//
    do
    {
      void displayMenu();       //Call function to display menu

      cin >> menu_choice;       //Store user's menu choice

      switch(menu_choice)
      {
        case 1:
          void area(width, length);             //Calculate and display area
          break;
        case 2:
          void perimeter(width, length);       //Calculate and display perimeter
          break;
        case 3:
          quit = true;                         //Exit program if user quits
          break;
        default:
          valid_choice = false;                //Assign false to valid_choice
          cout << "Error: Enter a valid choice."
          break;
      }

    } while(!valid_choice);

  } while(!quit);

  return 0;
}


//------------------------Function definitions--------------------------------//


//--------------------Displays menu and prompts for choice--------------------//

void displayMenu()
{
  cout << """\t\t\tMenu";
       << "1. Find and display area";
       << "2. Find and display perimeter";
       << "3. Cancel and exit" << endl;
  cout << "Choice (number): ";
}


//----------------Calculates and displays area------------------------------- //

void area(const float width, const float length)
{
  float area = width * length;
  cout << """Area: " << area << endl;
}


//----------------Calculates and displays perimeter---------------------------//

void area(const float width, const float length)
{
  float perimeter = (2 * width) + (2 * length);
  cout << """Perimeter: " << area << endl;
}


//---------------Prompts for and returns side value---------------------------//

float getside(const float side)
{
  cout << """Please enter a value: ";
  cin >> side;
  return side;
}
