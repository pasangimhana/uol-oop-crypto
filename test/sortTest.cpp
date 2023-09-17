#include <iostream>
#include <vector>
#include <algorithm>

struct TestOrder {
    int price;
    float timestamp;
    float coins;
};

bool customComparator(const TestOrder& a, const TestOrder& b) {
    if (a.price == b.price) {
        if (a.timestamp == b.timestamp) {
            return a.coins < b.coins;
        }
        return a.timestamp < b.timestamp;
    }
    return a.price > b.price;
}

int main(int argc, char** argv) {
    std::vector<TestOrder> orders;

    // add order with similar price, but different timestamp
    orders.push_back(TestOrder{1000, 1.0, 0.02});
    orders.push_back(TestOrder{1000, 2.0, 0.02});
    orders.push_back(TestOrder{1000, 3.0, 0.02});

    // add order with similar price and timestamp, but different coins
    orders.push_back(TestOrder{1000, 1.0, 0.03});
    orders.push_back(TestOrder{1000, 1.0, 0.04});
    orders.push_back(TestOrder{1000, 1.0, 0.05});

    // add order with different price, timestamp and coins
    orders.push_back(TestOrder{2000, 1.0, 0.02});
    orders.push_back(TestOrder{2000, 2.0, 0.02});
    orders.push_back(TestOrder{2000, 3.0, 0.02});

    // Sort orders
    std::sort(orders.begin(), orders.end(), customComparator);

    // Print orders
    for (TestOrder& order : orders) {
        std::cout << "Price: " << order.price << ", Timestamp: " << order.timestamp << ", Coins: " << order.coins << std::endl;
    }
}
