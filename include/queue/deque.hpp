#ifndef _MPH_DEQUE_H_
#define _MPH_DEQUE_H_

template <typename T>
class DoubleQueue {
private:
  List<T> contents;
  const int size;
public:
  DoubleQueue() : size(0) { };
  DoubleQueue(int s) : size(s) { };
  DoubleQueue(List<T> data) : size(data.size()) { };
  DoubleQueue(DoubleQueue<T> q) : size(q.size()) { };
  DoubleQueue(List<T> data, int s) : size(s > data.size() ? s : data.size()) { };
  DoubleQueue(DoubleQueue<T> data, int s) : size(s > data.length() ? s : data.size()) { };
  ~DoubleQueue() { };
  const int capacity() const { return size; }
  const int size() const { return size; }
  int length() const { return contents.size(); };
  bool is_empty() const { return this->length() == 0; }
  bool is_full() const { size == 0 ? return false : return this->length() >= this->size(); }
  T peek_front() const { return contents.get(0); }
  T peek_back() const { return contents.get(contents.size()); }
  T pop_front();
  T pop_back();
  bool push_front(T data);
  bool push_back(T data);
};

template <typename T>
T DoubleQueue<T>::pop_front() {
  if (is_empty()) {
    return (T)(0);
  }
  T data = contents.at(0);
  contents.remove(0);
  return data;
}

template <typename T>
T DoubleQueue<T>::pop_back() {
  if (is_empty()) {
    return (T)(0);
  }
  T data = contents.at(contents.size());
  contents.remove(contents.size());
  return data;
}

template <typename T>
bool DoubleQueue<T>::push_front(T data) {
  if (is_full()) {
    return false;
  }
  contents.prepend(data);
  return true;
}

template <typename T>
bool DoubleQueue<T>::push_back(T data) {
  if (is_full()) {
    return false;
  }
  contents.append(data);
  return true;
}

#endif
