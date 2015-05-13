//Programmer: LOUIE BERTONCIN     Date: 5/10/2015
//File: mybstree.h                Class: CS 1510, Section C
//Purpose: Header file for MyBSTree Class

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
#include "abstractbstree.h"

using namespace std;

template <typename T>
class Node
{

  public:
    T m_data;
    Node<T>* m_left;
    Node<T>* m_right;
    
    Node() : m_left(NULL), m_right(NULL) {}
    Node(const T& x) :m_data(x), m_left(NULL), m_right(NULL)  {}
    Node(const T& x, Node<T>* l, Node<T>* r) : m_data(x),m_left(l),m_right(r) {}
    Node<T>* copy(const Node<T>* tmp)
    {
      if(tmp==NULL)
        return NULL;
      else
      {
        Node<T>* cpy = new Node<T>(tmp->m_data, copy(tmp->m_left),
          copy(tmp->m_right));
        return cpy;
      }
    }

    int height() const;
    Node<T>* max();
    Node<T>* min();
    int find(const T& x, int lvl) const;

    void nodeClear(Node<T>* tmp);
    void insert(const T& x);
    void printPre() const;
    void printPost() const;
    void print(int lvl) const;
    void remove(Node<T>* &tmp, const T& x);
};

template <typename T>
class MyBSTree: public AbstractBSTree<T>
{
  public:
    Node<T>* root;

    MyBSTree(): root(NULL) {}
    MyBSTree<T>& operator=(const MyBSTree<T>& rhs);
    MyBSTree(const MyBSTree<T>& cpy);
    ~MyBSTree()
    {
      clear();
    }

    int size() const;
    bool isEmpty() const;
    int height() const;
    const T& findMax() const throw (Oops);
    const T& findMin() const throw (Oops);
    int find(const T& x) const;

    void clear();
    void insert(const T& x);
    void remove(const T& x);
    void printPreOrder() const;
    void printPostOrder() const;
    void print() const;
  private:
    int size_of(Node<T>* node) const;
    void makeEqual(Node<T>* node);
};

#include "mybstree.hpp"

#endif