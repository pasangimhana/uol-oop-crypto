#include "OrderBook.h"
#include "CSVReader.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

// Constructor to create an order book from a CSV file
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string, bool> productMap;

    for (OrderBookEntry &order : orders)
    {
        productMap[order.product] = true;
    }

    for (auto const &element : productMap)
    {
        products.push_back(element.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product)
{
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry &order : orders)
    {
        if (order.orderType == type && order.product == product)
        {
            orders_sub.push_back(order);
        }
    }
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product)
{
    std::vector<OrderBookEntry> sales;
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product);
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product);

    // sort each vector by the custom comparator
    std::sort(asks.begin(), asks.end(), sortAsksAsc);
    std::sort(bids.begin(), bids.end(), sortBidsDesc);

    for (OrderBookEntry &bid : bids)
    {
        for (OrderBookEntry &ask : asks)
        {
            if (bid.price >= ask.price)
            {
                OrderBookEntry sale{0, 0, getCurrentDateTime(), product, OrderBookType::sale};

                if (bid.amount == ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    ask.amount = 0;
                    cleanOrderBook(orders);
                    break;
                }
                if (bid.amount > ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount -= ask.amount;
                    ask.amount = 0;
                    cleanOrderBook(orders);
                    break;
                }
                if (bid.amount < ask.amount)
                {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount -= bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }

            if (bid.price < ask.price)
            {
                cleanOrderBook(orders);
                break;
            }
        }
    }
    return sales;
}

bool sortAsksAsc(const OrderBookEntry &a, const OrderBookEntry &b)
{
    if (a.price == b.price)
    {
        if (a.timestamp == b.timestamp)
        {
            return a.amount < b.amount;
        }
        return a.timestamp.compare(b.timestamp) < 0;
    }
    return a.price < b.price;
}

bool sortBidsDesc(const OrderBookEntry &a, const OrderBookEntry &b)
{
    if (a.price == b.price)
    {
        if (a.timestamp == b.timestamp)
        {
            return a.amount < b.amount;
        }
        return a.timestamp.compare(b.timestamp) < 0;
    }
    return a.price > b.price;
}

std::string getCurrentDateTime()
{
    // Get current time point
    auto now = std::chrono::system_clock::now();

    // Convert to time_t (C-style time)
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convert to tm struct for more precise formatting
    std::tm *time_info = std::localtime(&now_time);

    // Format the time
    std::ostringstream oss;
    oss << std::put_time(time_info, "%Y/%m/%d %H:%M:%S");

    // Get milliseconds and microseconds
    auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto us = std::chrono::time_point_cast<std::chrono::microseconds>(now) - ms;

    // Append milliseconds and microseconds to the string
    oss << '.' << std::setfill('0') << std::setw(6) << us.count();

    return oss.str();
}

void cleanOrderBook(std::vector<OrderBookEntry> orders)
{
    auto it = std::remove_if(orders.begin(), orders.end(), [](const OrderBookEntry &entry)
                             { return entry.amount == 0; });

    orders.erase(it, orders.end());
}