//Programmer: LOUIE BERTONCIN     Date: 4/17/2015
//File: datastack.hpp             Class: CS 1510, Section C
//Purpose: Definitions for DataStack class methods

#include <iostream>
#include <string>
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
  if (isEmpty())
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
  if (head == NULL || head->m_next == NULL)
    return;
  int total = head->m_data + head->m_next->m_data;
  pop();
  pop();
  push(total);
}

template <typename T>
void DataStack<T>::subtract()
{
  if (head == NULL || head->m_next == NULL)
    return;
  int difference = head->m_next->m_data - head->m_data;
  pop();
  pop();
  push(difference);
}

template <typename T>
void DataStack<T>::multiply()
{
  if (head == NULL || head->m_next == NULL)
    return;
  int product = head->m_data * head->m_next->m_data;
  pop();
  pop();
  push(product);
}

template <typename T>
void DataStack<T>::divide()
{
  if (head == NULL || head->m_next == NULL)
    return;
  int quotient = head->m_next->m_data / head->m_data;
  pop();
  pop();
  push(quotient);
}

template <typename T>
void DataStack<T>::modulo()
{
  if (head == NULL || head->m_next == NULL)
    return;
  int mod = head->m_next->m_data % head->m_data;
  pop();
  pop();
  push(mod);
}

template <typename T>
void DataStack<T>::negate()
{
  if (head == NULL)
    return;
  head->m_data *= -1;
}

template <typename T>
void DataStack<T>::sum()
{
  if (head == NULL)
    return;
  int sum = 0;
  Node<T>* temp = head;
  while (temp != NULL)
  {
    sum += temp->m_data;
    temp = temp->m_next;
  }
  clear();
  push(sum);
}

template <typename T>
void DataStack<T>::reverse()
{
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


