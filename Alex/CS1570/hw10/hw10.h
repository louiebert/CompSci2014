//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: hw10.h                    Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains global constants and the function prototypes for the
// non-member,  non-friend functions in the program that simulates a patient
// and a doctor visiting hospital rooms.

#ifndef HW10_H
#define HW10_H

#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "doctor.h"
//#include "patient.h"
#include "hospital.h"

using namespace std;

//-------------------------------Global Constants----------------------------//
const short MAX_TESTS = 5;                //Number of tests to connect to data file
const short NUM_PATIENTS = 10;            //Size of patient array
const short NUM_ROOMS = 6;                //Size of hospital_room array
//------------------------------Function Prototypes--------------------------//

// connect_to_file() opens and tests a connection to a data file. If no
//  connection is made, the program exits.
// Pre: Data file with same name as c-string parameter exists in same directory
//  as this program.
// Post: opens and tests a connection to a data file. If no
//  connection is made, the program exits. Returns true or false based on
//  whether connection was made.
template <typename T>
bool connect_to_file(T & the_stream, const char fileName[])
{
  bool connected = false;
  short numTries = 0;
  the_stream.open(fileName);
  while(numTries <= MAX_TESTS && !the_stream)
  {
    the_stream.open(fileName);
    numTries ++;
  }
  connected = the_stream;
  if(!the_stream)
  {
    cout << "ERROR: Cannot connect to data file. Exiting program." << endl;
    exit(1);
  }
  return connected;
}

// rand_num() generates a random number within (and inclusive of) a set range.
// Pre: Rand() must be seeded.
// Post: Returns a random number within (and inclusive of) a set range.
short rand_num(const short min, const short max);

// rand_name() reads in a random name from a data file.
// Pre: Must be connected to file.
// Post: Returns a random name from the file.
string rand_name(const short num_names, ifstream& fin);

// num_el() counts the number of elements in a data file.
// Pre: Must be connected to file.
// Post: Returns number of elements in a data file.
short count_el(ifstream& fin);

// disp_status() displays the statuses of the patient, hospital_room, and
//  doctor objects.
// Pre: The constants for the sizes of the patient and hospital_room arrays
//  must be the actual size of those arrays.
// Post: Displays the statuses of the patient, hospital_room, and
//  doctor objects.
/*template <class T>
void disp_status(const Doctor & d, const Patient patients[],
                 const Hospital<T> rooms[]);
*/

#endif
