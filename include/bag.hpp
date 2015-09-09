/*
  bag.hpp
 */
#ifndef _MPH_BAG_H_
#define _MPH_BAG_H_

#include <iostream>
using namespace std;

#include <list.hpp>

// Specification

template <typename T>
class Bag {
public:
  const int BAG_SIZE;
  List<T> contents;
public:
  Bag(int size) : BAG_SIZE(size) { }
  ~Bag() { }
  bool isEmpty() const;
  bool isFull() const;
  int contains(T data) const;
  const int size() const { return contents.size(); };
  const int capacity() const { return BAG_SIZE; };
  bool add(T data);
  bool remove(T data);
};

// Implementation

template <typename T>
bool Bag<T>::isEmpty() const {
  return (size() == 0);
}

template <typename T>
bool Bag<T>::isFull() const {
  return (size() == capacity());
}

template <typename T>
int Bag<T>::contains(T data) const {
  int n = 0;
  for (int i = 0; i < this->size(); i++) {
    if (contents.at(i) == data) {
      n++;
    }
  }
  return n;
}

template <typename T>
bool Bag<T>::add(T data) {
  if (size() < capacity()) {
    contents.append(data);
    return true;
  } else {
    return false;
  }
}

template <typename T>
bool Bag<T>::remove(T data) {
  for (int i = 0; i < this->size(); i++) {
    if (contents.at(i) == data) {
      contents.remove(i);
      return true;
    }
  }
  return false;
}

template<typename T>
std::istream & operator>>(std::istream & in, Bag<T> & b) {
  T tmp;
  in >> tmp;
  b.add(tmp);
  return in;
}

#endif
