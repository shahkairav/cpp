## Templates:

- Prefer to use the `typename` keyword for template declarations. The `class` keyword is a remnant from C++'s history and is maintained for legacy purposes.

### The Very Basics

- Template functions can have implicit instantiations. The type deduction is similar to `auto`.
```c++
min(3, 6.5); // deduces to min<int, double>(3, 6.5);
```

- Explicit instantiation might be used to define base cases for variadic templates or template metaprogramming.
```c++
template min<int, double>(int x, double y);

template class array<int, 5>;
```

- `auto` parameters are shorthand for template types in template functions; works similar to implicit instantiation. Example:
```c++
bool predicate(auto x) {
    return x > 5;
}
```

- If the return type is dependent on the actual types used in case of multiple typenames, use `auto` and let the compiler figure out the appropriate type.
```c++
template<typename T, typename U>
auto add(T x, U y) {
    return x + y;
}
```

### Non-type parameters / Value templates:

- The type of parameter is predefined and is substitued for a `constexpr` expression. Example:
```c++
template<typename T, int size>
class array {
    private:
        T m_array[size] {};
}
```


### Variadic Templates:
- The ellipsis `...` is used to represent argument "packs" and "expansions".

- If placed on the left of the parameter, it represents a pack. If placed on the right of the parameter, it represents an expansion.

- Syntax:
    ```c++
    template <typename First, typename... Rest>
    returntype functionname(const First& first, const Rest&... args);
    ```

- Example:
    ```c++
    void print() {
        cout << endl;
    }

    template <typename T> void print(const T& t) {
        cout << t << endl;
    }

    template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
        cout << first << ", ";
        print(rest...); // recursive call using pack expansion syntax
    }
    ```

    - Can think of the parameter pack `rest` having the type `Rest`.


### Template Metaprogramming:

- Everything happens at compile-time. TMP is also Turing complete!

- `constexpr` is a request to compiler to run a piece of code at compile time. `consteval` is a requirement to run the code at compile time.
```c++
consteval size_t factorial(size_t n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}
```
