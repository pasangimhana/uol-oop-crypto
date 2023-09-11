#include "OrderBook.h"
#include "CSVReader.h"
#include <vector>
#include <string>
#include <map>

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);

}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string, bool> productMap;

    for (OrderBookEntry& order : orders)
    {
        productMap[order.product] = true;
    }

    for (auto const& element : productMap)
    {
        products.push_back(element.first);
    }

    return products;

}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry& order : orders)
    {
        if (order.orderType == type && order.product == product)
        {
            orders_sub.push_back(e);
        }
    }

}