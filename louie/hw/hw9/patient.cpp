//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: patient.c                 Class: CS 1570, Section D
//Purpose: Body file for patient class

#include "patient.h"

using namespace std;

Patient()
{
  money = static_cast<float>(rand()%4001);
  condition = rand()%101;
  if(condition == 0)
    kill();
  name = pick_random_from_file(num_in_file(FILE_NAME), FILE_NAME);
}

void pay_out(const float & amount)
{
  if(money > amount)
    money -= amount;
  else
    money = 0;

  return;
}

bool modify_health(const int & change)
{
  bool isAlive = true;
  if(condition > -change)
    condition += change;
  else
  {
    kill();
    isAlive = false;
  }

  return isAlive;
}

int get_condition() const
{
  return condition;
}

int num_in_file(const string & filename) const
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

string pick_random_from_file(const int & max, const string & filename) const
{
  int loop_count = rand()%(max+1);
  string val;
  ifstream in;
  in.open(filename.c_str());

  for(i = 0; i < loop_count; i++)
  {
    getline(in, val, '\n');
  }
  in.close();

  return val;
}

void kill()
{
  condition = 0;
  is_alive = false;

  return;
}
