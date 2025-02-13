### Move Semantics

- _Copy as fallback_: If a rvalue reference is passed but move semantics are not implemented, then the copy constructor is used. To implement move-only objects, delete the copy constructor and such code will not be allowed.

- If a const object is tried to be moved, then the copy constructor is used instead.

- The compiler provides default move constructor and move assignment operator unless there is an user declared copy constructor, copy assignment operator, or destructor. If any of these is provided, the default move semantics are not supplied and instead fallback on copy semantics.

- Declared virtual destructors also disable automatic move semantics.

- `std::move(x)` is just syntactic sugar for `static_cast<T&&>(x)`.

- Move constructor syntax:
```c++
ClassName(ClassName&& obj) noexcept
```

- Move constructors should ideally be marked `noexcept`.

- Perfect forwarding:
  - `foo(const C&)` binds with all values.
    `foo(C&)` binds with non-const lvalues.
    `foo(C&&)` binds with rvalues.

  - If we had a wrapper function such as callFoo(x), then we would need to define three different functions to maintain the type correctness.
    ```c++
    callFoo(const C& x) { foo(x); }

    callFoo(C& x) { foo(x); }

    callFoo(C&& x) { foo(std::move(x)); } // if we don't have a move here, then the foo(C&) definition
                                          // is called and x is copied. Hence, the need for perfect forwarding.
    ```

  - Works only if all three conditions are satisfied:
    1. Template parameter
    2. Declare the parameter as && of the template parameter
    3. Forward the argument

    ```c++
    template<typename T>
    void callFoo(T&& x) { // x is a universal or forwarding reference
        foo(std::forward<T>(x));
    }
    ```

  - NOTE: `&&` declares:
    1. For types: raw rvalue references; must implement move semantics.
    2. For templates: universal references; must implement forward semantics.
