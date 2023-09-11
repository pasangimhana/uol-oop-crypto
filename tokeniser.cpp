#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> tokenize(const std::string &csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;

    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        end = csvLine.find(separator, start); // Find next separator after start

        if (start == csvLine.length() || start == end)
        {
            // Nothing more to find
            break;
        }

        std::string token;
        if (end >= 0)
        {
            token = csvLine.substr(start, end - start); // Get token between start and separator
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start); // Get remaining string
        }

        tokens.push_back(token); // Add token to the end of the vector
        start = end + 1;         // Move past this token
    } while (end > 0);

    return tokens;
}

int main()
{
    /*    std::string csvLine = "thing,thing2,thing3";*/
    char separator = ',';

    std::ifstream csvFile{"20200317.csv"};
    std::string line;

    if (csvFile.is_open())
    {

        std::vector<std::string> tokens;
        std::cout << "File open" << std::endl;
        while (std::getline(csvFile, line))
        {
            std::cout << line << std::endl;
            tokens = tokenize(line, separator);
            if (tokens.size() != 5) //
            {
                std::cout << "Error in Line" << std::endl;
                continue;
            }

            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error in line floats :" << line << std::endl;
                break;
            }

            for (const std::string &token : tokens)
            {
                std::cout << token << std::endl;
            }
        }
        csvFile.close();
    }
    else
    {
        std::cout << "File not open" << std::endl;
    }
    return 0;
}
