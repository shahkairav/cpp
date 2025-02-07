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
    std::vector<int> heap{5, 2, 9, 13, 19, 16, 17, 1};
    std::make_heap(heap.begin(), heap.end());
    print_vec(heap);

    // add a new value to the heap
    heap.push_back(14);
    std::push_heap(heap.begin(), heap.end());
    print_vec(heap);

    // get the max value and pop it
    std::cout << "Max value = " << heap.front() << std::endl;

    // sort the heap
    // essentially what std::sort_heap() does
    for (int i = 0; i < heap.size(); i++) {
        std::pop_heap(heap.begin(), heap.end() - i);
    }
    print_vec(heap);

    return 0;
}
