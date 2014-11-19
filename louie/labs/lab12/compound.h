//Programmer: LOUIE BERTONCIN     Date: 11/18/2014
//File: compound.h                Class: CS 1580, Section D
//Purpose: Header file for the Compound class.

#ifndef COMPOUND_H
#define COMPOUND_H

#include <string>
#include <iostream>

using namespace std;

const int ELEMENT_COUNT = 112;

class Compound
{
  private:
    string name;
    int elements[ELEMENT_COUNT];
    float kg;
  public:
    // Default constructor
    // Pre: None.
    // Post: Name is "unknown", all elements[] are 0, and kg is 0.
    Compound() : name("unknown"), elements(), kg(0) {};

    // Addition operator for Compound class
    // Pre: None.
    // Post: Appends names, adds all elements together, and adds kg.
    Compound& operator + (const Compound& other);

    friend Compound& operator * (Compound& comp, const float amount);
    friend ostream& operator << (ostream& out, const Compound& comp);
    friend istream& operator >> (istream& in, Compound& comp);
};


#endif