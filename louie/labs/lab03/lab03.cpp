//Programmer: LOUIE BERTONCIN          Date: 9/17/2014
//File: Lab03 Loops and Conditionals   Class: CS 1580, Section D

#include <iostream>
using namespace std;

int main()
{
  string menu_letter;
  short num_typed;
  bool active = true;

  cout << "Welcome to a simple Loops and Conditionals Program!!\n\n";

  do
  {
    do
    {
    cout << "Please choose a path from the following list:\n\n";
    cout << "a. Check if a number is divisible by 5!!\n";
    cout << "b. Discover a mystery message from the command prompt!\n";
    cout << "c. Exit this terribly intriguing program.\n\n";
    cout << "Select the letter of the path you'd like to take: ";
    cin >> menu_letter;
    if (menu_letter == "A")
      menu_letter = "a";
    else if (menu_letter == "B")
      menu_letter = "b";
    else if (menu_letter == "C")
      menu_letter = "c";
  } while (menu_letter != "a" && menu_letter != "b" && menu_letter != "c");

    if (menu_letter == "a")
    {
      cout << "\nWahoo!! You now can check if a number can be evenly divided \
by five!!\n\n";
      cout << "Now you must enter the number you are curious about: ";
      cin >> num_typed;
      cout << "Your number \"" << num_typed << "\" " << (num_typed % 5 ?
        "is not" : "is") << " divisible by five!!\n\n";
    }
    else if (menu_letter == "b")
    {
      cout << "\nThe secret message is as follows...\n\n";
      cout << "\"Eat at Lucky House and your dreams will come true.\"\n\n";
    }
    else
    {
      cout << "\nHope you had as much fun with this program as I did! Bye!!\n";
      active = false;
    }

  } while (active);


  return 0;
}
