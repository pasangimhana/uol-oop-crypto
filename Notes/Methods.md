# Glossary related to methods

### Static methods
A static method is a method that is bound to a class rather than its object. It doesn't require creation of a class instance, much like a global function. Static methods are usually used to implement functions that belong to the class, but not to any particular object of it.

Example : an initializer function that needs to be called once, before the class is used for the first time.
```cpp
class App {
    static void init() { /* ... */ }
};
```