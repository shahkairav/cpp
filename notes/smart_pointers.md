### Smart Pointers:

- Raw pointers are too powerful for their own good:
    - does it point to an array or a single object
    - pointer arithmetic and indexing makes sense only if pointing to an array but the type does not disambiguate between the two
    - owning vs non-owning: whose responsibility is it to delete the pointers
    - nullable vs non-nullable

- Smart pointers allows for dereferencing and pointing to objects of its type. On top of this, it provides its own smarts:
    - automatically release the resource (RAII)
    - enforce checks
    - enforce restrictions

- Use `std::span` for non-owning pointer to an array. A raw pointer may be used for non-owning pointer to an object; in the case of an owning pointer, always use a smart pointer.

- Defined in header `<memory>`.

#### Unique Pointer:
- Owns the memory; assumes it is the only owner. Releases the resource in its destructor. (RAII)

- Move only type to enforce unique ownership semantics.

```c++
typename<template T>
class unique_ptr {
public:
    using element_type = T;
    using pointer = T*;

    unique_ptr() noexcept : ptr(nullptr) { }
    explicit unique_ptr(T* p) noexcept : ptr(p) { }
    ~unique_ptr() noexcept { delete ptr; }

    // Forbids copy semantics
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // Move semantics
    unique_ptr(unique_ptr&& other) noexcept : ptr(std::exchange(other.ptr, nullptr)) { }
    unique_ptr& operator=(unique_ptr&& other) noexcept {
        delete ptr;
        ptr = o.ptr;
        o.ptr = nullptr;
        return *this;
    }

private:
    T* ptr;
}

std::unique_ptr<className> ptr{new className};
```
- The `release()` method gives up the ownership and returns a raw pointer. Note that this causes a resource leak.

- `reset(T* ptr)` releases the current object and takes ownership of the new raw pointer.

- `get()` returns the raw pointer that it owns without releasing the ownership.

- A unique pointer can be checked for nullptr as follows:
```c++
if (u_ptr) {
    // do something
}
```

- Instead of creating a unique pointer using a raw pointer, one can use `std::make_unique()`.
    - allocates memory
    - constructs an object of type `T` using the given arguments
    - wraps it in a unique pointer

    ```c++
    auto u_ptr = std::make_unique<T>(Args&&... args);
    ```

    - Note that the type `T` above cannot be deduced and must be explicitly specified.

- Syntax for arrays:
```c++

```
