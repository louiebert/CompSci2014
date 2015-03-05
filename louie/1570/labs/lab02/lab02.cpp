//Programmer: Louie Bertoncin   Date: 9/8/2014
//File: Lab 2 BMI Calculator    Class: CS 1580, Section D

#include <iostream>
using namespace std;

int main(){
static short conFactor = 703;
short height;
short weight;
float bmi;

cout << "You are using the BMI Calculator!""" << endl;
cout << "Please input your height and mass." << endl;
cout << "Height (in inches): ";
cin >> height;
cout << "Weight (in pounds): ";
cin >> weight;

bmi = (static_cast<float>(weight)*conFactor)/(height*height);

cout << "Your calculated BMI from " << height << " inches and " << weight << " pounds is " << bmi << endl;

cout << "Enter the BMI you'd like to obtain: ";
cin >> bmi;

weight = (static_cast<float>(bmi)*height*height)/conFactor

cout << "The required weight needed for a BMI of " << bmi << " is " << weight << " pounds."" << endl;

return 0;
}
