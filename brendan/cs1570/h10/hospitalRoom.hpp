// Programmer: Brendan Curran             Date: 12/7/2014/2014
// File: hospitalRoom.hpp		              Class: CS 1570 Sec C
// Description: 

#include <iostream>
#include <cstdlib>

using namespace std;


template <class T_machine>
void hospitalRoom<T_machine>::admit(patient &pat, doctor& doc)
{
  int consume = rand()%3+1;
  bool anger = false;
  int initial = doc.getSchrautConsumed();
  int temp;
  
  if (m_ouncesOfSchraut == 0)
  {
    anger = true;
  }
  
  else if (consume <= m_ouncesOfSchraut)
  {
    doc.consumeSchraut(consume);
    m_ouncesOfSchraut-=consume;
  }
  
  else if (consume > m_ouncesOfSchraut && m_ouncesOfSchraut != 0)
  {
    doc.consumeSchraut(m_ouncesOfSchraut);
    m_ouncesOfSchraut =0;
  }  
  
  if (doc.getSchrautConsumed() > initial)
  {
    if (doc.getSchrautConsumed() >5)
    {
      for (int i = 0; i < (doc.getSchrautConsumed()-5); i++)
        m_machine.apply(pat);
    }
    else
      m_machine.apply(pat);
  }
  
  else if (anger)
  {
    temp =2*(doc.getSchrautConsumed()-5);
    if (temp!=0)
    {
      for (int i = 0; i<temp; i++)
        m_machine.apply(pat);
    }
    else 
      m_machine.apply(pat);
  }
  
  else
    m_machine.apply(pat);
  
  m_machine.chargePatient(pat);
  
}
template <class T_friend>
ostream& operator << (ostream& stream, hospitalRoom<T_friend>& hr)
{
  stream << "Ozs of Schraut = " << hr.m_ouncesOfSchraut << endl;
  stream << hr.m_machine;
  return stream;
}