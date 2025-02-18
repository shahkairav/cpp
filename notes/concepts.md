- Before discussing concepts, we take a small detour and discuss type traits, since they are closely related concepts (haha).

## Type Traits:

-

## Concepts:

- Used to enhance templates with semantic logic and enforce such semantic checks at compile time. Introduced in **C++20**.

- A concept is a named set of constraints.

- Anything inside the braces must compile without error.

- Example:
```c++
template<typename T>
concept Comparable = requires(const T& a, const T& b) {
    { a < b } -> std::convertible_to<bool>;
}

template<typename T> requires Comparable<T>
T min(const T& a, const T& b);

// Shorthand for above
template<Comparable T>
T min(const T& a, const T& b);
```

- Leads to better compiler errors and can make debugging life way easier.
