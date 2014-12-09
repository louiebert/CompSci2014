// Programmer: Brendan Curran             Date: 10/7/2014
// File: h10.cpp        	              Class: CS 1570 Sec C
// Description: simulates Dr. Eloes work in his hospital, the doctor
// will take 10 patients through six rooms each with an operating machine
// inside. He will apply these machines to patients, which will interact
// with their physical and mental health, as well as their weight
// Dr. Eloe will also consume Schraut as he goes along in each room,
// and will apply more and more operations to his patients as he gets more drunk
// This will continue until the patient dies or has gone through all of the rooms.
// The patient's, Doctor's, and Room's, statuses will be output during and after 
// the completion of the treatment

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "h10.h"
#include "doctor.h"
#include "patient.h"
#include "hospitalRoom.h"
#include "xray.h"
#include "lobotomizer.h"
#include "organDonor.h"
#include "placeboizer.h"
#include "pharmacy.h"
#include "liposuctioner.h"
using namespace std;

int main()
{
  srand(time(NULL));
  doctor doc("Eloe");
  
  hospitalRoom<xRayer> roomXray;
  hospitalRoom<lobotomizer> roomLobotmizer;
  hospitalRoom<organDonor> roomOD;
  hospitalRoom<placeboizer> roomPlacebo;
  hospitalRoom<pharmacy> roomPharmacy;
  hospitalRoom<liposuctioner> roomLipo;
 
 patient patientArray[NUMPATIENTS];
  int roomCount = 0;
  int numDead = 0;
  
  for (int i = 0; i < NUMPATIENTS; i++)
  {
    cout << "Patient " << patientArray[i] << endl;
	//If the patient dies he will not enter the room
    if (patientArray[i].getAlive())
      roomXray.admit(patientArray[i], doc);    
    if (patientArray[i].getAlive())
      roomLobotmizer.admit(patientArray[i], doc);
    if (patientArray[i].getAlive())
      roomOD.admit(patientArray[i], doc);
    if (patientArray[i].getAlive())
      roomPlacebo.admit(patientArray[i], doc);
    if (patientArray[i].getAlive())
      roomPharmacy.admit(patientArray[i], doc);
    if (patientArray[i].getAlive())
      roomLipo.admit(patientArray[i], doc);
    cout << endl << endl;
  }
  
  for (int j = 0; j < NUMPATIENTS; j++)
  {
    cout << patientArray[j] << endl << endl;
    if (!patientArray[j].getAlive())
      numDead ++;
  }
  cout << endl << numDead << " patients have died" << endl << endl;
  cout << doc << endl << endl;
  cout << "Room 1: " << roomXray << endl;
  cout << "Room 2: " << roomLobotmizer << endl;
  cout << "Room 3: " << roomOD << endl;
  cout << "Room 4: " << roomPlacebo << endl;
  cout << "Room 5: " << roomPharmacy << endl;
  cout << "Room 5: " << roomLipo << endl;
  return 0;
}