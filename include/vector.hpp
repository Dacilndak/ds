#ifndef _MPH_VECTOR_H_
#define _MPH_VECTOR_H_

template <typename T>
class Vector {
private:
  int size;
  T * contents;
public:
  Vector();
  Vector(int size);
  Vector(int size, T * data, int len);
  ~Vector();
  bool insert(const T & newEntry, int index);
  bool append(const T & data);
  T & operator[](int index) { return this->at(index); }
  T & at(int index);
  int length() const { return size; }
};

template <typename T>
Vector<T>::Vector() {
  size = 0;
  contents = nullptr;
}

template <typename T>
Vector<T>::Vector(int s) {
  size = s;
  contents = new T[size];
}

template <typename T>
Vector<T>::Vector(int s, T * data, int len) {
  size = s > len ? s : len;
  contents = new T[size];
  for (int i = 0; i < len; i++) {
    contents[i] = data[i];
  }
}

template <typename T>
Vector<T>::~Vector() {
  if (contents != nullptr) {
    delete [] contents;
  }
}

template <typename T>
bool Vector<T>::insert(const T & newEntry, int index) {
  size += 1;
  T * tmp = realloc(contents, size);
  if (tmp == nullptr) {
    return false;
  }
  contents = tmp;
  for (int i = size - 1; i > index; i--) {
    contents[i] = contents[i - 1];
  }
  contents[index] = newEntry;
  return true;
}

template <typename T>
bool Vector<T>::append(const T & data) {
  size += 1;
  T * tmp = realloc(contents, size);
  if (tmp == nullptr) {
    return false;
  }
  contents = tmp;
  contents[size - 1] = data;
  return true;
}

template <typename T>
T & Vector<T>::at(int index) {
  return contents[index];
}

#endif
