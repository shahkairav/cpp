#include <iostream>
#include <vector>
#include <utility>

class A {
private:
    int a = 2;

protected:
    int b = 3;

public:
    int c = 4;

    void foo(A& other) {
        other.a = 5;
    }

    void print() {
        std::cout << this->a << std::endl;
    }
};

class B : public A {
    void foo() {

    }
};

int main() {
    A a;
    A b;
    a.foo(b);
    b.print();

    return 0;
}
