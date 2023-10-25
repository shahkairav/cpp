#include <iostream>
using namespace std;

class B {
public:
    int x = 5;
    void foo() {
        cout << "B" << x << endl;
    }
};

class D1: public B {
public:
    int x = 7;
    void foo() {
        cout << "D1 " << x << endl;
    }
};

class D2: public D1 {
public:
    int x = 9;
    void bar() {
        cout << "D2 " << x << endl;
    }
};

int main() {
    D2* ptr = new D2;
    ptr->foo();
    ptr->bar();
    cout << sizeof(*ptr) << endl;
    return 0;
}