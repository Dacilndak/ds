#ifndef _MPH_NODE_H
#define _MPH_NODE_H

#ifndef NULL
#define NULL 0
#endif

template <typename T>
class Node {
public:
  T data;
  Node<T> * next;
  Node<T> * prev;
  Node(T d, Node<T> * n) {
    data = d;
    next = n;
    prev = NULL;
  }
  Node(T d, Node<T> * p, Node<T> * n) {
    data = d;
    next = n;
    prev = p;
  }
};

#endif
