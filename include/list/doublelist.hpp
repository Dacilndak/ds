#ifndef _MPH_DOUBLE_LIST_H_
#define _MPH_DOUBLE_LIST_H_

#include <iostream>

#include "node.hpp"

template <typename T>
class DoubleList {
public:
  Node<T> * fwalk(Node<T> * start, int dist) const;
  Node<T> * rwalk(Node<T> * start, int dist) const;
  Node<T> * head;
  Node<T> * tail;
public:
  DoubleList();
  DoubleList(T data);
  DoubleList(T * data, int len);
  ~DoubleList();
  Node<T> * begin() const { return this->head; }
  Node<T> * end() const { return this->tail; }
  T insert(int pos, T data) { return this->add(pos, data); }
  T add(int pos, T data);
  T remove(int pos);
  T prepend(T data);
  T append(T data);
  void clear();
  T at(int pos) const;
  T get(int pos) const;
  T set(int pos, T data);
  int size() const;
};

template <typename T>
Node<T> * DoubleList<T>::fwalk(Node<T> * start, int dist) const {
  Node<T> * tmp = start;
  for (int i = 0; i < dist; i++) {
    tmp = tmp->next;
    if (tmp->next == NULL) { return tmp; }
  }
  return tmp;
}

template <typename T>
Node<T> * DoubleList<T>::rwalk(Node<T> * start, int dist) const {
  Node<T> * tmp = start;
  for (int i = 0; i < dist; i++) {
    tmp = tmp->prev;
    if (tmp->prev == NULL) { return tmp; }
  }
  return tmp;
}

template <typename T>
DoubleList<T>::DoubleList() {
  this->head = NULL;
  this->tail = NULL;
}

template <typename T>
DoubleList<T>::DoubleList(T data) {
  this->head = new Node<T>(data, NULL, NULL);
  this->tail = this->head;
}

template <typename T>
DoubleList<T>::DoubleList(T * data, int len) {
  for (int i = 0; i < len; i++) {
    this->append(*(data + i));
  }
}

template <typename T>
DoubleList<T>::~DoubleList() {
  this->clear();
}

template <typename T>
T DoubleList<T>::add(int pos, T data) {
  if (pos > this->size()) { this->append(data); return data; }
  if (pos < 0) { this->prepend(data); return data; }
  Node<T> * tmp = fwalk(head, pos);
  Node<T> * new_node = new Node<T>(data, tmp->prev, tmp);
  tmp->prev = new_node;
  new_node->prev->next = new_node;
  return data;
}

template <typename T>
T DoubleList<T>::remove(int pos) {
  Node<T> * tmp = fwalk(head, pos);
  if (tmp != this->head) {
    tmp->prev->next = tmp->next;
  } else {
    this->head = tmp->next;
  }
  if (tmp != this->tail) {
    tmp->next->prev = tmp->prev;
  } else {
    this->tail = tmp->prev;
  }
  T data = tmp->data;
  delete tmp;
  return data;
}

template <typename T>
T DoubleList<T>::append(T data) {
  Node<T> * tmp = new Node<T>(data, this->tail, NULL);
  this->tail = tmp;
  if (this->head == NULL) {
    this->head = tmp;
  } else {
    tmp->prev->next = tmp;
  }
  return data;
}

template <typename T>
T DoubleList<T>::prepend(T data) {
  Node<T> * tmp = new Node<T>(data, NULL, this->head);
  this->head = tmp;
  if (this->tail == NULL) {
    this->tail = tmp;
  } else {
    tmp->next->prev = tmp;
  }
  return data;
}

template <typename T>
void DoubleList<T>::clear() {
  Node<T> * tmp;
  while (head != NULL) {
    tmp = head;
    head = tmp->next;
    delete tmp;
  }
  tail = head;
}

template <typename T>
T DoubleList<T>::at(int pos) const {
  if (pos < 0) { return (T)(NULL); }
  return fwalk(head, pos)->data;
}

template <typename T>
T DoubleList<T>::get(int pos) const {
  if (pos < 0) { return (T)(NULL); }
  return fwalk(head, pos)->data;
}

template <typename T>
T DoubleList<T>::set(int pos, T data) {
  Node<T> * tmp = fwalk(head, pos);
  tmp->data = data;
  return data;
}

template <typename T>
int DoubleList<T>::size() const {
  if (head == NULL) { return 0; }
  else if (head == tail) { return 1; }
  else if (head->next == tail) { return 2; }
  else {
    Node<T> * tmp = head;
    int count = 1;
    while (tmp->next != NULL) {
      tmp = tmp->next;
      count++;
    }
    return count;
  }
}

template<typename T>
std::ostream & operator<<(std::ostream & out, const DoubleList<T> & l) {
  Node<T> * tmp = l.begin();
  if (tmp == NULL) {
    out << "< empty >";
    return out;
  }
  while (tmp != l.end()) {
    out << tmp->data << " <-> ";
    tmp = tmp->next;
  }
  out << l.end()->data;
  return out;
}

template<typename T>
std::istream & operator>>(std::istream & in, DoubleList<T> & l) {
  T tmp;
  in >> tmp;
  l.append(tmp);
  return in;
}

#endif
