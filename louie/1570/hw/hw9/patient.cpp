//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: patient.c                 Class: CS 1570, Section D
//Purpose: Body file for patient class

#include "patient.h"

using namespace std;

Patient::Patient()
{
  money = static_cast<float>(rand()%4001);
  condition = rand()%101;
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
  {
    kill();
  }

  return;
}

int Patient::get_condition() const
{
  return condition;
}

int Patient::num_in_file(const string& filename) const
{
  string val;
  int num_of_elements = 0;
  ifstream in;
  in.open(filename.c_str());

  getline(in, val, '"');
  while(!in.eof())
  {
    num_of_elements++;
    getline(in, val, '"');
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
    getline(in, val, '"');
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
