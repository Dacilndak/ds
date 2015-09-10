#ifndef _MPH_STATIC_ARRAY_BAG_H_
#define _MPH_STATIC_ARRAY_BAG_H_

#include <iostream>

template <typename T>
class StaticArrayBag {
private:
  int maxItems;
  int itemCount;
  T * contents;
public:
  StaticArrayBag();
  StaticArrayBag(int size);
  StaticArrayBag(int size, T * data, int len);
  ~StaticArrayBag();
  int size() const { return itemCount; }
  bool isEmpty() const { return itemCount == 0; }
  bool isFull() const { return itemCount == maxItems; }
  bool insert(const T & newEntry);
  bool add(const T & newEntry) { return this->insert(newEntry); }
  bool remove(const T & toDelete);
  int contains(const T & data) const;
  template <typename U>
  friend std::ostream & operator<<(std::ostream & out, StaticArrayBag<U> & b);
  template <typename U>
  friend std::istream & operator>>(std::istream & in, StaticArrayBag<U> & b);
};

template <typename T>
StaticArrayBag<T>::StaticArrayBag() {
  maxItems = 10;
  itemCount = 0;
  contents = new T[maxItems];
}

template <typename T>
StaticArrayBag<T>::StaticArrayBag(int size) {
  itemCount = 0;
  if (size <= 0) {
    maxItems = 10;
  } else {
    maxItems = size;
  }
  contents = new T[maxItems];
}

template <typename T>
StaticArrayBag<T>::StaticArrayBag(int size, T * data, int len) {
  itemCount = 0;
  if (size <= 0) {
    maxItems = 10;
  } else {
    maxItems = size;
  }
  contents = new T[maxItems];
  for (int i = 0; i < len; i++) {
    this->insert(data[i]);
  }
}

template <typename T>
StaticArrayBag<T>::~StaticArrayBag() {
  delete [] contents;
}

template <typename T>
bool StaticArrayBag<T>::insert(const T & newEntry) {
  if (itemCount >= maxItems) {
    return false;
  }
  contents[itemCount] = newEntry;
  itemCount++;
  return true;
}

template<typename T>
std::istream & operator>>(std::istream & in, StaticArrayBag<T> & b) {
  T tmp;
  in >> tmp;
  b.add(tmp);
  return in;
}

template <typename T>
std::ostream & operator<<(std::ostream & out, StaticArrayBag<T> & b) {
  for (int i = 0; i < b.size() - 1; i++) {
    out << b.contents[i] << ", ";
  }
  out << b.contents[b.size() - 1];
  return out;
}

#endif
