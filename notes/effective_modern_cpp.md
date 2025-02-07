# [1] Deducing Types

## Item 1

### Understand template type deductions

- Consider the following pseudocode:
  ```c++
  template<typename T>
  void f(ParamType param);

  f(expr); // function call
  ```
  In the above case, the compiler has to deduce two types: 1) `T` 2) `ParamType`

- Case 1: `ParamType` is a reference or pointer, but not a universal reference
  - If `expr`'s type is a reference, ignore the reference part.
  - Then pattern match `expr`'s type against `ParamType` to determine `T`.

- Case 2: `ParamType` is a universal reference.
  -

## Item 2
### Understand `auto` type deduction

## Item 3:
### Understand `decltype` (DONE)
- `decltype` operator returns the type of the expression or the name.
- In C++11, it was primarily used to declare templatized function's return type that dependended on the template parameters of the function. Example:
  ```c++
  template<typename Container, typename Index>
  auto authAndAccess(Container& c, Index i) -> decltype(c[i]) {
    authenticateUser();
    return c[i];
  }
  ```
  The above exmple uses C++11's *trailing return type* syntax that is used to define function's return type using its parameters. The `auto` keyword here has nothing to do with type deduction and just indicates the aforementioned.

  In C++14, return types can be deduces even for multiple return functions as long as each return expressions deduces to the same type. In that case, `auto` does indicate type deduction for the return value.
  ```c++
  template<typename Container, typename Index>
  decltype(auto) authAndAccess(Container& c, Index i) {
    authenticateUser();
    return c[i];
  }
  ```
  The `decltype(auto)` syntax used above is needed to maintain the referenceness of the return type: it essentially denotes that the compiler deduces the return type while using decltype rules.

  The above definition still needs refinement: the container in its current form cannot bind to rvalues (since it's not a const lvalue reference), while there might be a use case where the client wants to pass a rvalue argument just to copy the indexed element immediately. To resolve this, we need to employ **universal references**. Thereafter, we also need to use `std::forward` in accordance to [Item 25](#item-25).
  ```c++
  template<typename Container, typename Index>
  decltype(auto) authAndAccess(Container&& c, Index i) {
    authenticateUser();
    return std::forward<Container>(c)[i];
  }
  ```

- For lvalue expressions of type T other than names (such as `(x)`), decltype always reports a type of `T&`.

## Item 4
### Know how to view deduced types


# [2] auto

## Item 5
### Prefer `auto` to explicit type declarations

## Item 6
### Use the explicitly typed initializer idiom when `auto` deduces undesired types


# [3] Moving to Modern C++

## Item 7

### Distinguish between `()` and `{}` when creating objects

-

## Item 8
### Prefer `nullptr` to `0` and `NULL`:
- Neither `0` not `NULL` has a pointer type. Passing these two might lead to calling a different overloaded function unintentionally.
- Notwithstanding this item, overloading functions with integral and pointer arguments should be avoided, since some developers will continue to use the above two identifiers.
- `nullptr`'s type is `std::nullptr_t` and can be thought of as a pointer of all types.
-

## Item 9
### Prefer `alias` declarations to `typedef`s
-

## Item 10
### Prefer scoped `enum`s to unscoped `enum`s
-

## Item 11
### Prefer deleted functions to private undefined ones
-

## Item 12
### Declare overriding functions `override`
-

## Item 13

## Item 14

## Item 15

### Use `constexpr` whenever possible (DONE)

- Conceptually, expressions marked as `constexpr` are values that are constant and are known at compilation time (to be more precise, their values are known at *translation time*).

- These objects can be places in read-only memory. Can also be used in places where only compile-time knowable values are accepted such as array size specifier, integral template arguments, alignment specifiers etc.

- `constexpr` functions produce compile-time knowable return values if called with `constexpr` parameters. Else, the function's return value may not be known at compile time. In C++14, such functions are limited to taking and returning *literal types* i.e., built-in types (including `void`) and UDT's that have `constexpr` constructor and member functions.

- Use `constexpr` functions and obbjects wherever possible since those can be employed in a wider range of contexts than otherwise.

- `constexpr` is a part of an object's or function's interface. If a function is later modified such that its return value cannot be knowable at compile time, that could break a lot of client code.

- Example code:
  ```c++
  class Point {
  public:
    constexpr Point(double xVal = 0, double yVal = 0) noexcept : x(xVal), y(yVal) {}

    constexpr double xValue() const noexcept { return x; }
    constexpr double yValue() const noexcept { return y; }

    constexpr void setX(double newX) noexcept { x = newX; }
    constexpr void setY(double newY) noexcept { y = newY; }
  }

  constexpr Point midpoint(const Point& p1, const Point& p2) noexcept {
    return { (p1.xValue() + p2.xValue()) / 2, (p1.yValue() + p2.yValue()) / 2 };
  }

  constexpr Point reflection(const Point& p) noexcept {
    Point result;
    result.setX(-p.xValue());
    result.setY(-p.yValue());
    return result;
  }

  int main() {
    constexpr Point p1(9.4, 27.7);
    constexpr Point p2(28.8, 5.3);
    constexpr auto mid = midpoint(p1, p2);
    constexpr auto reflectedMid = reflection(mid);

    return 0;
  }
  ```

## Item 16

## Item 17


# [4] Smart Pointers

- Drawbacks of raw pointers:
  1. declaration doesn't indicate whether it points to a single object or to an array.
  2. does not reveal ownership i.e., whether it's responsible for destroying the object.
  3. if to destroy, does not indicate whether to use `delete` or `delete[]` or a special destruction function.
  4. difficult to ensure that destruction of the object occurs *exactly once*.
  5. no way to handle dangling pointers problem.

- `std::auto_ptr` is a vestigial remnant of C++98 and has since been deprecated.

- There are three types of smart pointers: `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`.

- Included in the `<memory>` header file.

## Item 18

### Use `std::unique_ptr` for exclusive-ownership resource management

- `std::unique_ptr` is as efficient as a raw pointer as far as size and operational efficiency goes.

- A unique pointer can only be moved and copying functions are *deleted*. This embodies **exclusive ownership** semantics.

- Factory functions that return objects allocated on heap are ideal candidates for `std::unique_ptr`.
  ```c++
  template<typename... Ts>
  std::unique_ptr<className> factoryFunction(Ts&&... params);
  ```

- By default, resource destruction takes place via `delete` operator, but custom deleters can be specified at the risk of increasing size of the pointer object.
  ```c++
  auto customDeleter = [](Widget* w) {
    makeLogEntry(w);
    delete w;
  }

  template<typename... Ts>
  std::unique_ptr<Widget, decltype(customDeleter)> w(nullptr, customDeleter);
  ```

- `std::unique_ptr`'s can be easily converted into a `std::shared_ptr`:
  ```c++

  ```

## Item 19
### Use `std::shared_ptr` for shared-ownership resource management

## Item 20
### Use `std::weak_ptr` for `std::shared_ptr`-like pointers that can dangle

- Assigning a shared pointer to `std::weak_ptr` does not increase the reference count of the underlying.

## Item 21

### Prefer `std::make_unique` and `make_shared` to direct use of `new`

- `std::make_unique` provides exception safety if the constructor can potentially throw an exception.

- `std::make_shared` should be strongly prefered over using the `new` operator since shared pointers have to implement a control block for the purposes of reference counting and if the pointer is initialised using the latter approach, then two constructors are essentially called.

- ```c++
  class Widget {...};

  std::unique_ptr<Widget> ptr1 = std::make_unique<Widget>();
  std::shared_ptr<Widget> ptr2 = std::make_shared<Widget>(); // prefered approach
  std::shared_ptr<Widget> ptr3(new Widget()); // do NOT use!
  ```

## Item 22
### When using the *Pimpl idiom*, define special member function in the implementation file.
-

# [5] Rvalue References, Move Semantics, and Perfect Forwarding

## Item 23

### Understand `std::move` and `std::forward` (DONE)

- A parameter is always an *lvalue*, even if its type is an *rvalue reference*.
  ```c++
  void f(Widget&& w); // w is an lvalue, even if its type is Widget&&
  ```

- `std::move` and `std::forward` are just templatized casts. They do not do anything during runtime and do not generate any executable code. Possible implementation:
  ```c++
  template<typename T>
  decltype(auto) move(T&& param) {
    using ReturnType = remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
  }
  ```

- Don't declare objects `const` if you want to be able to move from them. Move requests on these objects are silently converted into *copy* operations.
  ```c++
  class Widget {
  public:
    explicit Widget(const std::string text): value(std::move(text)) {}

  private:
    std::string value;
  };

  class string {
  public:
    string(const string& rhs); // copy constructor
    string(string&& rhs);      // move constructor
  }
  ```
  Here, `text` is converted into a *const rvalue reference*. However, such a value cannot bind to *non-const rvalue reference* and hence, the copy constructor is invoked.

- In constrast to `std::move`, `std::forward` is a **conditional cast**. The most common use-case is when a template function takes a universal reference and has to subsequently pass the parameter to another function. `std::forward` casts into a *rvalue* only if the parameter was passed as a *rvalue* itself.
  ```c++
  void process(const Widget& w); // process lvalue
  void process(Widget&& w);      // process rvalue

  template<typename T>
  void callProcess(T&& param) {
    ...
    process(std::forward<T>(param));
  }
  ```
  `std::forward` is able to check the necessary conditions using the deduced template type `T`.

## Item 24
## Item 25
### Use `std::move` on rvalue references, `std::forward` on universal references:
-

## Item 26
## Item 27
## Item 28
## Item 29
## Item 30
## Item 31
## Item 32
## Item 33
## Item 33
## Item 34
## Item 35
## Item 36
## Item 37
## Item 38
## Item 39
## Item 40
## Item 41
## Item 42
