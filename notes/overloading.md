- Whenever the meaning of operator is not clear and undisputed, it should not be overloaded. Instead, provide a well-named function.

- Always stick to the operator's well-known semantics.

- Provide all out of a set of related operations.

- Member vs Non-member:
    - The binary operators `=` (assignment), `[]` (array subscription), `->` (member access), as well as the n-ary `()` (function call) operator, must always be implemented as member functions, because the syntax of the language requires them to.

    - If it is a unary operator, implement as a member function.

    - If a binary operator treats both operands the same, then implement as non-member function. If not, then it usually has to access the left operand's private members and hence, implement as a member function.

- Constness: If the operator as a non-member function would take the left operand as a const reference, then the member-version implementation should have a trailing `const` to ensure `*this` refers to the object as a constant reference.

- The following operators cannot be overloaded:
    - `.`
    - `::`
    - `sizeof`
    - `typeid`
    - `.*`
    - ternary `?:`

- A unary operator `@` applied to an object `x` is invoked as either `operator@(x)` or `x.operator@()`.

- A binary operator `@` applied to objects `x` and `y` is invoked as either `operator@(x, y)` or `x.operator@(y)`.

> NOTE: Overloaded logical operators `||` and `&&` do not follow the shortcut semantics that are used for builtin-types. Hence, it is almost never a good idea to overload these operators.

- Assignment operator:
    ```c++
    X& X::operator=(const X& rhs)
    {
        swap(rhs);
        return *this;
    }
    ```

- Stream operators:
    ```c++
    std::ostream& operator<<(std::ostream& os, const T& obj)
    {
        // Write obj to stream
        return os;
    }

    std::istream& operator>>(std::istream& is, T& obj)
    {
        // Read obj from stream
        if( /* no valid object of T found in stream */ )
            is.setstate(std::ios::failbit);
        return is;
    }
    ```

- Function call operator / Functor:
    ```c++
    struct X {
        // Overloaded call operator
        int operator()(const std::string& y) {
            return /* ... */;
        }
    };
    ```

    - Throughout the C++ STL, function objects are always copied. Hence, if the object must use data that is expensive to copy, then store the data elsewhere and make the functor store a reference to it.

- Comparison operators:
    ```c++
    #include <compare>

    struct X {
        // defines ==, !=, <, >, <=, >=, <=>
        friend auto operator<=>(const X&, const X&) = default;
    };
    ```

    - In most cases, defaulting the spaceship operator should do the job.

- Unary arithmetic operators:
    - The postfix version takes a dummy `int` argument to differentiate from the prefix method.

    ```c++
    struct X {
        X& operator++()
        {
            // Do actual increment
            return *this;
        }

        X operator++(int)
        {
            X tmp(*this);
            operator++();
            return tmp;
        }
    };
    ```

- Binary arithmetic operators:
    - Implement the compound operators as member functions and then implement the base operators as non-member functions in terms of their compound analogues.

    ```c++
    struct X {
        X& operator+=(const X& rhs)
        {
            // actual addition of rhs to *this
            return *this;
        }
    };

    inline X operator+(const X& lhs, const X& rhs)
    {
        X result = lhs;
        result += rhs;
        return result;
    }
    ```

    - Hence, in general, `a += b` is more efficient than `a = a + b`.

- Subscript operator:
    ```c++
    struct X {
        value_type& operator[](index_type idx);
        const value_type& operator[](index_type idx) const;
        // ...
    };
    ```

- Operators for Pointer-like types:
    ```c++
    struct my_ptr {
        value_type& operator*();
        const value_type& operator*() const;
        value_type* operator->();
        const value_type* operator->() const;
    };
    ```

    - The member access operator `->` is a bit weird. It implementes _drill-down behaviour_ i.e., it recursively calls the operator till it receives an object of pointer type. Note that the overload syntax does not take an argument.


