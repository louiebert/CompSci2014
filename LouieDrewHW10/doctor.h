//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: doctor.h                                Class: CS 1570, Section D
//Purpose: Header file for doctor class

#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

using namespace std;

const short MAX_OZ_SCHRAUT = 25;

// Constructor sets m_name from parameter, sets m_oz_schraut to 0, and m_money
//   to 0.
// Pre: None.
// Post: Creates a Doctor object.

// puke() sets m_oz_schraut to 0.
// Pre: None.
// Post: m_oz_schraut = 0.

// drink_schraut() increases m_oz_schraut by the parameter and calls puke() if
//   m_oz_schraut >= to MAX_OZ_SCHRAUT
// Pre: None.
// Post: Increases m_oz_schraut and calls puke() if it exceeds the max.

// get_oz_schraut() returns m_oz_schraut.
// Pre: None.
// Post: Returns m_oz_schraut.

// increase_money() increases m_money by the parameter.
// Pre: None.
// Post: m_money is increased by the amount provided in the paramater.

// getMoney() returns the m_money
//Pre: None
//Post: m_money is returned.

class Doctor
{
  private:
    string m_name;
    short m_oz_schraut;
    float m_money;
  public:
    Doctor(const string& theName);
    void puke();
    void drink_schraut(const short& amount);
    short get_oz_schraut() const{return m_oz_schraut;}
    void increase_money(const float& amount);
    float getMoney() const{return m_money;}
};

#endif
