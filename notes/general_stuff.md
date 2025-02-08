- Initialization:
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

-
