// Programmer: ALEX SHAW                   Date: 11-16-14
// File: patient.h                         Class: CS1570 Section B
// Purpose: This file contains the defintion of the class that simulates a
// patient

#ifndef PATIENT_H
#define PATIENT_H

#include "hw09.h"
#include "hospital_room.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

// patient() is a default constructor that initializes the member vars
//  holding the patient's money, condition, and his/her name.
// Pre: None
// Post: Member vars of patient object are initialized.

// pay_out() decreases the patient's money by the charge amount.
// Pre: None.
// Post: Decreases the patient's money by the charge amount.

// modify_health() decreases the patient's health by the amount passed in and
//  calls kill().
// Pre: None.
// Post: Decreases the patient's health by the amount passed in.

// get_condition() returns

// If patient is dead, kill() sets var (holding whether patient is alive) to 0
// Pre: None.
// Post: If patient is dead, kill() sets var (holding whether patient is alive)
//  to 0

class patient
{
  public:
    patient(const float money = random_num(MIN_MONEY, MAX_MONEY),
            const int condition = random_num());
    void pay_out(const float amt = CHARGE);
    void modify_health(const int factor = APPLY_CHANGE);
    int get_condition() const {return m_condition;};
    friend ostream & operator<<(ostream & o, patient & p);
  private:
    void kill();
    float m_money;
    bool m_is_alive;
    int m_condition;
    string m_name;
};

#endif
