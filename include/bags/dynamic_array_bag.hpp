#ifndef _MPH_ARRAY_BAG_H_
#define _MPH_ARRAY_BAG_H_

#include <iostream>

template <typename T>
class DynamicArrayBag {
private:
  int maxItems;
  int itemCount;
  T * contents;
public:
  DynamicArrayBag();
  DynamicArrayBag(int size);
  DynamicArrayBag(int size, T * data, int len);
  ~DynamicArrayBag();
  bool insert(const T & newEntry);
  bool add(const T & newEntry) { return this->insert(newEntry); }
  bool remove(const T & toDelete);
  int contains(const T & data) const;
  int size() const { return itemCount; }
  bool isEmpty() const { return itemCount == 0; }
  bool isFull() const { return itemCount == maxItems; }
  template <typename U>
  friend std::ostream & operator<<(std::ostream & out, DynamicArrayBag<U> & b);
  template <typename U>
  friend std::istream & operator>>(std::istream & in, DynamicArrayBag<U> & b);
};

template <typename T>
DynamicArrayBag<T>::DynamicArrayBag() {
  maxItems = 10;
  itemCount = 0;
  contents = new T[maxItems];
}

template <typename T>
DynamicArrayBag<T>::DynamicArrayBag(int size) {
  itemCount = 0;
  if (size <= 0) {
    maxItems = 10;
  } else {
    maxItems = size;
  }
  contents = new T[maxItems];
}

template <typename T>
DynamicArrayBag<T>::DynamicArrayBag(int size, T * data, int len) {
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
DynamicArrayBag<T>::~DynamicArrayBag() {
  delete [] contents;
}

template <typename T>
bool DynamicArrayBag<T>::insert(const T & newEntry) {
  if (itemCount >= maxItems) {
    T * oldArray = contents;
    contents = new T[2 * maxItems];
    for (int i = 0; i < maxItems; i++) {
      contents[i] = oldArray[i];
    }
    delete [] oldArray;
    maxItems *= 2;
  }
  contents[itemCount] = newEntry;
  itemCount++;
  return true;
}

template <typename T>
bool DynamicArrayBag<T>::remove(const T & toDelete) {
  for (int i = 0; i < itemCount; i++) {
    if (contents[i] == toDelete) {
      for (int j = i + 1; j < itemCount; j++) {
	contents[j - 1] = contents[j];
      }
      itemCount--;
      return true;
    }
  }
  return false;
}

template <typename T>
int DynamicArrayBag<T>::contains(const T & data) const {
  int n = 0;
  for (int i = 0; i < itemCount; i++) {
    if (contents[i] == data) {
      n++;
    }
  }
  return n;
}

template<typename T>
std::istream & operator>>(std::istream & in, DynamicArrayBag<T> & b) {
  T tmp;
  in >> tmp;
  b.add(tmp);
  return in;
}

template <typename T>
std::ostream & operator<<(std::ostream & out, DynamicArrayBag<T> & b) {
  for (int i = 0; i < b.size() - 1; i++) {
    out << b.contents[i] << ", ";
  }
  out << b.contents[b.size() - 1];
  return out;
}

#endif
