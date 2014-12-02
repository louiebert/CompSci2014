//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: doctor.h                  Class: CS 1570, Section D
//Purpose: Header file for doctor class

#ifndef DOCTOR_H
#define DOCTOR_H

const int MAX_OZ_SCHRAUT = 25;

class Doctor
{
  private:
    string name;
    short oz_schraut;
    float money;
  public:
    Doctor(const string& theName);
    void puke();
    void drink_schraut(const short& amount);
    short get_oz_schraut() const;
    void increase_money(const float& amount);
};

#endif