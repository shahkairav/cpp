#include <iostream>

class A {
public:
    A() {
        std::cout << "Ctor called" << std::endl;
    }

    A(const A& other) {
        std::cout << "Copy ctor called" << std::endl;
    }

    A& operator=(const A& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        return *this;
    }
};

A foo() {
    A a = A();
    return a;
}

int main() {
    auto temp = foo();

    return 0;
}
