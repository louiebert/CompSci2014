//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: patient.h                               Class: CS 1570, Section D
//Purpose: Header file for patient class

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <cstdlib>
using namespace std;
const short MAX_MONEY=4000;
const short MAX_CONDITION=100;
const short MIN_CONDITION=0;
const short MIN_MONEY=0;
const char name_file[11]="names.dat";

//Description: The patient makes a patient with a randomly chosen name,
//             money on hand, and condition.
//Precondition: None
//Postcondition: A new patient object is created.

//Description: The pay_out function subtracts from the amount of money
//             a patient has by the passed amount.
//Precondition: None
//Postcondition: The passed amount is subtracted from the patients funds.

//Description: The modify_health function adds the passed amount to the
//             patients condition.
//Precondition: None
//Postcondition: The passed value is added to the patients condition.

//Description: The getCondition function returns the patients condition.
//Precondition: None
//Postcondition: The patients condtion is returned.

//Description: This funciton overrides the insertion operator for patient
//             and makes it output their name, condition, and livelyhood in
//             the form of a sentence.
//Precondition: None
//Postcondtion: The insertion operator is defined for patient objects.

//Description: The kill function checks to see if the patients condition is
//             zero and if it is it updates their status to dead.
//Precondition: None
//Postcondition: The patients status is updated appropriately.

class patient
{  public:
    patient();
    void pay_out(const float pay_amount);
    void modify_health(const int condition_dif);
    int getCondition() const{return m_condition;}
    friend ostream& operator <<(ostream& o,const patient& p);
  private:
    string m_name;
    float m_money;
    bool m_is_alive;
    int m_condition;
    void kill();
};
#endif
