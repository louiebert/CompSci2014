//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: x_rayer.h                 Class: CS 1570, Section D
//Purpose: Header file for x_rayer class

#ifndef X_RAYER_H
#define X_RAYER_H

#include "patient.h"

const int DEF_NUM_USES = 0;
const float DEF_COST_OF_USE = 550;
const int CHANCE_OF_MUTILATION = 10;
const int FACTOR_OF_MUTILATION = 2;

// charge_patient() subtracts the X_rayer's cost per use from the ptnt's money.
// Pre: None.
// Post: Decrements ptnt's money by X_rayer's cost per use.

// apply() takes a fraction of the ptnt's health away a percentage of the time
//   that the function is called.
// Pre: FACTOR_OF_MUTILATION constant cannot be zero.
// Post: Sometimes decreases ptnt's health.

// The << operator for the X_rayer class prints an X_rayer object.
// Pre: The ostream must be opened already and x_ray must have all its
//   properties existing.
// Post: Prints the X_rayer object through the given ostream object.

class X_rayer
{
  private:
    float cost_per_use;
    short num_uses;
  public:
    X_rayer();
    void charge_patient(Patient& ptnt) const;
    void apply(Patient& ptnt) const;
    friend ostream& operator << (ostream& out, const X_rayer& x_ray);
};

#endif