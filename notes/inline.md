## Inline

- Member functions of a class that are defined in the class declaration itself are implicitly inlined.

- One Defintion Rule (ODR):
    - inline functions, template functions, and constexpr variables can violate the ODR by having multiple **identical** definitions across several translation units and the compiler resolves them at link time.

    - identical class definitions are also allowed across multiple translation units.

- Complicated inline functions may be implicitly treated as static functions if the compiler chooses not to inline them at call sites in order to comply with the ODR.

- Inline variables are global variables that share the same address and do not violate the ODR. These can be included in multiple .cpp files without causing any errors.
    ```c++
    // In globals.h
    int myVar = 42;
    ```

    - This is not equivalent to `static` variables since they have external linkage and are shared across all translation units.

- `static` class members can now be defined within the class itself using the `inline` keyword and eliminate the requirement of a separate definition.
```c++
class myClass {
    inline static int myVar = 10;
};
```

- Class methods that are explicitly defined as inline functions must be implemented in the header files. This is because the compiler needs to know the function implementation for each translation unit in order for it to be inlined at all call sites.
