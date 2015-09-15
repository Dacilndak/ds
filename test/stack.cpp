#include <stack.hpp>
#include <iostream>
using namespace std;

int main() {
  cout << "Compiles!" << endl;
  Stack<int> s;
  s.push(4);
  s.push(5);
  s.pop();
  cout << s << endl;
  int data[7] = {1, 4, 5, 8, 6, 5, 10};
  s.push(data, 7);
  cout << s << endl;
  return 0;
}
