### Header Files (.h or .hpp):

> Header is for specification

Header files contain class or function declarations, also known as the specification. They provide information about the public interface of classes or functions, such as member functions, constructors, and variables.
The header file is where you declare the class and its members, but it doesn't contain the actual implementation of member functions. It serves as a "promise" to provide the implementation elsewhere.
Implementation Files (CPP files):


> A .cpp file is for implementation.
> 
CPP files contain the actual implementation of member functions and other code that corresponds to the declarations in the header file.
Separating the implementation into CPP files allows for better organization and hides implementation details from users of the class.
Including Header Files:

In the main file (the entry point of the program), you need to include the header file to gain access to the class's declaration and its public interface.
Including the header file tells the compiler about the class's existence and how to use it in the main code.
Linker Errors:


#### Linker Error
When using header and CPP files, the linker error may occur if the implementation in the CPP file is not provided to the compiler during the build process.
The linker error is often due to a "promise" in the header file without a corresponding implementation.
How to Compile:

To compile the entire project, you need to provide all the CPP files in the build command. This ensures that the compiler has access to the implementation of all classes and functions.
Libraries:

The concept of separating header files from the implementation is similar to how external libraries are used. The header files provide the interface, while the library files contain the actual implementation.

#### Linker File
In C++, the main file (e.g., main.cpp) does not need to see the implementation details of classes and functions defined in separate CPP files. Instead, the main file only needs to include the corresponding header files that contain the class and function declarations (specifications).

The header files serve as a way to provide the main file with information about the classes and functions, including their names, data members, and member function prototypes. This allows the main file to use these classes and functions without knowing their actual implementation.

During the compilation process, each CPP file (e.g., OrderBookEntry.cpp) is compiled independently to create object files (e.g., OrderBookEntry.o). The object files contain the compiled code for the implementation of the classes and functions in the corresponding CPP files.

Finally, during the linking phase, the linker combines all the object files, including the main file (main.o), to create the final executable. The linker resolves the references to functions and classes made in the main file with their actual implementations found in the object file