## Constexpr:

- The act of moving computation from runtime to compile time.

- It creates a compile time constant. Declares that the object is fit for use in what the standard calls _constant expressions_.

    ### Constant Expressions:

    - Can be used in places that need to be evaluated at compile time. Example: template parameters, array size.

    - Constant expressions may contain the following:
        - literals
        - most operators
        - constexpr variables
        - constexpr functions with constexpr arguments
        - non-type template parameters
        - enums
        - lambda functions
        - type traits

    - `const int` variables initialized using constant expressions are considered constexpr by default.


- Declaring something as constexpr doesn't mean it will necessarily be evaluated at compile time. Similarly, an object not explicitly declared as such might be evaluated at compile time.
    - However, functions always need to be explicitly marked `constexpr` if compile-time behaviour is desired.

    - The compiler is required to evaluate constant expressions at compile-time only in contexts that require a constant expression.

- `constexpr` implies `const`.

-
