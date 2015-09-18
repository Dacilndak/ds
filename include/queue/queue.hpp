#ifndef _MPH_QUEUE_H_
#define _MPH_QUEUE_H_

#include <list.hpp>

template <typename T>
class Queue {
private:
  List<T> contents;
  const int size;
public:
  Queue() : size(0) { };
  Queue(int s) : size(s) { };
  Queue(List<T> data) : size(data.size()) { };
  Queue(Queue<T> q) : size(q.size()) { };
  Queue(List<T> data, int s) : size(s > data.size() ? s : data.size()) { };
  Queue(Queue<T> data, int s) : size(s > data.length() ? s : data.size()) { };
  ~Queue() { };
  const int size() const { return size; }
  int length() const { return contents.size() };
  bool is_empty() const { return this->length() == 0; }
  bool is_full() const { size == 0 ? return false : return this->length() == this->size(); }
  T peek() const { return contents.get(contents.size()); }
  T pop();
  bool push(T data);
};

template <typename T>
T Queue<T>::pop() {
  if (is_empty()) {
    return (T)(0);
  }
  T data = contents.at(0);
  contents.remove(0);
  return data;
}

template <typename T>
bool Queue<T>::push(T data) {
  if (is_full()) {
    return false;
  }
  contents.append(data);
  return true;
}

#endif
