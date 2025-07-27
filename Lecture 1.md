Week 1: Introduction to C++
=============

The C++ Programming Language 
------------
* C++ is a high-level and high-performance programming language that supports multiple programming paradigms including rocedural programming (step-by-step instructions), object-oriented programming (classes, inheritance, polymorphism), and generic programming (templates).
* It is strongly typed (data types must be explicitly defined and are strictly enforced)
* It is compiled (code is translated into machine code before it runs, making execution fast)
* It allows low-level memory control through pointers and dynamic memory. 
* C++ is one of the most popular languages in the games industry.

Visual Studio IDE
-----------
* Visual Studio is an Integrated Development Environment (IDE) developed by Microsoft. 
* It provides tools for writing and editing C++ code
* As well as compiling and debugging C++ programs. 
* We will be using Visual Studio 2022 throughout this module.
* It is already installed on lab PCs, but you can install Visual Studio (not Visual Studio Code) on your personal device by downloading the installer at [visualstudio.microsoft.com](https://visualstudio.microsoft.com/)

 "Hello World": Your First C++ Program
 ----------
~~~cpp
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
~~~

* `#include` is a preprocessor directive used to include headers in programs. `#include <iostream>` includes the standard input/output library.
* All preprocessor directives are preceded by a # sign and are processed by the preprocessor before the source code is compiled.
* The `main()` function is the entry point to C++ programs. Execution begins here, and all C++ programs must have exactly one `main()` function.
* `std::cout` outputs a string to the console, `Hello World!` in this case, and then it moves the cursor to the next becuase of the `\n` character which represent a newline.
* `std` is the standard namespace in C++. It contains all the standard library functions and objects, like `cout`, `cin`, and many others. 
* A namespace is like a container that holds a set of identifiers (e.g. functions and classes) to avoid name conflicts. 
* Functions and objects defined inside the std namespace must be prefixed `std::` unless the compiler is told to automatically look inside std with `using namespace std`;

~~~cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
}
~~~
* The `using` directive can be used to provide access to all namespace qualifiers in the current scope. Use with care to avoid name conflicts.
