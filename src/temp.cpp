#include <iostream>
using namespace std;

void foo(int x) {
  cout << x << endl;
}

void foo(double x) {
  cout << x << endl;
}

int main() {
  foo(3);
  foo(3.14);

  return 0;
}