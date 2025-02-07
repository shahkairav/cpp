#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vec(const std::vector<T>& vec) {
    for (const auto& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1{1, 2, 3, 4, 7, 8, 9, 10, 14, 21, 42};
    std::vector<int> v2;

    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](int x) {
        return (x % 2 == 0);
    });

    print_vec(v2);

    return 0;
}
