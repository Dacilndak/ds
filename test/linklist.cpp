#include <list.hpp>
#include <iostream>
using namespace std;

void show_ptrs(List<int> * ll) {
  Node<int> * tmp = ll->begin();
  while (tmp != NULL) {
    cout << "Address: " << tmp << endl;
    tmp = tmp->next;
  }
}

int main() {
  int nums[4] = { 1, 2, 3, 4 };
  List<int> x(nums, 4);
  cout << "Made list" << endl;
  show_ptrs(&x);
  x.append(20);
  cout << endl << "Appended" << endl;
  show_ptrs(&x);
  x.prepend(10);
  cout << endl << "Prepended" << endl;
  show_ptrs(&x);
  x.remove(1);
  cout << endl << "Removed" << endl;
  show_ptrs(&x);
  x.add(1, 20);
  x.add(2, 50);
  cout << endl << "Added" << endl;
  show_ptrs(&x);
  cout << "Size: " << x.size() << endl;
  cout << x;
  x.clear();
  cout << endl << "Cleared" << endl;
  show_ptrs(&x);
  cout << x << endl;
  cout << "Size: " << x.size() << endl;
  cout << endl << "Destructor" << endl;
  return 0;
}
