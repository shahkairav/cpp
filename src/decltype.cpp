#include <iostream>
#include <complex>
#include <type_traits>
using namespace std;

int main() {
  auto x = complex<int>{5,3};
  decltype(x) y;
  cout << typeid(x).name() << endl;
  return 0;
}