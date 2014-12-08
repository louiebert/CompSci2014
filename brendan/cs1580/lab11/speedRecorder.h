// Programmer: Brendan Curran              Date: 11/12/2014
// File: speedRecorder.h                   Class: CS 1580 Sec D
// Description: contains class speedRecorder, which contains survey data
// about typing speeds for a certain company id

#ifndef SPEEDRECORDER_H
#define SPEEDRECORDER_H

class speedRecorder
{
  public:
    speedRecorder(const int company_id);
    void addSpeed(int speed);
    int getId() const;
    int getTotalEntries() const;
    float getAverageSpeed() const;
  private:
    int m_id;
    int m_numberOfEntries;
    float m_averageSpeed;
    int m_totalSpeed;
};


#endif