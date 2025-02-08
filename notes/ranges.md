- Predicate: A boolean valued function.

- Lambda functions or functors are used to provide extra state to our function. A _functor_ is any object that implements the `operator()`.

- Lambda functions:
    ```c++
    auto lambda_func = [capture_clause](parameters) {
        return expression;
    }
    ```

    - `[&]`: capture everything by reference
    - `[&, x]`: capture everything by reference except for x
    - `[=]`: capture everything by value

    - Lambdas implicitly creater functor objects. The captures become field members of the class.

    - `std::function` is the overarching type for lambdas and functors. Example:
    ```c++
    std::functional<bool(int, int)> // functor or lambda function that takes two ints and returns a boolean
    ```

- A _range_ is anything with a begin() and an end().

- Any algorithm that takes a pair of iterators specifying a _range_ can instead simply take an object that implements the `begin()` and `end()` methods.
```c++
std::ranges::find(v, 5);
```

- Range algorithms are **constrained** i.e., they make use of _concepts_.

-
