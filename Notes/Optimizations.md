# Various Optimization Methods used

### i++ and ++i
In C++, using i++ for a loop is slower than ++i. This is because i++ creates a temporary variable, increments i, and returns the temporary variable. ++i increments i and returns the incremented value. This is a very small difference, but it can make a difference in a large loop.

### Using emplace_back() instead of push_back()
emplace_back() is faster than push_back() because it constructs the object in place instead of copying and moving it. This is especially useful for vectors of large objects.