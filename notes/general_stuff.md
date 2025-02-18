### Initialization:

- Direct:
    ```c++
    int x = 12.0;
    int x(12.0); // leads to narrowing conversion
    ```

- Uniform / Braced:
    ```c++
    int x{4};
    int y = {4.5}; // fails since uniform init does not allow narrowing
    ```

- Structured Binding:
    - used to create new variables initialized using some other structure.

    ```c++
    auto [class_name, class_id, class_num_students] = class_struct;
    ```

    - can use on objects where the size is known at compile-time.

### Iterators:

- Used to iterate through containers without having to use dangerous pointers.

- All iterators provide these four ooperations:
    - `begin()` returns an iterator pointing to the first element
    - `end()` returns an iterator pointing to one element beyond the last element of the container.
    - `++it` increments the iterator by one
    - `*it` dereferences the iterator

- Types of iterators (bottom inherits from top):
    - input: allows reading the element
    - forward: allows multiple passes; contrast with _streams_
    - bidirectional: allows moving backward and forward
    - random access: allows indexing into the container

- Other type of iterator is `output` iterator. This iterator allows writing to the element.

### Static keyword:

- The `static` keyword used outside of a class / struct means that the variable / function has internal linkage i.e., it is visible only within that translation unit.
    - In some sense, `extern` does the opposite in that it just serves as the declaration of a variable and looks for the actual definition in other translation units.

- Inside of a class / struct, it means there will be only one shared instance of that variable across all instances of the class.
    - Static members cannot be defined inside of a class and need to be initialized outside of the class. This is because header files can be included in multiple translation units and that would lead to duplicate definitions if in-class definitions were allowed.

- Static methods cannot access non-static members for obvious reasons.

- Local Scope static:
    - Ensures that the lifetime of the variable is extended till the process is terminated.
    - However, the scope is still limited to the original scope.
    - Example:
    ```c++
    void foo() {
        static int i = 0;
        std::cout << i++ << std::endl;
    }
    ```
