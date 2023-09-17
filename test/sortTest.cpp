#include <iostream>
#include <vector>
#include <algorithm>

struct TestOrder {
    int price;
    std::string timestamp;
    float coins;
};

bool customComparator(const TestOrder& a, const TestOrder& b) {
    if (a.price == b.price) {
        if (a.timestamp == b.timestamp) {
            return a.coins < b.coins;
        }
        return a.timestamp.compare(b.timestamp) < 0; // Compare timestamps using the compare function
    }
    return a.price > b.price;
}

int main(int argc, char** argv) {
    std::vector<TestOrder> orders;

    // add order with similar price, but different timestamps
    orders.push_back(TestOrder{1000, "2020/03/17 17:01:24.884492", 0.02});
    orders.push_back(TestOrder{1000, "2020/03/17 17:01:24.884493", 0.02});
    orders.push_back(TestOrder{1000, "2020/03/17 17:01:24.884491", 0.02});


    // add order with similar price and timestamp, but different coins
    orders.push_back(TestOrder{1000, "2020/03/17 17:01:24.884492", 0.01});
    orders.push_back(TestOrder{1000, "2020/03/17 17:01:24.884492", 0.02});
    orders.push_back(TestOrder{1000, "2020/03/17 17:01:24.884492", 0.03});

    // add order with different price, timestamp and coins
    orders.push_back(TestOrder{2000, "2020/03/17 17:01:24.884492", 0.01});
    orders.push_back(TestOrder{2000, "2020/03/17 17:01:24.884493", 0.02});
    orders.push_back(TestOrder{2000, "2020/03/17 17:01:24.884491", 0.03});

    // Sort orders
    std::sort(orders.begin(), orders.end(), customComparator);

    // Print orders
    for (TestOrder& order : orders) {
        std::cout << "Price: " << order.price << ", Timestamp: " << order.timestamp << ", Coins: " << order.coins << std::endl;
    }
}
