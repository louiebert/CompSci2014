//Programmer: LOUIE BERTONCIN     Date: 5/10/2015
//File: mybstree.hpp              Class: CS 1510, Section C
//Purpose: Function definitions for MyBSTree class

#include <iostream>
#include "abstractbstree.h"
#include "mybstree.h"

using namespace std;

template <typename T>
MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
  root = rhs.root->copy(rhs.root);
  return *this;
}

template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& cpy)
{
  root = cpy.root->copy(cpy.root);
}

template <typename T>
int MyBSTree<T>::size() const
{
  return size_of(root);
}

template <typename T>
int MyBSTree<T>::size_of(Node<T>* node) const
{
  if (node == NULL)
    return 0;
  return (size_of(node->m_left) + 1 + size_of(node->m_right));
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
  if (root == NULL)
    return true;
  return false;
}

template <typename T>
int MyBSTree<T>::height() const
{
  if (root == NULL)
    return 0;
  return root->height();
}

template <typename T>
int Node<T>::height() const
{
  int l = m_left ? m_left->height() : 0;
  int r = m_right ? m_right->height() : 0;
  int bigger;
  if (l > r)
    bigger = l;
  else
    bigger = r;
  return 1 + bigger;
}

template<typename T>
const T& MyBSTree<T>::findMax() const throw (Oops)
{
  if (root == NULL)
    throw(Oops("Oops! : Tree is Empty!!"));
  if (root->m_right == NULL)
    return root->m_data;
  return root->max()->m_data;
}

template <typename T>
Node<T>* Node<T>::max()
{
  if (m_right == NULL)
    return this;
  if (m_right->m_right == NULL)
    return m_right;
  return m_right->max();
}

template <typename T>
const T& MyBSTree<T>::findMin() const throw (Oops)
{
  if (root == NULL)
    throw(Oops("Oops! : Tree is Empty!!"));
  if (root->m_left == NULL)
    return root->m_data;
  return root->min()->m_data;
}

template <typename T>
Node<T>* Node<T>::min()
{
  if (m_left == NULL)
    return this;
  if (m_left->m_left == NULL)
    return m_left;
  return m_left->min();
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
  if (root == NULL)
    return 0;
  if (root->m_data == x)
    return 1;
  return root->find(x, 1);
}

template <typename T>
int Node<T>::find(const T& x, int lvl) const
{
  if (m_data == x)
    return lvl;
  if (m_data > x)
  {
    if (m_left == NULL)
      return -(lvl + 1);
    else
      return m_left->find(x, lvl + 1);
  }
  else
  {
    if (m_right == NULL)
      return -(lvl + 1);
    else
      return m_right->find(x, lvl + 1);
  }
}

template <typename T>
void MyBSTree<T>::clear()
{
  if (root != NULL)
    root->nodeClear(root);
}

template <typename T>
void Node<T>::nodeClear(Node<T>* tmp)
{
  if(tmp->m_left!=NULL)
    nodeClear(tmp->m_left);
  if(tmp->m_right!=NULL)
    nodeClear(tmp->m_right);
  delete tmp;
}

template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  if(root==NULL)
    root=new Node<T>(x);
  else
    root->insert(x);
}

template <typename T>
void Node<T>::insert(const T& x)
{
  if(x < m_data)
  {
    if(m_left==NULL)
      m_left=new Node(x);
    else
      m_left->insert(x);
  }
  else if(x > m_data)
  {
    if(m_right==NULL)
      m_right=new Node(x);
    else
      m_right->insert(x);
  }
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
  if (root == NULL)
    return;
  root->remove(root, x);
}

template <typename T>
void Node<T>::remove(Node<T>* &tmp, const T& x)
{
  if(tmp==NULL)
    return;
  else if(x<tmp->m_data)
  {
    remove(tmp->m_left, x);
  }
  else if(x>tmp->m_data)
    remove(tmp->m_right, x);
  else if(tmp->m_right!=NULL && tmp->m_left!=NULL)
  {
    tmp->m_data = tmp->m_left->max()->m_data;
    remove(tmp->m_left,tmp->m_data);
  }
  else
  {
    Node<T>* tmp1 = tmp;
    if(tmp->m_right!=NULL)
    {
      tmp = tmp->m_right;
      delete tmp1;
    }
    else
    {
      tmp = tmp->m_left;
      delete tmp1;
    }
  }
}



template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  if (root != NULL)
    root->printPre();
}

template <typename T>
void Node<T>::printPre() const
{
  cout << m_data << endl;
  if (m_left != NULL)
    m_left->printPre();
  if (m_right != NULL)
    m_right->printPre();
}



template <typename T>
void MyBSTree<T>::printPostOrder() const
{
  if (root != NULL)
    root->printPost();
}

template <typename T>
void Node<T>::printPost() const
{
  if (m_left != NULL)
    m_left->printPost();
  if (m_right != NULL)
    m_right->printPost();
  cout << m_data << endl;
}



template <typename T>
void MyBSTree<T>::print() const
{
  if (root != NULL)
    root->print(0);
}

template <typename T>
void Node<T>::print(int lvl) const
{
  if (m_right != NULL)
    m_right->print(lvl + 1);
  for(int i = 0; i < lvl; ++i)
    cout << "    ";
  cout << m_data << endl;
  if (m_left != NULL)
    m_left->print(lvl + 1);
}
