//Programmer: LOUIE BERTONCIN, DREW BUELTER    Date: 11/30/2014
//File: hw10.cpp                               Class: CS 1570, Section D
//Purpose: Main file for hospital tour program

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "patient.h"
#include "x_rayer.h"
#include "hospital_room.h"

int main()
{
  srand(time(NULL));
  cout<<"------------Hospital Simulation------------"<<endl<<endl;
  patient pat1;
  patient pat2;
  patient pat3;
  hospital_room room;
  cout<<endl<<"Before being admited, "<<pat1<<endl<<endl;
  cout<<pat2<<endl<<endl;
  cout<<pat3<<endl<<endl;
  cout<<"Room Before Use: "<<room<<endl<<endl;
  room.admit(pat1);
  room.admit(pat1);
  room.admit(pat1);
  room.admit(pat1);
  room.admit(pat1);
  cout<<"After being admited, "<<pat1<<endl<<endl;
  cout<<pat2<<endl<<endl;
  cout<<pat3<<endl<<endl;
  cout<<"Room After Use: "<<room<<endl<<endl;
  cout<<"------------Conclusion of Simulation-------------"<<endl;
  return 0;
}
