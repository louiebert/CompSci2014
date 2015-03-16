//Programmer: LOUIE BERTONCIN     Date: 3/15/2015
//File: linkedlist.hpp            Class: CS 1510, Section C
//Purpose: Contains definitions of LinkedList class functions

#include <iostream>
#include "linkedlist.h"
using namespace std;

template <typename T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
  if (this != &rhs)
  {
    Node<T>* tempNode = rhs.head;
    if (head != NULL)
      LinkedList<T>::clear();
    if (tempNode == NULL)
      head = NULL;
    else
    {
      insert_front(tempNode->m_data);
      Node<T>* thisNode = head;
      while (tempNode->m_next != NULL)
      {
        tempNode = tempNode->m_next;
        thisNode->m_next = new Node<T>(tempNode->m_data, NULL);
        thisNode = thisNode->m_next;
      }
    }
  }

  return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  head = NULL;
  *this = rhs;
}

template <typename T>
int LinkedList<T>::size() const
{
  if (head == NULL)
    return 0;

  int count = 1;
  Node<T>* tempNode = head;
  while (tempNode->m_next != NULL)
  {
    ++count;
    tempNode = tempNode->m_next;
  }

  return count;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if (head == NULL)
    return true;
  return false;
}

template <typename T>
Node<T>* LinkedList<T>::getFirstPtr()
{
  if (head == NULL)
  {
    cout <<"!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list"<< endl;
  }
  return head;
}

template <typename T>
Node<T>* LinkedList<T>::getLastPtr()
{
  if (head == NULL)
  {
    cout <<"!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list" << endl;
    return NULL;
  }
  Node<T>* tempNode = head;
  while (tempNode->m_next != NULL)
    tempNode = tempNode->m_next;
  return tempNode;
}

template <typename T>
Node<T>* LinkedList<T>::getAtPtr(int i)
{
  int counter = i;
  Node<T>* tempNode = head;

  while (tempNode->m_next != NULL && counter > 0)
  {
    tempNode = tempNode->m_next;
    --counter;
  }

  if (counter > 0)
  {
    cout <<"!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index"<< endl;
    return NULL;
  }

  return tempNode;
}

template <typename T>
void LinkedList<T>::clear()
{
  while (head != NULL)
  {
    Node<T>* tempNode = head;
    if (tempNode->m_next != NULL)
    {
      while (tempNode->m_next->m_next != NULL)
        tempNode = tempNode->m_next;
      delete tempNode->m_next;
      tempNode->m_next = NULL;
    }
    else
    {
      delete tempNode;
      head = NULL;
    }
  }
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  Node<T>* newHead = new Node<T>(x, head);
  head = newHead;
}

template <typename T>
void LinkedList<T>::insert(const T& x, Node<T>* pos)
{
  if (head == pos)
  {
    insert_front(x);
    return;
  }
  Node<T>* tempNode = head;
  while (tempNode->m_next != NULL && tempNode->m_next != pos)
    tempNode = tempNode->m_next;
  if (tempNode->m_next != NULL)
    tempNode->m_next = new Node<T>(x, pos);
}



template <typename T>
void LinkedList<T>::remove(Node<T>* pos)
{
  if (head == NULL)
    return;
  if (head == pos)
  {
    delete head;
    return;
  }

  Node<T>* tempNode = head;
  while (tempNode->m_next != NULL && tempNode->m_next != pos)
    tempNode = tempNode->m_next;
  if (tempNode->m_next == NULL)
    return;
  if (tempNode->m_next->m_next != NULL)
  {
    Node<T>* secondTemp = tempNode->m_next;
    tempNode->m_next = secondTemp->m_next;
    delete secondTemp;
    secondTemp = NULL;
  } else
  {
    delete tempNode->m_next;
    tempNode->m_next = NULL;
  }
}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  Node<T>* lhsNode = head;
  Node<T>* rhsNode = rhs.head;

  while (rhsNode->m_next != NULL)
  {
    if (lhsNode->m_next == NULL)
      return false;
    if (lhsNode->m_data == rhsNode->m_data)
    {
      lhsNode = lhsNode->m_next;
      rhsNode = rhsNode->m_next;
    }
    else
    {
      return false;
    }
  }
  if (lhsNode->m_next != NULL)
    return false;

  return true;
}

template <typename T>
Node<T>* LinkedList<T>::find(const T& x)
{
  if (head == NULL)
    return NULL;
  if (head->m_data == x)
    return head;
  Node<T>* tempNode = head;
  while (tempNode->m_next != NULL)
  {
    tempNode = tempNode->m_next;
    if (tempNode->m_data == x)
      return tempNode;
  }
  return NULL;
}

template <typename T>
void LinkedList<T>::reverse()
{
  if (head == NULL)
    return;

  int listSize = size();
  T* tempArray = new T[listSize];
  Node<T>* tempNode = head;
  for (int i = listSize-1; i >= 0; --i)
  {
    tempArray[i] = tempNode->m_data;
    tempNode = tempNode->m_next;
  }
  clear();
  head = new Node<T>(tempArray[0], NULL);
  tempNode = head;
  for (int i = 1; i < listSize; ++i)
  {
    tempNode->m_next = new Node<T>(tempArray[i], NULL);
    tempNode = tempNode->m_next;
  }

  delete[] tempArray;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  if (xlist.head == NULL)
    return;
  Node<T>* tempNode;
  Node<T>* xlistTempNode = xlist.head;

  if (head != NULL)
  {
    tempNode = head;
    while (tempNode->m_next != NULL)
      tempNode = tempNode->m_next;
    tempNode->m_next = new Node<T>(xlistTempNode->m_data, NULL);
    tempNode = tempNode->m_next;
    while (xlistTempNode->m_next != NULL)
    {
      xlistTempNode = xlistTempNode->m_next;
      tempNode->m_next = new Node<T>(xlistTempNode->m_data, NULL);
      tempNode = tempNode->m_next;
    }
  }
  else
  {
    head = new Node<T>(xlistTempNode->m_data, NULL);
    tempNode = head;
    while (xlistTempNode->m_next != NULL)
    {
      xlistTempNode = xlistTempNode->m_next;
      tempNode->m_next = new Node<T>(xlistTempNode->m_data, NULL);
      tempNode = tempNode->m_next;
    }
  }
}
