#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class OrderBookType {
    ask, bid
};

class OrderBookEntry {
public:

    // instead of assigning the values in the function body, an initialization list can be used
    OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType)
    : price(_price), amount(_amount), timestamp(std::move(_timestamp)), product(std::move(_product)), orderType(_orderType) {}

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

int main() {
    OrderBookEntry order1{10.40, 0.01, "123456789", "BTC-USD", OrderBookType::ask};
    std::cout << "Price: " << order1.price << std::endl;
}
//
// Created by phaser on 02/08/23.
//
