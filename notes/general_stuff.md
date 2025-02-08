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

-

