- Essence:

    - Stick to what you do. Every class takes care of its own business.
    - A class should only have a single responsibility. Avoid swiss knives.

- Access modifiers:

    - Public: accessible by anyone
    - Protected: accessible by the class itself and the derived classes
    - Private: accessed by the class itself (i.e., other instance objects can access the member variables too)

- There is no default initialization for primitive types if not initialized.

- Keep your data members private unless necessary.

- Member functions do not contribute to the size of the object.

- Object size:

    - size of all members including the parent classes.
    - may have a pointer to vtable; `__vptr`
    - may include padding.
    - empty classes do not have zero size to ensure that two objects do not have the same address. However, an empty base class need not be represented by another byte; this is called _empty base class optimization_.

- Methods that are defined in the class definition itself (probably in a header file) are by default inlined by the compiler.

- this: is a pointer to the calling object.

- Constructors:

    - no constructors at all ==> empty constructor by default; calls empty constructors of the base class and the members.
    - no empty constructor ==> must pass parameters
    - Since C++11, can call another constructor; called CONSTRUCTOR DELEGATION
    - Can use default arguments
    - Ctor initialization list: used for initialization of members and base classes.
        - efficiency
        - correctness
        - must use if:
            a) contains object with no default ctor and no initialization on declaration
            b) contains const data member
            c) contains reference date member
            d) base class with no default ctor
    - members are initialized in the order of declaration in the class.

- Constructor delegation example:
  Rectangle(int x1, int y1, int x2, int y2): Rectangle(Point(x1, y1), Point(x2, y2)) {}

- Copy Constructor:

    - Syntax: A::A(const A& a);
    - Default copy ctor does a memberwise copy
    - Used when an object is passed by value. Except:
        - copy elision:
        - return value optimisation:

- Copy assignment operator:

    - Syntax: A& A::operator=(const A& a);

- Implicit casting works only for constant reference or for byval but not for byref.

    - This behaviour can be prevented by adding the explicit keyword to the constructor.
    - NOTE: It's okay to allow implicit construction if the arguments passed provide full state of the object.
        - For example: string creation using a const char\* is fine. However, implicitly creating a vector from an int by calling the Vector(int size) constructor is not something intended and should be used with the explicit keyword.

- Member functions that do not modify the object's members should be marked const so as to be compatible with `const` objects. However, they should also have `non-const` analogue implementations if mutable behaviour is desired for non-const objects.

```c++
template<typename T>
class Vector {
    public:
        const T& at(size_t index) const;
        T& at(size_t index);
}

// Implementation
template<typename T>
const T& Vector<T>::at(size_t index) const {
    return std::const_cast<Vector<T>&>(*this).at(index);
}
```

- Mutable keyword is used to mark member variables that can be changed even in const functions.

    - Members that are not part of the state of the object can be marked mutable.
    For example: For a vector class, only the size and the array constitute the state of the object, and members such as sum can be marked mutable.

- Rule of Zero:

    - best if the class doesn't need any resource management.
    - can be achieved by using properly managed data members such as string, containers, and smart pointers.

- Rule of Three:

    - If you need a destructor, always implement the copy ctor and assignment operator too.

- Rule of Five:
    - If you implement the Rule of Three, ask back for defaults for the move constructor and move assignment operator.

--> Inheritance:

- To invoke the base class's functions from the derived class, use the following syntax:

```c++
class derived : public base1, public base2 {
public:
    void foo() {
        base1::foo();
        base2::foo();

        // can even invoke the functions for some other object
        derived d2;
        d2.base1::foo();
    }
}
```

- Virtual functions are used for late binding. Adding the `virtual` keyword at the start of the function declaration ensures that the derived class's function is called even if using a pointer of base class type.

    - When using virtual functions, one can mark the functions in derived classes as `override` to specify that that function is supposed to override a virtual function. This helps compiler catch some trivial errors missed by the user.

- While implementing interfaces, implement the class as a `pure interface` to prevent spurious recompilation of user codes and need to include several header files. If there truly is some data that is common to all classes that derive from this interface, then store it in a class of its own and have the derived classes inherit from both.

```c++
class Shape {
    public:		// interface to users of Shapes
        virtual void draw() const = 0;
        virtual void rotate(int degrees) = 0;
        virtual Point center() const = 0;
        // ...

        // no data
};

struct Common {
    Color col;
    // ...åå
};

class Circle : public Shape, protected Common {
    public:
        void draw() const;
        void rotate(int) { }
        Point center() const { return cent; }
        // ...

    protected:
        Point cent;
        int radius;
};

class Triangle : public Shape, protected Common {
    public:
        void draw() const;
        void rotate(int);
        Point center() const;
        // ...

    protected:
        Point a, b, c;
};
```
