// Programmer: Brendan Curran             Date: 12/7/2014/2014
// File: hospitalRoom.hpp		              Class: CS 1570 Sec C
// Description: function definitions for the templated hospital class

#include <iostream>
#include <cstdlib>

using namespace std;


template <class T_machine>
void hospitalRoom<T_machine>::admit(patient &pat, doctor& doc)
{
  int initUses = m_machine.getNumUses();
  if (pat.getMoney() > m_machine.getCost())
  {
    int consume = rand()%3+1;
    bool anger = false;
    int initial = doc.getSchrautConsumed();
    int temp;
  
    //Doctor is angry because he is out of Schraut
    if (m_ouncesOfSchraut == 0)
    {
      anger = true;
    }
    
	//If there is less Schraut than he wanted to consume he will
	//finish off the bottle
    else if (consume <= m_ouncesOfSchraut)
    {
      doc.consumeSchraut(consume);
      m_ouncesOfSchraut-=consume;
    }
    
	//otherwise the doctor will consume his wanted amount of Schraut
    else if (consume > m_ouncesOfSchraut && m_ouncesOfSchraut != 0)
    {
      doc.consumeSchraut(m_ouncesOfSchraut);
      m_ouncesOfSchraut =0;
  }   
    
	//doctor succeeds in consuming schraut, number of operations 
	//= total schraut consumed-5, or only once if schraut <5
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
    
	//Doctor is angry because he is out, he doubles the amount
	//from the previous circumstance
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
    
    //patient is only charged once
    m_machine.chargePatient(pat);
    
    //doc gains half the cash
    doc.addMoney(m_machine.getCost());
  }
  cout << m_machine.getName() << " was used ";
  cout << m_machine.getNumUses()-initUses << " times";
  cout << endl;
  return;
}

template <class T_friend>
ostream& operator << (ostream& stream, hospitalRoom<T_friend>& hr)
{
  stream << "Ozs of Schraut = " << hr.m_ouncesOfSchraut << endl;
  stream << hr.m_machine;
  return stream;
}