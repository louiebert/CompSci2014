//Programmer: LOUIE BERTONCIN     Date: 4/17/2015
//File: datastack.h               Class: CS 1510, Section C
//Purpose: Header file for DataStack Class

#ifndef DATASTACK_H
#define DATASTACK_H

#include <iostream>
#include <string>
#include "abstractstack.h"

using namespace std;

template <class T>
class Node
{
public:
  int m_data;                  // Data to be stored
  Node<T>* m_next;     // Pointer to the next element in the list


  Node() : m_next(NULL) {}

  Node(const T& x, Node<T>* p) : m_data(x), m_next(p) {}

};

template < typename T >
class DataStack: public AbstractStack<T>
{
  public:
    DataStack(): head(NULL) {}
    // const DataStack& operator= (const DataStack& rhs);

    bool isEmpty() const;
    const T& top() const throw ( Oops );
    void push(const T& x);
    void pop();

    ~DataStack() { clear(); }
    void clear();

    void add();
    void subtract();
    void multiply();
    void divide();
    void modulo();
    void negate();
    void sum();
    void reverse();

    Node<T>* head;
};

template <typename T>
ostream& operator<< (ostream& out, const DataStack<T>* dataStack)
{
  out << "[ ";
  if (dataStack->head != NULL)
  {
    Node<T>* temp = dataStack->head;
    out << temp->m_data;
    while(temp->m_next != NULL)
    {
      temp = temp->m_next;
      out << ", " << temp->m_data;
    }
    out << " ";
  }
  out << "]";
  return out;
}


#include "datastack.hpp"

#endif