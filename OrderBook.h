#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"

#include <vector>

class OrderBook
{
public:
        /** Constructor */
        OrderBook(std::string filename);
        std::vector<std::string> getKnownProducts();

private:
        std::vector<OrderBookEntry> orders;
        std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product);
        std::vector<OrderBookEntry> matchAsksToBids(std::string product);

        // helpers
        void cleanOrderBook(std::vector<OrderBookEntry> orders);
        std::string getCurrentDateTime();

        // static helpers
        static bool sortAsksAsc(OrderBookEntry &a, OrderBookEntry &b);
        static bool sortBidsDesc(OrderBookEntry &a, OrderBookEntry &b);


};