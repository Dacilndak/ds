#ifndef _MPH_LINKLIST_H_
#define _MPH_LINKLIST_H_
#include <iostream>

#include <node.hpp>

template <typename T>
class LinkList {
private:
  Node<T> * head;
  Node<T> * tail;
  Node<T> * walk(Node<T> * start, int pos) const;
public:
  LinkList();
  LinkList(T data);
  LinkList(T * data, int len);
  ~LinkList();
  Node<T> * begin() const { return head; }
  Node<T> * end() const { return tail; }
  T add(int pos, T data);
  T remove(int pos);
  T prepend(T data);
  T append(T data);
  T at(int pos) const;
  T get(int pos) const;
  T set(int pos, T data);
  void clear();
  int size() const;
};

template <typename T>
Node<T> * LinkList<T>::walk(Node<T> * start, int pos) const {
  Node<T> * tmp = start;
  for (int i = 0; i < pos; i++) {
    tmp = tmp->next;
    if (tmp->next == NULL) { return tmp; }
  }
  return tmp;
}

template <typename T>
LinkList<T>::LinkList() {
  head = NULL;
  tail = NULL;
}

template <typename T>
LinkList<T>::LinkList(T data) {
  head = new Node<T>(data, NULL);
  tail = head;
}

template <typename T>
LinkList<T>::LinkList(T * data, int len) {
  for (int i = 0; i < len; i++) {
    this->append(*(data + i));
  }
}

template <typename T>
LinkList<T>::~LinkList() {
  this->clear();
}

template <typename T>
T LinkList<T>::add(int pos, T data) {
  Node<T> * tmp = walk(head, pos);
  Node<T> * new_node = new Node<T>(data, tmp);
  walk(head, pos - 1)->next = new_node;
  return data;
}

template <typename T>
T LinkList<T>::remove(int pos) {
  Node<T> * tmp = walk(head, pos);
  if (tmp == head) {
    head = head->next;
  } else if (tmp == tail) {
    tail = walk(head, pos - 1);
    tail->next = NULL;
  } else {
    walk(head, pos - 1)->next = walk(tmp, 1);
  }
  T data = tmp->data;
  delete tmp;
  return data;
}

template <typename T>
T LinkList<T>::prepend(T data) {
  Node<T> * tmp = new Node<T>(data, NULL);
  tmp->next = head;
  head = tmp;
  return data;
}

template <typename T>
T LinkList<T>::append(T data) {
  Node<T> * tmp = new Node<T>(data, NULL);
  tail->next = tmp;
  tail = tmp;
  return data;
}

template <typename T>
T LinkList<T>::at(int pos) const {
  if (pos < 0) { return NULL; }
  return walk(head, pos)->data;
}

template <typename T>
T LinkList<T>::get(int pos) const {
  if (pos < 0) { return NULL; }
  return walk(head, pos)->data;
}

template <typename T>
T LinkList<T>::set(int pos, T data) {
  Node<T> * tmp = walk(head, pos);
  tmp->data = data;
  return data;
}

template <typename T>
void LinkList<T>::clear() {
  Node<T> * tmp;
  while (head != NULL) {
    tmp = head;
    head = tmp->next;
    delete tmp;
  }
  tail = head;
}

template <typename T>
int LinkList<T>::size() const {
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
std::ostream & operator<<(std::ostream & out, const LinkList<T> & l) {
  Node<T> * tmp = l.begin();
  if (tmp == NULL) {
    out << "< empty >";
    return out;
  }
  while (tmp != l.end()) {
    out << tmp->data << " -> ";
    tmp = tmp->next;
  }
  out << l.end()->data;
  return out;
}

template<typename T>
std::istream & operator>>(std::istream & in, LinkList<T> & l) {
  T tmp;
  in >> tmp;
  l.append(tmp);
  return in;
}

#endif
