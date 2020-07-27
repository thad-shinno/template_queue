#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "node.h"
using std::cout;
using std::endl;

// First in first out templated queue

template <typename T>
class Queue {
  // queue has a front, back and size
  private:
    Node<T> *_front;
    Node<T> *_back;
    int _size;

  public:
    Queue<T>();
    T remove();
    void add(T);
    T peek();
    int size();
    void print();
};

// init size = 0
template <typename T>
Queue<T>::Queue() {
  _size = 0;
}

// add to back of queue
template <typename T>
void Queue<T>::add(T val) {
  Node<T> *n = new Node<T>(val);
  // if queue is empty, put it on front AND back
  if (_size == 0) {
    _front = n;
    _back = n;
    // double link
    _front->setNext(_back);
    _back->setPrev(_front);
  }
  // else put it in the back
  else {
    n->setPrev(_back);
    _back->setNext(n);
    _back = n;
  }
  _size++;
}

template <typename T>
T Queue<T>::remove() {
  // can't remove from empty queue
  if (_size == 0) {
    throw "Queue is empty";
  }

  T val = _front->getVal(); // save front
  _front = _front->getNext(); // remove front;
  _size--;
  return val;
}

// return, but don't remove front of queue
template <typename T>
T Queue<T>::peek() {
  // can't peek at an empty queue
  if (_size == 0) {
    throw "Queue is empty";
  }

  return _front->getVal();
}

template <typename T>
int Queue<T>::size() {
  return _size;
}

// print every item in the queue
template <typename T>
void Queue<T>::print() {
  Node<T> *curr = _front;
  for (int i = 0; i < _size; i++) {
    cout << curr->getVal() << " ";
    curr = curr->getNext();
  }
  cout << endl;
}

#endif
