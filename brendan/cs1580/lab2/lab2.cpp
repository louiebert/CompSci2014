// Programmer: Brendan Curran               Date: 9/10/2014
// File: lab2.cpp (BMI calculator)          Class: CS 1580 Sec D

#include <iostream>
using namespace std;

int main()
{
    int height;
	int weight;
	float bmi;
	float goal; //bmi goal entered by user
	int goalweight; //weight they need to hit bmi goal
	
	cout << "Welcome to the BMI Calculator\n\n";
	cout << "Please enter your weight (pounds): ";
	cin >> weight;
	cout << "Please enter your height (inches): ";
	cin >> height;
	bmi = static_cast<float>(weight)*703/(height*height);
	cout << "The BMI value for " << weight << " pounds and " << height << " inches is " << bmi << endl;
	
	cout << "\nEnter the BMI value you would like to obtain: "; //start of mass calculator
	cin >> goal;
	goalweight = goal*height*height/703;
	cout << "To reach a BMI of " << goal << " you must weigh " << goalweight << " pounds\n";
	cout << "Thanks for using the BMI calculator\n";
	
  
}

