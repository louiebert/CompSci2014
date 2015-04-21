//Programmer: LOUIE BERTONCIN     Date: 4/17/2015
//File: datastack.hpp             Class: CS 1510, Section C
//Purpose: Definitions for DataStack class methods

#include <iostream>
#include <string>
#include <cstdlib>
#include "abstractstack.h"
#include "datastack.h"

using namespace std;

template <typename T>
bool DataStack<T>::isEmpty() const
{
  if (head != NULL)
    return false;
  return true;
}

template <typename T>
const T& DataStack<T>::top() const throw(Oops)
{
  if (!isEmpty())
    return head->m_data;
  throw(Oops("Oops! No top of the stack!"));
}

template <typename T>
void DataStack<T>::push(const T& x)
{
  if (isEmpty())
  {
    head = new Node<T>();
    head->m_data = x;
    return;
  }
  head = new Node<T>(x,head);
}

template <typename T>
void DataStack<T>::pop()
{
  if (isEmpty())
    return;
  Node<T>* temp = head;
  head = head->m_next;
  delete temp;
}

template <typename T>
void DataStack<T>::clear()
{
  while(head != NULL)
    pop();
}

template <typename T>
void DataStack<T>::add()
{
  try
  {
    int total = top();
    pop();
    total += top();
    pop();
    push(total);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::subtract()
{
  try
  {
    int second = top();
    pop();
    int first = top();
    pop();
    int difference = first - second;
    push(difference);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::multiply()
{
  try
  {
    int product = top();
    pop();
    product *= top();
    pop();
    push(product);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::divide()
{
  try
  {
    int second = top();
    pop();
    int first = top();
    pop();
    int quotient = first/second;
    push(quotient);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::modulo()
{
  try
  {
    int second = top();
    pop();
    int first = top();
    pop();
    int mod = first%second;
    push(mod);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::negate()
{
  try
  {
    int first = top();
    pop();
    first *= -1;
    push(first);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::sum()
{
  try
  {
    int sum = 0;
    int first = top();
    Node<T>* temp = head;
    while (temp != NULL)
    {
      sum += temp->m_data;
      temp = temp->m_next;
    }
    clear();
    push(sum);
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}

template <typename T>
void DataStack<T>::reverse()
{
  try
  {
    int first = top();
    DataStack<T>* mirror1 = new DataStack<T>();
    DataStack<T>* mirror2 = new DataStack<T>();

    while(head != NULL)
    {
      mirror1->push(head->m_data);
      pop();
    }
    while(mirror1->head != NULL)
    {
      mirror2->push(mirror1->head->m_data);
      mirror1->pop();
    }
    while(mirror2->head != NULL)
    {
      push(mirror2->head->m_data);
      mirror2->pop();
    }
    mirror1->clear();
    mirror2->clear();

    delete mirror1;
    delete mirror2;
  }
  catch(const Oops& err)
  {
    cerr << err.getMsg() << endl;
  }
}


