//Programmer: LOUIE BERTONCIN     Date: 11/30/2014
//File: patient.cpp               Class: CS 1570, Section D
//Purpose: Body file for patient class

#include "patient.h"

using namespace std;

Patient::Patient()
{
  money = static_cast<float>(rand()%(MAX_MONEY+1));
  condition = rand()%(MAX_HEALTH+1);
  mental_health = rand()%(MAX_MENTAL_HEALTH+1);
  weight = rand()%(MAX_WEIGHT+1) + MIN_WEIGHT;
  is_alive = true;
  if(condition == 0)
  {
    kill();
  }
  name = pick_random_from_file(num_in_file(NAMES_FILE), NAMES_FILE);
}

void Patient::pay_out(const float& amount)
{
  if(money > amount)
    money -= amount;
  else
    money = 0;

  return;
}

void Patient::modify_health(const int& change)
{
  if(condition > -change)
    condition += change;
  else
    kill();

  return;
}

void Patient::modify_mental_health(const int& change)
{
  if(mental_health > -change)
    mental_health += change;
  else
    mental_health = 0;

  return;
}

void modify_weight(const int& change)
{
  if(weight > -change)
    weight += change;
  else
    weight = 0;

  return;
}

int Patient::get_condition() const
{
  return condition;
}

void modify_name(const string& newName)
{
  name = newName;

  return;
}

int Patient::num_in_file(const string& filename) const
{
  string val;
  int num_of_elements = 0;
  ifstream in;
  in.open(filename.c_str());

  getline(in, val, '\n');
  while(!in.eof())
  {
    num_of_elements++;
    getline(in, val, '\n');
  }
  in.close();

  return num_of_elements;
}

string Patient::pick_random_from_file(const int& max, const string& filename)
const
{
  int loop_count = rand()%(max+1);
  string val;
  ifstream in;
  in.open(filename.c_str());

  for(int i = 0; i < loop_count; i++)
  {
    getline(in, val, '\n');
  }
  in.close();

  return val;
}

void Patient::kill()
{
  condition = 0;
  is_alive = false;

  return;
}

ostream& operator << (ostream& out, const Patient& ptnt)
{
  out << ptnt.name << "(money: " << ptnt.money << ", " <<
    (ptnt.is_alive ? "is living, " : "is dead, ") << "condition: " <<
    ptnt.condition << ")";
  return out;
}
