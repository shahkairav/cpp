- STL comprises of:
  1. General utilities
  2. Containers
  3. Adaptors
  4. Iterators

- Goal of STL: _#Algo * #Representations * #Types ==> #Algo + #Representations + #Types_

- Containers store collections of elements.
  Algorithms perform operations upon collections of elements.
  Containers and algorithms are entirely independent.
  Iterators provide a common unit of information exchange between containers and algorithms.

- Most algorithms are template functions parametrized by generic types of iterators.

- Sequence containers: `vector`, `deque`, `list`, `array`, `forward_list`

- Associative containers: `map`, `set`, `multimap`, `multiset` (and their unordered analogues)

- Container adaptors: `queue`, `stack`, `priority_queue`

- An iterator's interface specifies:
  - the complexity of observing and traversing a collection's elements
  - the manner in which elements are observed
  - wheter an element can be read from or written to

- Five iterator categories:
  - `output`
  - `input`
  - `forward`
  - `bidirectional`
  - `random access`

  `random access` -> `bidirectional` -> `forward` --> `input`
                                            \
                                              --> `output`

  - The above is not public heritance. It's a hierarchy of requirements.

--> Algorithms:
  - Processes ranges of elements of a collection. Requires at least one explicitly specified iterator pair.
  - Removing algorithms work by rearranging elements and setting the end iterator appoprately.

  - `sort()`
  - `lower_bound()`
  - `remove_copy_if()`
  - `find_if()`
  - `max_element()`
  - `copy_if(input1, input2, output, pred)`
  - `transform()`
  - `unique_copy()`

- Some sequences can be traversed only once and support only single-pass iteration: input/output iterators.

- Input iterators are also referred to as immutable iterators. The other types are mutable iterators.

--> Sequences:
- Iterator range is represented by a pair of iterators: [first, last)
  - Such a design was chosen since loops just need to test for iterator equality and indexing is not required.

--> Iterator Adaptors:
- Reverse iterators: template<class Iter> reverse_iterator;
- Insert iterators: template<class Container> back_insert_iterator, front_insert_iterator, insert_iterator;

--> Containers:
- Every STL container provides a common set of nested type aliases:
  - value_type
  - reference
  - const_reference
  - iterator
  - const_iterator
  - size_type
  - difference_type (denote difference between two iterators)

- Common set of functions:
  - begin()
  - end()
  - cbegin()
  - cend()

- Bidirectional containers provide these additional aliases and functions:
  - reverse_iterator
  - const_reverse_iterator
  - rbegin()
  - rend()
  - crbegin()
  - crend()

- vector<bool> is not a standard container for space optimisation reasons. Hence, a vector provides contiguous storage for all elements except bool. vector<bool> is used to deal with after the auto keyword was introduced in C++11.

- Stack, Queue, and Priority_Queue are by default implemented over deque.
