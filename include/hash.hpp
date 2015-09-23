#ifndef _MPH_HASH_H_
#define _MPH_HASH_H_

#include <cmath>

#include <vector.hpp>
#include <list.hpp>

namespace hash_functions {
  int knuth_div_hash(int k, int n) {
    return (k * (k + 3) ) % n;
  }

  int mod_hash(int k, int n) {
    return k % n;
  }
  
  int mult_hash(int k, int n) {
    float A = 0.5 * (sqrt(5) - 1);
    int s = floor(A * pow(2, 32));
    int x = k * s;
    return x >> (32 - 16);
  }

  int knuth_mult_hash(int k, int n) {
    return (k * 2654435761) >> (32 - (int)floor(log2(n)));
  }

  int basic_hash(int k, int n) {
    return knuth_mult_hash(k, n);
  }
};

template <typename T>
class HashTable {
private:
  int blocks;
  int (*hash_function)(int, int);
  Vector<List<T> > * contents;
public:
  HashTable();
  HashTable(int n);
  HashTable(int (*func)(int, int));
  HashTable(int (*func)(int, int), int n);
  ~HashTable();
  int size() const;
  int block_length(int block) const { return contents->at(block).size(); }
};

template <typename T> using Hash = HashTable<T>;

template <typename T>
HashTable<T>::HashTable() {
  hash_function = hash_functions::basic_hash;
  blocks = 100;
  contents = new Vector<List<T> >(blocks);
}

template <typename T>
HashTable<T>::HashTable(int s) {
  hash_function = hash_functions::basic_hash;
  blocks = s;
  contents = new Vector<List<T> >(blocks);
}

template <typename T>
HashTable<T>::HashTable(int (*func)(int, int)) {
  hash_function = func;
  blocks = 100;
  contents = new Vector<List<T> >(blocks);
}
  
template <typename T>
HashTable<T>::HashTable(int (*func)(int, int), int n) {
  hash_function = func;
  blocks = n;
  contents = new Vector<List<T> >(blocks);
}

template <typename T>
HashTable<T>::~HashTable() {
  delete contents;
}

template <typename T>
int HashTable<T>::size() const {
  int count;
  for (int i = 0; i < blocks; i++) {
    count += this->block_size(i);
  }
  return count;
}

#endif
