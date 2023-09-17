#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    // Get current time point
    auto now = std::chrono::system_clock::now();

    // Convert to time_t (C-style time)
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convert to tm struct for more precise formatting
    std::tm* time_info = std::localtime(&now_time);

    // Format the time
    std::cout << std::put_time(time_info, "%Y/%m/%d %H:%M:%S");

    // Get milliseconds and microseconds
    auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto us = std::chrono::time_point_cast<std::chrono::microseconds>(now) - ms;

    // Print milliseconds and microseconds
    std::cout << '.' << std::setfill('0') << std::setw(6) << us.count() << std::endl;

    return 0;
}
