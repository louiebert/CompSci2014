//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/17/2014
//File: x_rayer.h                               Class: CS 1570, Section D
//Purpose: Header file for x_rayer class

#ifndef X_RAYER_H
#define X_RAYER_H
#include "patient.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const float INIT_COST=550;
const short INIT_NUM_USES=0;

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

//Description: This function overrides the insertion operator to output
//             the cost an number of uses.
//Preconditon: None
//Postcondition: The insertion operator is overridden.
class x_rayer
{
  public:
    x_rayer(const short n=INIT_NUM_USES,const float c=INIT_COST){m_num_uses=n;
    m_cost=c;}
    void charge_patient(patient & p)const;
    void apply(patient & p);
    friend ostream& operator <<(ostream& o,const x_rayer& x);
  private:
    float m_cost;
    short m_num_uses;
};
#endif
