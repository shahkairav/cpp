// Views are composable

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

template <typename T>
void print_vec(const std::vector<T>& vec) {
    for (const auto& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e'};
    auto f = std::ranges::views::filter(letters, [](char c) {
        c = toupper(c);
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    });
    auto t = std::ranges::views::transform(f, [](char c) {
        return toupper(c);
    });
    auto new_vec = std::ranges::to<std::vector<char>>(t);

    print_vec(new_vec);

    // Can also chain views
    auto piped_vec = letters |
        std::ranges::views::filter([](char c) {
            c = toupper(c);
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }) |
        std::ranges::views::transform([](char c) {
            return toupper(c);
        }) |
        std::ranges::to<std::vector<char>>();

    print_vec(piped_vec);

    return 0;
}
