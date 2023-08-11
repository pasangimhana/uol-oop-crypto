#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

class MerkelMain {
public:
    MerkelMain();
    /** Call this to run the full program*/
    void init();

private:
    // Private member variables
    /** Order book */
    std::vector <OrderBookEntry> orders;

    // Private methods
    void loadOrderBook();
    static void printMenu();
    int getUserOption();
    void processUserOption(int userOption);
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
};
