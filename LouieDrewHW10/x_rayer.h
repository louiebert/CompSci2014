//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/17/2014
//File: x_rayer.h                               Class: CS 1570, Section D
//Purpose: Header file for x_rayer class

#ifndef X_RAYER_H
#define X_RAYER_H
#include "patient.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Description: The x_rayer constructor makes a default x_rayer with a cost of
//             $550 and 0 uses.
//Precondition: None
//Postcondition: A new x_rayer object is created with cost of 550 and 0
//               uses.

//Description: The charge_patient function charges the passed patient for
//using the x-ray machine the value of cost.
//Precondtion: None
//Postcondition: The passed patient is charged.

//Description: The apply function increments num_uses by one and 10% of the
//             time halves the patients condition.
//Precondition: None
//Postcondition: num_uses is incremented and the patients health may be
//               diminished.

//Description: The get_cost_per_use function returns the cost to use the
//             x_rayer.
//Precondition: None
//Postcondition: The cost of the machine is returned.

//Description: This function overrides the insertion operator to output
//             the cost an number of uses.
//Preconditon: None
//Postcondition: The insertion operator is overridden.

const float XR_COST_PER_USE = 550;

class X_Rayer
{
  private:
    float m_cost_per_use;
    short m_num_uses;
  public:
    X_Rayer():m_num_uses(0),m_cost_per_use(XR_COST_PER_USE){}
    void charge_patient(Patient & patient)const;
    void apply(Patient & patient);
    float get_cost_per_use(){return m_cost_per_use;}
    friend ostream& operator << (ostream& out, const X_Rayer& x);
};
#endif
