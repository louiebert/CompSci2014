//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: hospital_room.h           Class: CS 1570, Section D
//Purpose: Header file for hospital_room class

class Hospital_room
{
  private:
    X_rayer the_machine;
    float oz_of_drink;
  public:
    Hospital_room();
    void admit(Patient & ptnt) const;
    friend ostream & operator << (ostream & out, const Hospital_room & room);
};
