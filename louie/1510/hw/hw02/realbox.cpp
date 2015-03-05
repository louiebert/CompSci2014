//Programmer: LOUIE BERTONCIN     Date: 2/26/2014
//File: realbox.cpp               Class: CS 1510, Section C
//Purpose: Contains definitions of RealBox class functions

#include <iostream>
#include <cstdlib>
#include "realbox.h"

using namespace std;

RealBox::RealBox(int s, float a)
{
  m_reals = new float[s];
  m_boxsize = s;
  for (int i = 0; i < s; ++i)
  {
    m_reals[i] = a;
  }
}

RealBox::~RealBox()
{
  delete [] m_reals;
}

const RealBox& RealBox::operator=(const RealBox& rhs)
{
  if (this != &rhs)
  {
    if (m_boxsize != rhs.m_boxsize && m_boxsize != 0)
    {
      delete [] m_reals;
    }

    m_boxsize = rhs.m_boxsize;
    m_reals = new float[m_boxsize];

    for (int i = 0; i < rhs.m_boxsize; ++i)
    {
      m_reals[i] = rhs.m_reals[i];
    }
  }

  return *this;
}

RealBox::RealBox(const RealBox& rhs)
{
  m_boxsize = 0;
  *this = rhs;
}

void RealBox::set(int i, float x)
{
  m_reals[i] = x;
  return;
}

std::ostream& operator<< (std::ostream& out, const RealBox& box)
{
  out << "[ ";
  for (int i = 0; i < box.m_boxsize; ++i)
  {
    out << box.m_reals[i] << ", ";
  }
  out << "]";
  return out;
}
