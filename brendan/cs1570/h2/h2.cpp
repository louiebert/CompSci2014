//Programmer: Brendan Curran    Date: 9/10/2014
//File: H2 dose calculator      Class cs 1570, section C

#include <iostream>
using namespace std;

int main()
{
  int age;
  float weight;
  int iq;
  int gender; //used in formula, input by user 1 or 0
  int genderout; //used to output string male or female
  int freq; //tablets per day input
  int dose; //number of tablets prescribed, calculated by formula
  static int eloenum = 20; //constant for formula
  static int ts = 250; //constant tablet strength
  int asciif = 102; //ascii for f
  int asciie = 101; //ascii for e
  char fff; //will be used to output f if female
  char eee; //will be used to output e, if male will get multiplied to 0 so it doesnt output
  
  cout << "Welcome to Dr. Eloe's prescription program"";
  cout << "Enter age: ";
  cin >> age;
  cout << "enter weight: ";
  cin >> weight;
  cout << "enter IQ: ";
  cin >> iq;
  cout << "enter gender (1 - male, 0 - female): ";
  cin >> gender;
  cout << "enter frequency (tablets/day): ";
  cin >> freq;
  
  genderout = gender + 1;  //stupid calculations to switch 1 and 0
  genderout = genderout%2; //set gender int to male = 0 and female = 1
  asciif = asciif*genderout; //ascii code remains same if female, int*1 = int
  asciie = asciie*genderout; //ascii code goes to null if male, int*0 = 0
  fff= asciif; //character = ascii code
  eee= asciie; //wasn't informed of ternary statements before I wrote all this crap
  
  dose  = ((static_cast<float>(age)/iq)*((weight/freq)+1)*((static_cast<float>(ts)/1000)+gender)+eloenum)+.5;
  cout << ""Dr. Eloe: "For the values input:";
  cout << ""    Age = " << age;
  cout << ""    Weight = " << weight;
  cout << ""    IQ = " << iq;
  cout << ""    Gender = " << fff << eee << "male";
  cout << ""    Frequency = " << freq;
  cout << ""    Tablet strength of " << ts << " mg";
  cout << ""The recommended dosage is " << dose << " tablets";
  cout << """Thank you and please come again"";
  return 0;
  
}
