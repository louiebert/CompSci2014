//Programmer: LOUIE BERTONCIN     Date: 11/17/2014
//File: x_rayer.h                 Class: CS 1570, Section D
//Purpose: Header file for x_rayer class

class X_rayer
{
  private:
    float cost_per_use;
    short num_uses;
  public:
    X_rayer();
    void charge_patient(Patient & ptnt) const;
    void apply(Patient & ptnt) const;
    friend ostream & operator << (ostream & out, const X_rayer & x_ray);
};
