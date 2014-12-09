// Programmer: Brendan Curran             Date: 10/7/2014
// File: doctor.h        		              Class: CS 1570 Sec C
// Description: contains the doctor class

#ifndef DOCTOR_H
#define DOCTOR_H

using namespace std;
#include <string>
#include <iostream>

//Amount of schraut at which the doctor will puke
const int SCHRAUTTOLERANCE = 25;
class doctor
{
  private:
    string m_name;
    short m_schrautConsumed;
    float m_money;
  public:
    //Description: Standard constructor
	//Pre: single paramater string for the name of the doctor
	doctor(string name): m_name(name), m_money(0), m_schrautConsumed(0){}
	
	//Description: empties the Doctors stomach when too drunk
	//Pre: none
	//Post: if consumed schraut exceeds 25 ozs m_schrautConsumed will be set 
	//to 0
    void puke () {m_schrautConsumed = 0; cout << "Doctor " << m_name << " has puked" << endl;}
    
	//Description: The doctor will receive half of the amount charged by the 
	//machine
	//Pre: integer amount charged by the machine
	//Post: half of the amount charged will be added to m_money
	void addMoney (int charged) {m_money+=(charged/2);}
	
	//Description: consumes a given amount of schraut
	//Pre: integer amount of schraut to consumeSchraut
	//Post: m_schrautConsumed is increased by amount given
    void consumeSchraut (int amount);
	
	//accessor function, returns schraut currently in stomach of doctor
    short getSchrautConsumed() {return m_schrautConsumed;} 
    
	//Description: overloaded insertion operator to output the doctors status
	//Pre: doctor passed by reference
	//Post: outputs how much money the doctor has and how much schraut he has
	//consumed
	friend ostream& operator << (ostream& stream, doctor& doc);
};

#endif