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
    int m_mentalCondition; //0-100 100 is best, 0 is vegetable
    int m_weight; //in pounds
    char m_name[50];
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
    
    //Description: changes the patients mental health
    //Pre: integer amount to change health, positive or negative_sign
    //Post: amount is added to the patients exisiting mental health condition
    void modifyMHealth(const int amount);
    
    //Description: changes the patients weight
    //Pre: integer amount to change weight, + or -
    //Post: amount is added to the patients weight
    void modifyWeight (const int amount);
    
    //get function for condition
    int getHealth() {return m_condition;}
    
    //Accessor function for mental health
    int getMHealth() {return m_mentalCondition;}
    
    //Accessor function for patients alive status, true is alive
    bool getAlive() {return m_isAlive;}
    
    //Accessor function for the patient's money
    float getMoney() {return m_money;}
    
    //Accessor function for the patient's name
    string getName() {return m_name;}
    
    //Accessor function for the patients weight
    int getWeight() {return m_weight;}
    
    //Description: Patient forget's their name, but to signify a new name
    //is concatenated onto their old one with a hyphen in between
    void forgetName();
        
    //Description: checks if patient is alive 
    //Pre: none
    //Post: if patients condition is 0 or lower, m_isAlive becomes false
    void kill();
    
    //Description: defines insertion operator for patient
    //outputs their name, condition, living status, and current amount of money
    friend ostream& operator << (ostream& stream, patient& pat);
    
};

#endif