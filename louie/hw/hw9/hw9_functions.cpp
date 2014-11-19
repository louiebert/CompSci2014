//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hw9_functions.cpp         Class: CS 1570, Section D
//Purpose: Functions file for hospital tour program

#import "hw9.h"

using namespace std;

void greeting()
{
  cout << "Welcome to the hospital tour!\n\n" << endl;

  return;
}

ostream & operator << (ostream & out, const X_rayer & x_ray)
{
  out << "X-Rayer(# of uses: " << x_ray.num_uses << ", cost per use: " <<
    x_ray.cost_per_use << ")";
  return out;
}

ostream & operator << (ostream & out, const Patient & ptnt)
{
  out << ptnt.name << "(money: " << ptnt.money << ", " <<
    (ptnt.is_alive ? "is living, " : "is dead, ") << "condition: " <<
    ptnt.condition << ")";
  return out;
}

ostream & operator << (ostream & out, const Hospital_room & room)
{
  out << "Hospital Room: (" << room.the_machine << ",\n\toz of Schraut!: " <<
    room.oz_of_drink << ")";
  return out;
}