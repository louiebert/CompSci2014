//Programmer: LOUIE BERTONCIN     Date: 11/11/2014
//File: Speed_recorder.h          Class: CS 1580, Section D
//Purpose: Header for Speed_recorder class to represent a company's Speedometer.

class Speed_recorder
{
  public:
    Speed_recorder(const int company_id);
    void addSpeed(int speed);
    int getId() const;
    int getTotalEntries() const;
    float getAverageSpeed() const;
  private:
    int id;
    int numberOfEntries;
    float averageSpeed;
};
