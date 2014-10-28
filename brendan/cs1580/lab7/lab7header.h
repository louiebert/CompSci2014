// Programmer: Brendan Curran              Date: 10/14/2014
// File: lab7header.h                    Class: CS 1580 Sec D
// Description: contains 2 function prototypes and a struct
// to represent a pixel

#ifndef LAB7HEADER_H
#define LAB7HEADER_H

//struct to represent a pixel, will contain three values
//in set [0,255] for rgb values
struct Pixel
{
  float m_red;
  float m_green;
  float m_blue;
};

//Description: Changes a pixel to its grayscale value and returns its value
//utilizes templated rgbToGray function 
//Pre: Pixel Parameter containing valid rgb values
//Post: returns an unsigned char containing grayscale value
unsigned char rgbToGray(const Pixel p);

//Description: outputs to screen the original pixel and its gray value
//Pre: Pixel parameter containing valid rgb values and unsigned char
//containing the gray value
//Post: outputs to screen in format <r,g,b> -> grayvalue
void output(const Pixel p, const unsigned char grayValue);

//Description: Prompts user to input values for a pixel and returns them
//Pre: none
//Post: returns struct Pixel with values entered by user
Pixel getPixel();


#endif