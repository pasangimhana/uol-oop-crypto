# Algorithm to tokenize a CSV file

1. First we define a seperator to tokenize the CSV file. In this case, we use a comma (,).
2. We define a string to store the current token. `token`
3. We define a vector of strings to store the tokens. `tokens`
4. We create controllers `start` and `end`.
5. A do while loop is created to iterate through the line.
6. First we set the `start` controller to the first character of the line.
7. Then set `end` to the first occurence of the seperator.
8. If `end` is not found, then we set `end` to the end of the line.
9. We then set `token` to the substring of the line from `start` to `end`.
10. We then push `token` to `tokens`.
11. We then set `start` to `end` + 1.
12. We then repeat steps 7 to 11 until `end` is equal to the end of the line.

## npos alternative
`std::string::npos` is a constant value defined in the C++ Standard Library's <string> header. It represents the maximum possible value for the size_t type, which is an unsigned integer type used for representing sizes and indices in C++.

In the context of the code snippet you provided:

```cpp
while (end != std::string::npos);
```
This line of code suggests that there is a loop that continues as long as the value of the variable end is not equal to s`td::string::npos`. This is commonly used in string manipulation to indicate that a specific operation should continue until the end of a string is reached. In most cases, `std::string::npos` is used as a sentinel value to indicate that a particular condition (like finding the end of a string) has not been met.