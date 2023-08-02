#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class OrderBookType {
    ask, bid
};

class OrderBookEntry {
public:

    OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType) {
        this->price = _price;
        this->amount = _amount;
        this->timestamp = std::move(_timestamp);
        this->product = std::move(_product);
        this->orderType = _orderType;
    }

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

int main() {
    OrderBookEntry order1{100, 0.01, "123456789", "BTC-USD", OrderBookType::ask};
}
//
// Created by phaser on 02/08/23.
//
