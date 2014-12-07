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
#include "organ_donor.h"
#include "pharmacy.h"
#include "placaeboizer.h"
const int NUM_PATIENTS=10;

int main()
{
  short deadPatients=0;
  srand(time(NULL));
  Patient patients[NUM_PATIENTS];
  Doctor doctorEloe("Doctor Eloe");
  hospital_room<X_Rayer> xrayRoom;
  hospital_room<Lobotomizer> loboRoom;
  hospital_room<Organ_Donor> organRoom;
  hospital_room<Placaeboizer> placaRoom;
  hospital_room<Pharmacy> pharmRoom;
  hospital_room<Liposuctionizer> lipoRoom;
  greeting();
  for(int i=0; i < NUM_PATIENTS ; i++)
  {
    cout<<"Patient #"<<i+1<<": "<<endl;
    cout << "----------X-RAY ROOM----------" << endl;
    xrayRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "----------LOBOTOMY ROOM----------" << endl;
    loboRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "----------ORGAN DONOR ROOM----------" << endl;
    organRoom.admit(patients[i], doctorEloe);
    cout<<patients[i]<<endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "----------PLACAEBOIZER ROOM----------" << endl;
    placaRoom.admit(patients[i], doctorEloe);
    cout<<patients[i]<<endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "----------PHARMACY----------" << endl;
    pharmRoom.admit(patients[i], doctorEloe);
    cout<<patients[i]<<endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "----------LIPOSUCTION ROOM----------" << endl;
    lipoRoom.admit(patients[i], doctorEloe);
    cout<<patients[i]<<endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "\nThe doctor has " << doctorEloe.get_oz_schraut() <<
    " ounces of Schraut! in his stomach and has $" << doctorEloe.getMoney()
    << "." <<"\n\n" <<endl;
    if(patients[i].get_physical_health() == 0)
      deadPatients++;
  }
  cout << "During this simmulation " << deadPatients << " patients died, and" <<
    " the doctor made $" << doctorEloe.getMoney() << "." << endl;
  farewell();
  return 0;
}
