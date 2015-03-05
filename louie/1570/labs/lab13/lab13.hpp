//Programmer: LOUIE BERTONCIN     Date: 12/2/2014
//File: lab13.hpp                 Class: CS 1580, Section D
//Purpose: Struct definition file for Lab13

#include <iostream>

using namespace std;

const int ACTION_LENGTH = 5;

// Horse Constructor creates a horse and populates its actions.
// Pre: None.
// Post: New horse is created.

// Horse Extraction Operator reads in a horse from user inputs.
// Pre: None.
// Post: A horse becomes defined by the user's prompted input.

// Horse Insertion Operator prints out a Horse object to the given ostream.
// Pre: None.
// Post: Horse object is printed.

// Horse.act() returns a random one of the five Horse actions.
// Pre: None.
// Post: A string of the horse's action is returned.

// Cat Constructor creates a cat and populates its actions.
// Pre: None.
// Post: New cat is created.

// Cat Extraction Operator reads in a cat from user inputs.
// Pre: None.
// Post: A cat becomes defined by the user's prompted input.

// Cat Insertion Operator prints out a Cat object to the given ostream.
// Pre: None.
// Post: Cat object is printed.

// Cat.act() returns a random one of the five Cat actions.
// Pre: None.
// Post: A string of the cat's action is returned.

struct Horse
{
  public:
    Horse();
    friend istream& operator >> (istream& in, Horse& aHorse);
    friend ostream& operator << (ostream& out, const Horse& aHorse);
    string act() const;
    string m_name;
    char m_gender;
    string m_actions[ACTION_LENGTH];
};

struct Cat
{
  public:
    Cat();
    friend istream& operator << (istream& in, Cat& aCat);
    friend ostream& operator << (ostream& out, const Cat& aCat);
    string act() const;
    string m_name;
    char m_gender;
    string m_actions[ACTION_LENGTH];
};

Horse::Horse()
{
  m_name = "";
  m_gender = '\0';
  m_actions[0] = " is galloping in the wind.";
  m_actions[1] = " is whinnying.";
  m_actions[2] = " is shaking its mane.";
  m_actions[3] = " is eating an apple.";
  m_actions[4] = " is relieving itself.";
}

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
  out << aHorse.m_name << " (" << aHorse.m_gender << ")";

  return out;
}

string Horse::act() const
{
  return m_actions[rand()%ACTION_LENGTH];
}

Cat::Cat()
{
  m_name = "";
  m_gender = '\0';
  m_actions[0] = " is drinking milk.";
  m_actions[1] = " is chasing Jerry.";
  m_actions[2] = " is grooming itself.";
  m_actions[3] = " is discovering the litter box.";
  m_actions[4] = " is sniffing a new friend.";
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
  out << aCat.m_name << " (" << aCat.m_gender << ")";

  return out;
}

string Cat::act() const
{
  return m_actions[rand()%ACTION_LENGTH];
}


