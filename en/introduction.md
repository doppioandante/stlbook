# What is the STL
The STL is part of the C++ standard library since the first standardization
(1998) and gathers various data structures, realized as _template classes_
(hence the name).<br>
As we will see, the STL offers three main elements to the programmer:
* **containers**: each container implements an abstract data structure
* **iterators**: every container has an uniform access interface called iterator
* **algorithms**: a lot of standard procedures operating on iterators are contained in the `<algorithm>` header

# What are the advantages of the STL?
The STL is general purpose and has good performance, allowing a broad usage.
Moreover, its design strongly influences important C++ libraries such as
[Boost](http://www.boost.org/), so learning about it is a good investment for
a C++ programmer.

With respect to pure C code, the presence of the STL allows C++ to have
expressive capabilities similar to those of definitely higher level languages:

* Templates and operator overloading permit easier abstraction over types,
  there's no need for `void*` pointers
* Memory is automatically managed by containers, avoiding commonplace errors
  from C memory management
* Reimplementing basic data structures such as growable arrays and associative
  arrays is discouraged, resulting in less coding time and better overall quality.

Let's see a practical comparision: the following code will read an array of
numbers from the standard input, and will print it in decreasing order afterwards.

In C, a possible solution could be like this:
```c
!INCLUDE "../code/list1.c"
```

while in C++, it would be like this:
```c++
!INCLUDE "../code/list2.cpp"
```

It's not necessary to fully understand the two codes now but, by comparing them,
we can observe the following things:

* Using the STL there's no need to resize `list`, because `std::vector` takes
  care of memory for us; moreover, there's no possibility to forget a `free()` at the
  end, because `list`'s destructor gets triggered at scope exit
* Thanks to templates we get some type-safety, while in C we have to cast a
  `void*` pointer
* C++ code could easily be redefined to work with non-int types, while this
  gets tricky in C
* `begin()` and `end()` allow iterator access to `list`; [ostream_iterator](<http://www.cplusplus.com/reference/iterator/ostream_iterator/)
  allows us to see `cout` as an iterator
* By using `greater<T>` from `<functional>` we can skip declaring our comparision
  function; in C++11 one may however prefer to use a lambda

We finally note that C++ code, despite being shorter, is surely more complex,
because it's more abstract. While this particular example could do with less
sofistication, this expressive power often allows for more reusable and clean
solutions.
