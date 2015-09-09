#include <bag.hpp>
#include <iostream>
using namespace std;

void show_ptrs_fwd(List<double> * ll) {
  Node<double> * tmp = ll->begin();
  cout << "Forward:  ";
  while (tmp != NULL) {
    cout << tmp << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

void show_ptrs_bwd(List<double> * ll) {
  Node<double> * tmp = ll->end();
  cout << "Backward: ";
  while (tmp != NULL) {
    cout << tmp << " ";
    tmp = tmp->prev;
  }
  cout << endl;
}

int main() {
  Bag<double> b(5);
  DoubleList<double> * c = &b.contents;
  b.add(5.5);
  b.add(3);
  b.add(4);
  b.add(3);
  show_ptrs_fwd(c);
  show_ptrs_bwd(c);
  cout << *c << endl;
  b.remove(3);
  show_ptrs_fwd(c);
  show_ptrs_bwd(c);
  cout << *c << endl;
  b.remove(3);
  show_ptrs_fwd(c);
  show_ptrs_bwd(c);
  cout << *c << endl;
  b.remove(5.5);
  show_ptrs_fwd(c);
  show_ptrs_bwd(c);
  cout << *c << endl;
  b.remove(4);
  show_ptrs_fwd(c);
  show_ptrs_bwd(c);
  cout << *c << endl;
  b.remove(5.5);
  show_ptrs_fwd(c);
  show_ptrs_bwd(c);
  cout << *c << endl;
  return 0;
}
