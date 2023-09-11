#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& csvLine, char separator) {
    std::vector<std::string> tokens;
    signed int start, end;

    start = csvLine.find_first_not_of(separator, 0);

    do {
        end = csvLine.find(separator, start); // Find next separator after start

        if (start == csvLine.length() || start == end) {
            // Nothing more to find
            break;
        }

        std::string token;
        if (end >= 0) {
            token = csvLine.substr(start, end - start); // Get token between start and separator
        } else {
            token = csvLine.substr(start, csvLine.length() - start); // Get remaining string
        }

        tokens.push_back(token); // Add token to the end of the vector
        start = end + 1; // Move past this token
    } while (end > 0);

    return tokens;
}

int main() {
    std::string csvLine = "thing,thing2,thing3";
    char separator = ',';

    std::vector<std::string> tokens = tokenize(csvLine, separator);

    for (const std::string& token : tokens) {
        std::cout << token << std::endl;
    }
    return 0;
}
