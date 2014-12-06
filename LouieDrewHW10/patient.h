//Programmer: LOUIE BERTONCIN, DREW BUELTER     Date: 11/30/2014
//File: patient.h                               Class: CS 1570, Section D
//Purpose: Header file for patient class

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <cstdlib>

//Description: The patient makes a patient with a randomly chosen name,
//             money on hand, weight, and physical and mental condition.
//Precondition: None
//Postcondition: A new patient object is created.

//Description: The pay_out function subtracts from the amount of money
//             a patient has by the passed amount.
//Precondition: None
//Postcondition: The passed amount is subtracted from the patients funds.

//Description: The modify_physical_health function adds the passed amount
//to the patients condition.
//Precondition: None
//Postcondition: The passed value is added to the patients condition.

//Description: The get_phsyical_health function returns the patients
//condition.
//Precondition: None
//Postcondition: The patients condtion is returned.

//Description: The modify_mental_health function adds to the patients mental
//             health by the passed value.
//Precondition: None
//Postcondition: The patients mental health is changed by the passed value.

//Description: The get_mental_health function returns the patients mental
//             health value
//Preconditon: None
//Postcondition: The patients mental health value is returned.

//Description: The add_to_name function adds the passed string to the end
//             of the patients name giving them a new name.
//Precondition: None
//Postcondition: The passed string is put on the end of the patients name.

//Description: The modify_weight function adds the passed value to the
//             patients weight.
//Precondition: None
//Postcondition: The passed value is added to the patients weight.

//Description: The get_weight function returns the weight of the patient
//Precondition: None
//Postcondition: The weight of the patient is returned.

//Description: The getMoney function returns the amount of money the
//             patient has.
//Precondition: None
//Postcondition: The amount of money on the patient is returned.

//Description: This funciton overrides the insertion operator for patient
//             and makes it output their name, condition, and livelyhood in
//             the form of a sentence.
//Precondition: None
//Postcondtion: The insertion operator is defined for patient objects.

//Description: The kill function checks to see if the patients condition is
//             zero and if it is it updates their status to dead.
//Precondition: None
//Postcondition: The patients status is updated appropriately.

using namespace std;
const short MAX_MONEY=4000;
const short MAX_PCONDITION=100;
const short MIN_PCONDITION=0;
const short MIN_MCONDITION=0;
const short MIN_MONEY=0;
const short MAX_WEIGHT=220;
const short MIN_WEIGHT=120;
const char name_file[11]="names.dat";

class Patient
{
  public:
    static const int MAX_MCONDITION = 100;
    Patient();
    void pay_out(const float pay_amount);
    void modify_physical_health(const int condition_dif);
    int get_physical_health() const{return m_physCondition;}
    void modify_mental_health(const int amount);
    int get_mental_health() const{return m_mentCondition;}
    void add_to_name(const string name);
    void modify_weight(const int amount);
    int get_weight()const {return m_weight;}
    float getMoney() const{return m_money;}
    friend ostream& operator <<(ostream& o,const Patient& p);

  private:
    string m_name;
    float m_money;
    bool m_is_alive;
    int m_physCondition;
    int m_mentCondition;
    short m_weight;
    void kill();
};

#endif
