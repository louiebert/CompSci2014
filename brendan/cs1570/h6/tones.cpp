// Programmer: Brendan Curran              Date: 10/13/2014
// File: tones.cpp                         Class: CS 1570 Sec C
// Description: this is the implementation file for tones.h, and thus
// contains the function definitions

#include <iostream>
#include "tones.h"
#include <ctime>
#include <cstdlib>

void tone1(patient & data)
{
  //95% chance of success (roach hears tone)
  //if failure protein value will come up negative, meaning inconclusive
  int failChance = rand()%100;
  
  //test fails
  if (failChance < 5)
  {
    data.m_p1 = -1;
    data.m_p2 = -1;
    data.m_p3 = -1;
  }
  
  //test successful
  else
  {
	//assigns [0,100]
    data.m_p1 = rand()%101;
   
   //if less than 10 protein is undetectable, will be assigned 0
    if (data.m_p1 < 10)
      data.m_p1 = 0;
    
	//not perfectly random, will generate [0-99] + [0.0,1.0]
	//to achieve range of [0,100]
	data.m_p2 = 1.0*(rand()%100)+(rand()%11*.1);
	
    data.m_p3 = rand()%11;
  }
}

void tone2(patient & data)
{
  int temp;
  //temporary value, might be assigned if conditions are met
  
  int failChance = rand()%100;
  
  if (failChance < 5)
  {
    data.m_p4 = -1;
  }
  
  else
  {
    temp = 1.0*(rand()%100)+(rand()%11*.1); //will be assigned to p2 if lesser
    if (temp < data.m_p2 || data.m_p2 < 0)
      data.m_p2 = temp;
	
	//assigns [10,50]
    data.m_p4 = 10+rand()%41;
  }
}

void tone3(patient & data)
{
  int temp;
  int failChance = rand()%100;
  
  if (failChance < 5)
  {
    data.m_p5 = -1;
  }
  
  else
  {
    
    temp = rand()%101;
    if (temp > data.m_p1 && temp >9) //reassign if greater
      data.m_p1 = temp;
  
    temp = 10+rand()%41;
    if (temp > data.m_p4) //reassign if greater
      data.m_p4 = temp;
    
    data.m_p5 = rand()%11;  
  }
}

void greet()
{
  cout << "Hello doctor, welcome to your JHS testing session"" << endl;
}

string getName()
{
  string name;
  cout << "What is your patient's name (nospaces)?: ";
  cin >> name;
  cout << endl;
  return name;
}

bool diagnose(patient data)
{
  //patient has disease if p2 is less than or equal to this constant
  const float p2Limit = 14.6;
  
  //with p5 >= p5limit p1+p2+p3 must be less than sumLimit for disease
  const int p5Limit = 2;
  const int sumLimit = 75;
  
  //p4l is p4 lower limit, p4h is higher limit
  //p3L is p3 limit
  //if p5 is below its limit, p4 must be within p4l and p4h, and
  //p3 must be above its limit for patient to have disease
  const int p4l = 20;
  const int p4h = 40;
  const int p3l = 6;
  
  //if p1 is not present, patient does not have disease
  if(data.m_p1 == 0)
    return false;

  else
  {
    if (data.m_p5< p5Limit && data.m_p4>p4l&& data.m_p4<p4h && data.m_p3>p3l)
      return true; 
    else if(data.m_p5>=p5Limit && (data.m_p1+data.m_p2+data.m_p3)<sumLimit)
      return true;
    else if(data.m_p2 <= p2Limit)
      return true;
    else 
      return false;
  }
}

void showResult(patient data)
{
  //an inconclusive tone will make a protein value negative, if any are 
  //negative the test is inconclusive due to insufficient data
  if(data.m_p1<0 || data.m_p2<0 || data.m_p3<0 || data.m_p4<0 || data.m_p5<0)
    cout << "insufficient data " << endl;
	
	
  else if(data.m_diagnosis)
    cout << data.m_name << " tests positive for JHS" << endl;
  else
    cout << data.m_name << " tests negative for JHS" << endl;
  
  //These output all protein values if they are valid, if not valid
  //it will say the protein is not represented
  cout << "p1 = ";
  if (data.m_p1 <0)
    cout << "not represented" << endl;
  else 
    cout << data.m_p1 << endl;
   
  cout << "p2 = "; 
  if(data.m_p2 < 0)
    cout << "not represented" << endl;
  else
    cout << data.m_p2 << endl;
    
  cout << "p3 = ";
  if(data.m_p3 < 0)
    cout<< "not represented" << endl;
  else
    cout << data.m_p3 << endl;
    
  cout << "p4 = ";
  if (data.m_p4 < 0)
    cout << "not represented" << endl;
  else
    cout << data.m_p4 << endl;
    
  cout << "p5 = ";
  if (data.m_p5 < 0)
    cout << "not represented" << endl;
  else
    cout << data.m_p5 << endl; 
}