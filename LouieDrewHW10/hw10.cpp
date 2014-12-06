//Programmer: LOUIE BERTONCIN, DREW BUELTER    Date: 11/30/2014
//File: hw10.cpp                               Class: CS 1570, Section D
//Purpose: Main file for hospital tour program

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "patient.h"
#include "x_rayer.h"
#include "hospital_room.h"
#include "doctor.h"
#include "liposuctionizer.h"
#include "lobotomizer.h"
#include "organ_donar.h"
#include "pharmacy.h"
#include "placaeboizer.h"

int main()
{
  const int NUM_PATIENTS=10;
  short deadPatients=0;
  srand(time(NULL));
  Patient patients[NUMPATIENTS]
  Doctor doctorEloe("Doctor Eloe");
  hospital_room<x_rayer> xrayRoom;
  hospital_room<lobotomizer> loboRoom;
  hospital_room<organ_donor> organRoom;
  hospital_room<placaeboizer> placaRoom;
  hospital_room<pharmacy> pharmRoom;
  hospital_room<liposuctionizer> lipoRoom;
  greeting();
  for(int i=0;i<NUMPATIENTS;i++)
  {
    cout<<"----------X-RAY ROOM----------"<<endl;
    xrayRoom.admit(patients[i],doctorEloe);
    cout<<patients[i]<<endl;
    if(doctorEloe.get_oz_schraut()==0)
      cout<<"The doctor puked!"<<endl<<endl;
    cout<<"----------LOBOTOMY ROOM----------"<<endl;
    loboRoom.admit(patients[i],doctorEloe);
    cout<<patients[i]<<endl;
    if(doctorEloe.get_oz_schraut()==0)
      cout<<"The doctor puked!"<<endl<<endl;
    cout<<"----------ORGAN DONOR ROOM----------"<<endl;
    organRoom.admit(patients[i],doctorEloe);
    if(doctorEloe.get_oz_schraut()==0)
      cout<<"The doctor puked!"<<endl<<endl;
    cout<<"----------PLACAEBOIZER ROOM----------"<<endl;
    placaRoom.admit(patients[i],doctorEloe);
    if(doctorEloe.get_oz_schraut()==0)
      cout<<"The doctor puked!"<<endl<<endl;
    cout<<"----------PHARMACY----------"<<endl;
    pharmRoom.admit(patients[i],doctorEloe);
    if(doctorEloe.get_oz_schraut()==0)
      cout<<"The doctor puked!"<<endl<<endl;
    cout<<"----------LIPOSUCTION ROOM----------"<<endl;
    lipoRoom.admit(patients[i],doctorEloe);
    if(doctorEloe.get_oz_schraut()==0)
      cout<<"The doctor puked!"<<endl<<endl;
    cout<<"The doctor has consumed "<<doctorEloe.get_oz_schraut()<<
    "ounces of Schraut! and has $"doctorEloe.getMoney()<<endl<<endl;
    if(patients[i].get_physical_health()==0)
      deadPatients++;
  }
  cout<<"During this simmulation "<<deadPatients<<" patients died, and"<<
  "the doctor made $"<<doctorEloe.getMoney()<<endl;
  farewell();
  return 0;
}
