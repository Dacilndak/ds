#ifndef _MPH_STACK_H_
#define _MPH_STACK_H_

#include <list.hpp>

#ifndef NULL
#define NULL 0
#endif

template <typename T>
class Stack {
private:
  List<T> contents;
public:
  Stack() : contents() { }
  Stack(T data) : contents(data) { }
  Stack(T * data, int len) : contents(data, len) { }
  T pop();
  T push(T data);
  T * push(T * data, int len);
  int size() const { return this->contents.size(); }
  template <typename U>
  friend std::ostream & operator<<(std::ostream & out, const Stack<U> & s);
  template <typename U>
  friend std::istream & operator>>(std::istream & out, Stack<U> & s);
};

template <typename T>
T Stack<T>::pop() {
  if (this->contents.size() == 0) {
    return (T)(NULL);
  }
  T temp = this->contents.at(this->contents.size());
  this->contents.remove(this->contents.size());
  return temp;
}

template <typename T>
T Stack<T>::push(T data) {
  this->contents.append(data);
  return data;
}

template <typename T>
T * Stack<T>::push(T * data, int len) {
  for (int i = 0; i < len; i++) {
    this->contents.append(data[i]);
  }
  return data;
}

template<typename T>
std::ostream & operator<<(std::ostream & out, const Stack<T> & s) {
  out << s.contents;
  return out;
}

template<typename T>
std::istream & operator>>(std::istream & in, Stack<T> & s) {
  T input;
  in >> input;
  s.push(input);
  return in;
}

#endif
