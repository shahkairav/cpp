#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Functors: objects that define the operator()
template <typename T>
struct greater {
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

// template <std::size_t N>
// class lessThanN {
//     bool operator() ()
// }

int main() {
    std::vector<int> vec{1, 2, 3, 4, 7, 8, 9, 10, 14, 21, 42};

    // Example of a lambda
    std::cout << *std::find_if(vec.begin(), vec.end(), [](int x) {
        return (x % 2 == 0) && (x % 7 == 0);
    }) << std::endl;

    // Overarching type for function pointers and functors
    std::function<bool(int, std::string)> foo = [](int x, std::string s) {
        return stoi(s) == x;
    };

    std::cout << foo(5, "5") << std::endl;
    std::cout << foo(10, "101") << std::endl;


    return 0;
}
