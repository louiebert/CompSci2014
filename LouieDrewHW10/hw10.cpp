//Programmer: LOUIE BERTONCIN, DREW BUELTER    Date: 11/30/2014
//File: hw10.cpp                               Class: CS 1570, Section D
//Purpose: Main file for hospital tour program

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hw10.h"
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
  Hospital_Room<X_Rayer> xrayRoom;
  Hospital_Room<Lobotomizer> loboRoom;
  Hospital_Room<Organ_Donor> organRoom;
  Hospital_Room<Placaeboizer> placaRoom;
  Hospital_Room<Pharmacy> pharmRoom;
  Hospital_Room<Liposuctionizer> lipoRoom;
  greeting();
  for(int i=0; i < NUM_PATIENTS ; i++)
  {
    cout << "Patient #"<<i+1<<": " << endl;
    cout << "\t----------X-RAY ROOM----------" << endl;
    xrayRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "\t----------LOBOTOMY ROOM----------" << endl;
    loboRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "\t----------ORGAN DONOR ROOM----------" << endl;
    organRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "\t----------PLACAEBOIZER ROOM----------" << endl;
    placaRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "\t----------PHARMACY----------" << endl;
    pharmRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << "\t----------LIPOSUCTION ROOM----------" << endl;
    lipoRoom.admit(patients[i], doctorEloe);
    cout << patients[i] << endl;
    if(doctorEloe.get_oz_schraut() == 0)
      cout << "The doctor puked!" << endl;

    cout << ""The doctor has " << doctorEloe.get_oz_schraut() <<
    " ounces of Schraut! in his stomach and has $" << doctorEloe.getMoney()
    << "." <<"""" << endl;
    if(patients[i].get_physical_health() == 0)
      deadPatients++;
  }

  cout << "\t\t###########################"" << endl;

  cout << "During this simulation " << deadPatients << " patients died, and" <<
    " the doctor made $" << doctorEloe.getMoney() << "." << endl;

  cout << "Final room report:" << endl << xrayRoom << endl << loboRoom << endl
    << organRoom << endl << placaRoom << endl << pharmRoom << endl << lipoRoom
    << endl << endl;

  farewell();

  return 0;
}
