//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: patient.h                 Class: CS 1570, Section D
//Purpose: Header file for patient class

class Patient
{
  private:
    float money;
    bool is_alive;
    int condition;
    string name;
    int num_in_file(const string & filename) const;
    string pick_random_from_file(const int & max,const string & filename) const;
    void kill();
  public:
    Patient();
    void pay_out(const float & amount);
    bool modify_health(const int & change);
    int get_condition() const;
    friend ostream & operator << (ostream & out, const Patient & ptnt);
};
