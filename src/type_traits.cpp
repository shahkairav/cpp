#include <iostream>
#include <type_traits>

void algorithm_signed(int i) {
    std::cout << "signed\n";
 }
void algorithm_unsigned(unsigned u) {
    std::cout << "unsigned\n";
}


template <typename T>
void algorithm(T t)
{
    if constexpr (std::is_signed_v<T>)
        algorithm_signed(t);
    else
    if constexpr (std::is_unsigned_v<T>)
        algorithm_unsigned(t);
    else
        static_assert(std::is_signed<T>::value || std::is_unsigned<T>::value, "Must be signed or unsigned!");
}

int main() {
    algorithm(1);
    algorithm(1u);
    return 0;
}
