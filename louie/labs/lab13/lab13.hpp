//Programmer: LOUIE BERTONCIN     Date: 12/2/2014
//File: lab13.hpp                 Class: CS 1580, Section D
//Purpose: Struct definition file for Lab13

#include <iostream>

using namespace std;

struct Horse
{
  public:
    friend istream& operator >> (istream& in, Horse& aHorse);
    friend ostream& operator << (ostream& out, const Horse& aHorse);
    string m_name;
    char m_gender;
};

struct Cat
{
  public:
    friend istream& operator << (istream& in, Cat& aCat);
    friend ostream& operator << (ostream& out, const Cat& aCat);
    string m_name;
    char m_gender;
};


istream& operator >> (istream& in, Horse& aHorse)
{
  char aGender;
  cout << "Horse name: ";
  in >> aHorse.m_name;
  cout << "Horse gender(M/F): ";
  in >> aGender;
  aHorse.m_gender = toupper(aGender);

  return in;
}

ostream& operator << (ostream& out, const Horse& aHorse)
{
  out << aHorse.m_name << "(" << aHorse.m_gender << ")";

  return out;
}

istream& operator >> (istream& in, Cat& aCat)
{
  char aGender;
  cout << "Cat name: ";
  in >> aCat.m_name;
  cout << "Cat gender(M/F): ";
  in >> aGender;
  aCat.m_gender = toupper(aGender);

  return in;
}

ostream& operator << (ostream& out, const Cat& aCat)
{
  out << aCat.m_name << "(" << aCat.m_gender << ")";

  return out;
}


