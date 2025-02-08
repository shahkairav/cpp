## All about C++ Templates

- Prefer to use the `typename` keyword for template declarations. The `class` keyword is a remnant from C++'s history and is maintained for legacy purposes.

### The Very Basics

- Template functions can have implicit instantiations. The type deduction is similar to `auto`.

- `auto` parameters are shorthand for template types in template functions; works similar to implicit instantiation. Example:
    ```c++
    bool predicate(auto x) {
        return x > 5;
    }
    ```

-

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
