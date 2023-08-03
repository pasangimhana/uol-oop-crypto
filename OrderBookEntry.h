
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
//
// Created by phaser on 03/08/23.
//

#ifndef UOL_OOP_CRYPTO_ORDERBOOKENTRY_H
#define UOL_OOP_CRYPTO_ORDERBOOKENTRY_H

#endif //UOL_OOP_CRYPTO_ORDERBOOKENTRY_H
