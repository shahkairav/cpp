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
    std::vector<int> vec{5, 2, 9, 13, 19, 16, 17, 1};
    std::sort(vec.begin(), vec.end());
    print_vec(vec);

    // partial sort
    vec = {5, 2, 9, 13, 19, 16, 17, 1};
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    print_vec(vec);

    // nth element
    vec = {5, 2, 9, 13, 19, 16, 17, 1};
    std::nth_element(vec.begin(), vec.begin() + 4, vec.end());
    print_vec(vec);

    // inplace_merge
    // the incremental step used for mergesort

    // partition
    // sort based on a predicate
    vec = {5, 2, 9, 13, 19, 16, 17, 1};



    // the end of range that satisfies the predicate is known as partition_point


    return 0;
}
