// @author Thad Shinno
#ifndef NODE_H
#define NODE_H

// Node has a generic datatype val, next node, and previous node.

template <typename T>
class Node {
  private:
    T _val;
    Node *_next;
    Node *_prev;

  public:
    Node<T>(T);
    void setNext(Node*);
    void setPrev(Node*);
    Node<T>* getNext();
    Node<T>* getPrev();
    T getVal();
};

template <typename T>
Node<T>::Node(T val) {
  _val = val;
}

template <typename T>
void Node<T>::setNext(Node<T> *next) {
  _next = next;
}

template <typename T>
void Node<T>::setPrev(Node<T> *prev) {
  _prev = prev;
}

template <typename T>
Node<T>* Node<T>::getNext() {
  return _next;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
  return _prev;
}

template <typename T>
T Node<T>::getVal() {
  return _val;
}

#endif
