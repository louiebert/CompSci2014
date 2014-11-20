// Programmer: Brendan Curran              Date: 11/12/2014
// File: speedRecorder.cpp                 Class: CS 1580 Sec D
// Description: contains function definitions for the speed recorder class
// along with construction for the speed recorder class

#include "speedRecorder.h"


speedRecorder::speedRecorder(const int company_id)
{
  m_id = company_id;
  m_numberOfEntries = 0;
  m_averageSpeed=0;
  m_totalSpeed=0;
}


void speedRecorder::addSpeed(int speed)
{
  m_totalSpeed+=speed;
  m_numberOfEntries++;
  m_averageSpeed= static_cast<float>(m_totalSpeed)/m_numberOfEntries;
}

int speedRecorder::getId() const
{
  return m_id;
}

int speedRecorder::getTotalEntries() const
{
  return m_numberOfEntries;
}

float speedRecorder::getAverageSpeed() const
{
  
  return m_averageSpeed;
}