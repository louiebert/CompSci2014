//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: doctor.h                  Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the class definition for the class that simulates
// a doctor within the program that simulates a patient and a doctor
// visiting hospital rooms.bool puke()

#ifndef DOCTOR_H
#define DOCTOR_H

#include <cstdlib>
#include <iostream>
using namespace std;

//----------------------------Global constants-------------------------------//
short PUKE_LVL = 25;        //Oz of Schraut that warrants puking
short POST_PUKE_LVL = 0;    //Oz of Schraut in doctor's stomach after puking
short MIN_SCHRAUT = 1;      //Range of Schraut consumed
short MAX_SCHRAUT = 3;
short DRUNK_APPS = -5;      //Total Schraut consumed+DRUNK_APPS=# applications
short ANGRY_APPS = 2;       //Used if no Schraut is consumed
//------------------------------Documentation--------------------------------//
// Doctor() is the default constructor for the Doctor class; it initializes
//  the name, amount of Shraut consumed, and the doctor's money.
// Pre: None
// Post: Member vars initialized.

// puke() tests if the good doctor's schraut content exceeds 25 oz and resets it
//   to 0 oz after that content exceeds 25 oz.
// Pre: Amount of Schraut submitted as parameter must be 0 or greater.
// Post: m_schraut is set to 0 if the Schraut content exceeds 0; returns true
//  or false based on whether the doctor puked.

// Accessor for m_schruat returns schraut level.
// Pre: None.
// Post: Returns schraut level.

// consume_schraut() updates the doctor's Schraut content after he/she has
//  consumed Schraut.
// Pre: None.
// Post: Updates the doctor's Schraut content, returns true or false depending
//  on whether any Schraut was consumed.

class Doctor
{
  public:
    Doctor(const string name): m_name(name), m_schraut(0), m_money(0) {}
    bool puke();
    bool consume_schraut(float & amt_schraut);
    float getSchraut() const {return m_schraut;} 
    void modifyMoney(float m) {m_money += m; return; }
    friend ostream & operator <<(ostream & o, const Doctor & d);

  private:
    string m_name;
    short m_schraut;        //Amount of Schraut in stomach
    float m_money;          //Amount of monetary assets
};

#endif
