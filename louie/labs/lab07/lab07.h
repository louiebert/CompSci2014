//Programmer: LOUIE BERTONCIN       Date: 10/14/2014
//File: lab07.h                     Class: CS 1580, Section D
//Purpose: Header file for structs and functions lab

#ifndef LAB7_H
#define LAB7_H

using namespace std;

const float REDCONVERT = 0.2126;
const float GREENCONVERT = 0.7152;
const float BLUECONVERT = 0.0722;

struct Pixel
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

// The greeting() function outputs a greeting to the user.
// Pre: None
// Post: A greeting string is printed to the console
void greeting();

// This function displays a menu for the user to choose from.
// Pre: None
// Post: Menu of procedure options appears in the console
void display_menu(int & user_choice);

// Function getPixel() returns user input RGB values in a Pixel object.
// Pre: None
// Post: Returns a Pixel object from user input
void getPixel(Pixel & pxl);

// Function rgbToGray() returns a single value in grayscale calculated from the
//   three input colors.
// Pre: All three parameters need to be integers between 0-255
// Post: Returns a grayscale value from three colors.
template < typename T >
T rgbToGray(const T red, const T green, const T blue);

// Function rgbToGray() takes in a Pixel object and returns a grayscale value
//   for that colored Pixel object.
// Pre: None
// Post: Returns a 0-255 grayscale value converted from a provided color pixel.
unsigned char rgbToGray(const Pixel p);

// Function output() prints the pixel and the grayscale value
// Pre: None
// Post: Prinst a pixel's values to the console window
void output(const Pixel p, const unsigned char grayValue);

// The goodbye() function prints a farewell to the console.
// Pre: None
// Post: Prints a message to the console
void goodbye();

#endif
