//Programmer: LOUIE BERTONCIN     Date: 3/2/2015
//File: arraylist.hpp             Class: CS 1510, Section C
//Purpose: Contains definitions of ArrayList class functions

#include <iostream>
#include "arraylist.h"
using namespace std;


/*
 * ---- Big 3 Member Functions ---
 */

template <typename T>
ArrayList<T>::~ArrayList<T>()
{
  delete[] m_data;
  m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  if (this != &rhs)
  {
    if (m_size != rhs.m_size && m_size != 0)
      delete[] m_data;

    m_size = rhs.m_size;
    m_max = rhs.m_max;

    m_data = new T[m_max];
    for (int i = 0; i < m_size; ++i)
      m_data[i] = rhs.m_data[i];
  }

  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_size = 0;
  *this = cpy;
}


/*
 * ----- Basic Accessor Operations -----
 */

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if (m_data == NULL)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << endl;
    return m_errobj;
  }
  return m_data[0];
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if (i < 0 || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" <<endl;
    return m_errobj;
  }
  return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if (i < 0 || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" <<endl;
    return m_errobj;
  }
  return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
  for (int i = 0; i < m_size; ++i)
  {
    if (m_data[i] == x){
      return i;
    }
  }
  return -1;
}


/*
 * ----- Basic Mutator Operations -----
 */

template <typename T>
void ArrayList<T>::clear()
{
  if (m_size != 0)
  {
    delete[] m_data;
    m_data = NULL;
  }

  m_size = 0;
  m_max = 0;

  return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  if (m_size == m_max)
  {
    if (m_max == 0)
      m_max = 1;
    m_max *= 2;
    T* tempArray = new T[m_size];
    for (int i = 0; i < m_size; ++i)
      tempArray[i] = m_data[i];
    delete[] m_data;
    m_data = new T[m_max];
    for (int i = 0; i < m_size; ++i)
      m_data[i] = tempArray[i];
    delete[] tempArray;
    tempArray = NULL;
  }
  m_data[m_size] = x;
  ++m_size;
  return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  if (i < 0 || i > m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)"<<
      endl;
    return;
  }
  if (m_size == m_max)
  {
    if (m_max == 0)
      m_max = 1;
    m_max *= 2;
    T* tempArray = new T[m_size];
    for (int i = 0; i < m_size; ++i)
      tempArray[i] = m_data[i];
    delete[] m_data;
    m_data = new T[m_max];
    for (int i = 0; i < m_size; ++i)
      m_data[i] = tempArray[i];
    delete[] tempArray;
    tempArray = NULL;
  }
  for (int j = m_size; j > i; --j)
    m_data[j] = m_data[j-1];
  ++m_size;
  m_data[i] = x;
  return;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if (i < 0 || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"<<
      endl;
    return;
  }
  if (m_size == 1)
  {
    m_size = 0;
    m_data = NULL;
    return;
  }
  for (int j = i; j < m_size - 1; ++j)
    m_data[j] = m_data[j+1];
  --m_size;
  if (m_size < m_max/4)
  {
    m_max /= 2;
    T* tempArray = new T[m_size];
    for (int i = 0; i < m_size; ++i)
      tempArray[i] = m_data[i];
    delete[] m_data;
    m_data = new T[m_max];
    for (int i = 0; i < m_size; ++i)
      m_data[i] = tempArray[i];
    delete[] tempArray;
    tempArray = NULL;
  }
  return;
}


/*
 * ----- Complex Mutator Operations -----
 */

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if (i < 0 || i >= m_size || k < 0 || k >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"<<
      endl;
    return;
  }
  T temp = m_data[i];
  m_data[i] = m_data[k];
  m_data[k] = temp;
  return;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  m_size += alist.m_size;
  if (m_size >= m_max)
  {
    if (m_max == 0)
      m_max = 1;
    while (m_size >= m_max)
      m_max *= 2;
    T* tempArray = new T[m_size];
    for (int i = 0; i < m_size - alist.m_size; ++i)
      tempArray[i] = m_data[i];
    for (int i = m_size - alist.m_size; i < m_size; ++i)
      tempArray[i] = alist.m_data[i-(m_size-alist.m_size)];
    delete[] m_data;
    m_data = new T[m_max];
    for (int i = 0; i < m_size; ++i)
      m_data[i] = tempArray[i];
    delete[] tempArray;
    tempArray = NULL;
  } else
  {
    for (int i = m_size - alist.m_size; i < m_size; ++i)
      m_data[i] = alist.m_data[i-(m_size-alist.m_size)];
  }
  return;
}

template <typename T>
void ArrayList<T>::purge()
{
  for (int i = 0; i < m_size; ++i)
  {
    for (int j = i + 1; j < m_size; ++j)
    {
      if (m_data[i] == m_data[j])
      {
        remove(j);
      }
    }
  }
  return;
}


