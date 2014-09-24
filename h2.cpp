//Programmer: Louie Bertoncin   Date: 9/8/2014
//File: H2 Dose Calculator      Class: CS 1570, Section D

#include <iostream>
using namespace std;

int main(){
  short dosage; // Whole number of pills rounded from calculation
  short age; // Integer input from user
  short iq; // Integer input from user
  short freq; // Integer input from user (pills/day)
  bool gen; // Boolean gender input from user
  float wt; // Weight entered by user in kilograms
  static short dec = 20; // Dr. Eloe's Constant
  static short ts = 250; // Tablet strength

  cout << "Welcome to the Dose Calculator!!\n" << endl;
  cout << "What is your age: ";
  cin >> age;
  cout << "What is your weight in kilograms: ";
  cin >> wt;
  cout << "How about your IQ: ";
  cin >> iq;
  cout << "And your gender (1 is male, 0 is female): ";
  cin >> gen;
  cout << "And, finally, how many pills do you want to take in a day: ";
  cin >> freq;

  dosage = ((static_cast<float>(age)/iq)*((wt/freq)+1)*((static_cast<float>(ts)/1000)+gen)+dec+0.5)/1;

  cout << "\nDr. Eloe says:" << endl;
  cout << "For the values input:" << endl;
  cout << "     Age: " << age << endl;
  cout << "     Weight: " << wt << endl;
  cout << "     IQ: " << iq << endl;
  cout << "     Gender: " << (gen == 1 ? "Male" : "Female") << endl;
  cout << "     Frequency: " << freq << endl;
  cout << "     Tablet strength of 250 mg" << endl;
  cout << "The recommended dosage is " << dosage << " tablets.\n" << endl;

  return 0;
}
