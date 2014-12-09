// Programmer: ALEX SHAW                   Date: 11-16-14
// File: x_rayer.h                         Class: CS1570 Section B
// Purpose: This file contains the defintion of the class that simulates an
// x-ray machine.

#ifndef X_RAYER_H
#define X_RAYER_H

#include "hospital_room.h"
#include "patient.h"
#include "hw09.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

// x_rayer() is a default constructor that initializes the member vars
//  holding the initial number of uses and the cost per use.
// Pre: None
// Post: Member vars of x_rayer object are initialized.

// charge_patient() charges a patient for using the x_rayer machine
// Pre: None
// Post: Member var of patient object that holds his/her money has the cost per
//  use of the x-ray machine subtracted from it.

// apply() halves a patient's condition 10% of the time.
// Pre: None
// Post: A patient's condition is halved 10% of the time.

// operator <<() overloads the extraction operator to display an x_rayer
//  object's member vars
// Pre: Insertion operator must not also be overloaded as a non-member function
// Post: All of the member vars of an x_rayer object are displayed to the
//  screen.

// increment_uses() increases the number of uses by the value passed.
// Pre: None.
// Post: Increases the number of uses by the value passed.

class x_rayer
{
  public:
    x_rayer(const int uses = INIT_USES, const float cost = CHARGE);
    void charge_patient(patient & p) const;
    void apply(patient & p) const;
    friend ostream & operator<<(ostream & o, x_rayer & x);
    float get_cost_per_use() const {return m_cost_per_use;};
    int get_num_uses() const {return m_num_uses;};
    void increment_uses(const int num = 1);

  private:
    float m_cost_per_use;
    int m_num_uses;
};

#endif
