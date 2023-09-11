#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"

#include <vector>

class OrderBook
{
    public:
    /** Constructor */
        OrderBook(std::string filename);
/** Returns all orders for a given product */
        std::vector<std::string> getKnownProducts();
/** Returns all orders for a given product */
        std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, double price);


    private:
        std::vector<OrderBookEntry> orders;
};