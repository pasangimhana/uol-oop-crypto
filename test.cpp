#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenise(std::string line, char separator) {
    std::vector<std::string> tokens;
    std::string token;

    signed int start, end;

    start = line.find_first_not_of(separator, 0);

    do {
        end = line.find_first_of(separator, start);
        // check if the end is equal to start, or start is equal to the length of the line
        if (start == line.length() || start == end) {
            break;
        }
        // if the end is not -1, then there is a token to be extracted
        if (end >= 0) {
            token = line.substr(start, end - start);
        }
            // if the end is -1, then the token is the remainder of the string
        else {
            token = line.substr(start, line.length() - start);
        }

        tokens.push_back(token);

    } while (end > 0);

    return tokens;
}

int main() {
    std::string line = "Hello,World,How,Are,You,Today";
    std::cout << line << std::endl;
    std::vector<std::string> tokens = tokenise(line, ',');
    for (auto const &token: tokens) {
        std::cout << token << std::endl;
    }
    return 0;
}