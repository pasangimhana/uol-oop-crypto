#include <iostream>
#include <string>
#include <vector>

#include "MerkelMain.h"
#include "OrderBookEntry.h"

int main() {
    MerkelMain app{};
    app.init();
}























//    std::vector <OrderBookEntry> orders;
//
//    OrderBookEntry order1{10.40, 0.01, "123456789", "BTC-USD", OrderBookType::ask};
//
//    orders.push_back(order1);
//
//    // instead we can directly pass the consturctor
//    orders.push_back(OrderBookEntry{45.25, 0.01, "123456789", "BTC-USD", OrderBookType::ask});
//
//    // iterating the orders Orderbook using a range based for loop -  this is bad because you have to copy the object
//    for (const OrderBookEntry order : orders){
//        std::cout << "Price: " << order.price << std::endl;
//    }
//
//    // const means we are only reading, we are not editing,
//    for (OrderBookEntry& order : orders){
//        std::cout << "Price: " << order.price << std::endl;
//    }
//
// Created by phaser on 02/08/23.
//
