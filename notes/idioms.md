### SFINAE:
-

### Copy and Swap:
-

### PImpL:
-

### RAII:

- stands for _Resource Acquisition Is Initialization_. This concept can be better named as "Scope-bound resource management".

- This idiom is used to manage any resource that is in finite supply and must be judiciously used by the process.

- The constructor usually acquires the resource by either setting its member handle to point to the resource or creates a new object itself. The destructor releases the resource or deletes it if the resource was created in the object's constructor.

- This idiom avoids the issue of resource leaks and double deletion.

- Examples of RAII in the STL: `std::vector`, `std::string`.

- STL also offers several RAII wrappers such as `std::unique_ptr`, `std::lock_guard`, `std::shared_lock`.

```c++
void WriteToFile(const std::string& message) {
    // |mutex| is to protect access to |file| (which is shared across threads).
    static std::mutex mutex;

    // Lock |mutex| before accessing |file|.
    std::lock_guard<std::mutex> lock(mutex);

    // Try to open file.
    std::ofstream file("example.txt");
    if (!file.is_open()) {
        throw std::runtime_error("unable to open file");
    }

    // Write |message| to |file|.
    file << message << std::endl;

    // |file| will be closed first when leaving scope (regardless of exception)
    // |mutex| will be unlocked second (from |lock| destructor) when leaving scope
    // (regardless of exception).
}
```

- RAII also provides greater exception-safety since C++ standard guarantees that all local variables are deleted at the end of their scope in the reverse order of their construction.

### CRTP:

-
