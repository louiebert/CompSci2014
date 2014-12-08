// Programmer: Brendan Curran             Date: 10/7/2014
// File: doctor.h        		              Class: CS 1570 Sec C
// Description: 

#ifndef DOCTOR_H
#define DOCTOR_H

using namespace std;
#include <string>

class doctor
{
  private:
    string m_name;
    short m_schrautConsumed;
    float m_money;
  public:
    doctor(string name): m_name(name), m_money(0), m_schrautConsumed(0){}
    void puke () {m_schrautConsumed = 0;}
    void addMoney (int charged) {m_money+=(charged/2);}
    void consumeSchraut (int amount);
    short getSchrautConsumed() {return m_schrautConsumed;} 
};

#endif