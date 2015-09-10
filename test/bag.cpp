#include <bag.hpp>
#include <iostream>
using namespace std;

void show_ptrs_fwd(const List<double> * ll) {
  Node<double> * tmp = ll->begin();
  cout << "Forward:  ";
  while (tmp != NULL) {
    cout << tmp << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

void show_ptrs_bwd(const List<double> * ll) {
  Node<double> * tmp = ll->end();
  cout << "Backward: ";
  while (tmp != NULL) {
    cout << tmp << " ";
    tmp = tmp->prev;
  }
  cout << endl;
}

int main() {
  LinkListBag<double> b(5);
  const List<double> * c = b.get_contents();
  b.add(5.5);
  b.add(3);
  b.add(4);
  b.add(3);
  cout << b << endl;
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

  StaticArrayBag<double> dB(4);
  for (int i = 0; i < 1000; i++) {
    dB.insert(i);
    if (dB.isFull()) {
      cout << "Expanding!" << endl;
    }
  }
  cout << dB << endl;
  return 0;
}
