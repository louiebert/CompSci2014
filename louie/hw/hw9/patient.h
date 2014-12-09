//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: patient.h                 Class: CS 1570, Section D
//Purpose: Header file for patient class

#ifndef PATIENT_H
#define PATIENT_H

#include <fstream>
#include <cstdlib>

using namespace std;

const string NAMES_FILE = "names.dat";

// num_in_file() returns the number of items in the given file name.
// Pre: filename must be a working filename for a file in the directory of the
//   project.
// Post: Returns the number of elements in the given file.

// pick_random_from_file() returns a random item between 0 and max in the file
//   with the name of filename
// Pre: max cannot be greater than the number of elements in filename's file and
//   filename must be a working filename for a file in the directory of the
//   project.
// Post: Returns a random element from the given file.

// kill() sets the Patient's health to zero and sets is_alive to false.
// Pre: None.
// Post: Effectively kills the Patient object.

// payout() decreases the Patient object's money variable by amount.
// Pre: None.
// Post: Decreases Patient object's money by amount.

// modify_health() changes the Patient object's condition variable by change and
//   calls kill() if the object's health is <= 0.
// Pre: None.
// Post: Decreases patient's condition and kills patient if necessary.

// get_condition() returns the condition of the Patient object.
// Pre: None.
// Post: Returns condition of Patient object.

// The << operator for the Patient class prints an Patient object.
// Pre: The ostream must be opened already and ptnt must have all its
//   properties existing.
// Post: Prints the Patient object through the given ostream object.

class Patient
{
  private:
    float money;
    bool is_alive;
    int condition;
    string name;
    int num_in_file(const string& filename) const;
    string pick_random_from_file(const int& max,const string& filename) const;
    void kill();
  public:
    Patient();
    void pay_out(const float& amount);
    void modify_health(const int& change);
    int get_condition() const;
    friend ostream& operator << (ostream& out, const Patient& ptnt);
};

#endif
