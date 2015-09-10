/*
  bag.hpp
 */
#ifndef _MPH_LL_BAG_H_
#define _MPH_LL_BAG_H_

#include <iostream>
using namespace std;

#include <list.hpp>

// Specification

template <typename T>
class LinkListBag {
private:
  const int BAG_SIZE;
  List<T> contents;
public:
  LinkListBag(int size) : BAG_SIZE(size) { }
  ~LinkListBag() { }
  const List<T> * get_contents() const { return &contents; }
  bool isEmpty() const;
  bool isFull() const;
  int contains(T data) const;
  const int size() const { return contents.size(); };
  const int capacity() const { return BAG_SIZE; };
  bool add(T data);
  bool remove(T data);
  template <typename U>
  friend std::ostream & operator<<(std::ostream & out, LinkListBag<U> & b);
  template <typename U>
  friend std::istream & operator>>(std::istream & in, LinkListBag<U> & b);
};

// Implementation

template <typename T>
bool LinkListBag<T>::isEmpty() const {
  return (size() == 0);
}

template <typename T>
bool LinkListBag<T>::isFull() const {
  return (size() == capacity());
}

template <typename T>
int LinkListBag<T>::contains(T data) const {
  int n = 0;
  for (int i = 0; i < this->size(); i++) {
    if (contents.at(i) == data) {
      n++;
    }
  }
  return n;
}

template <typename T>
bool LinkListBag<T>::add(T data) {
  if (size() < capacity()) {
    contents.append(data);
    return true;
  } else {
    return false;
  }
}

template <typename T>
bool LinkListBag<T>::remove(T data) {
  for (int i = 0; i < this->size(); i++) {
    if (contents.at(i) == data) {
      contents.remove(i);
      return true;
    }
  }
  return false;
}

template<typename T>
std::istream & operator>>(std::istream & in, LinkListBag<T> & b) {
  T tmp;
  in >> tmp;
  b.add(tmp);
  return in;
}

template <typename T>
std::ostream & operator<<(std::ostream & out, LinkListBag<T> & b) {
  if (b.isEmpty()) {
    out << "< empty >";
    return out;
  }
  for (int i = 0; i < b.size() - 1; i++) {
    out << b.contents.at(i) << ", ";
  }
  out << b.contents.at(b.size() - 1);
  return out;
}

#endif
