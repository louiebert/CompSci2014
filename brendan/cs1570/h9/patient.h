// Programmer: Brendan Curran             Date: 11/19/2014
// File: paitent.h      		              Class: CS 1570 Sec C
// Description: defines the patient class

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>

using namespace std;

const int PATIENT_MAX_MONEY = 4000;

class patient
{
  private:
    float m_money;
    bool m_isAlive;
    int m_condition; //0-100, 100 perfect, 0 = dead
    char m_name[30];
  public:
    //Description: default constructor
    //Pre: none
    //Post: Name is randomly assigned from list of names in file names.txt
    //condition is randomly assigned 0-100, isAlive determined from this value_comp
    //money is randomly assigned 0-4000
    patient();
    
    //Description: Charges the patient a certain amount of money
    //Pre: integer amount to charge
    //Post: patients money is reduced by the amount
    void payOut(const int amount);
    
    //Description: Changes patients condition by amount specified
    //Pre: integer amount to change health, positive or negative_sign
    //Post: amonut to change is added to patients existing condition value_comp
    void modifyHealth(const int amount);
    
    //get function for condition
    int getCondition() const;
    
    //Description: checks if patient is alive 
    //Pre: none
    //Post: if patients condition is 0 or lower, m_isAlive becomes false
    void kill();
    
    //Description: defines insertion operator for patient
    //outputs their name, condition, living status, and current amount of money
    friend ostream& operator << (ostream& stream, patient& pat);
    
};

#endif