#include "MerkelMain.h"
#include "OrderBookEntry.h"


/** Public Methods */

MerkelMain::MerkelMain()
{
    std::cout << "Welcome to MerkelMain" << std::endl;
}

void MerkelMain::init()
{
    loadOrderBook();

    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}


/** Private Methods */


void MerkelMain::printMenu()
{
    std::cout << std::endl << std::endl << "1. Print Help" << std::endl
              << "2. Print exchange stats"
              << std::endl
              << "3. Place an ask"
              << std::endl
              << "4. Place a bid"
              << std::endl
              << "5. Print wallet"
              << std::endl
              << "6. Continue" << std::endl;

}

int MerkelMain::getUserOption(){
    std::cout << "Enter an input between 1 - 6: " << std::endl;
    int userOption;
    std::cin >> userOption;
    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}

void MerkelMain::printMarketStats()
{
    std::cout << "Here are the market exchange stats" << std::endl;
}

void MerkelMain::enterAsk()
{
    std::cout << "Place an ask?" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Place a bid?" << std::endl;
}

void MerkelMain::printWallet(){
    std::cout << "Print your wallet" << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Continue" << std::endl;
}
void MerkelMain::processUserOption(int userOption)
{

    if (userOption == 1)
    {
        printHelp();
    }

    switch (userOption)
    {
        case 2:
            printMarketStats();
            break;
        case 3:
            enterAsk();
            break;
        case 4:
            enterBid();
            break;
        case 5:
            printWallet();
            break;
        case 6:
            gotoNextTimeframe();
            break;
    }
}
/** Load the orderbook data */
void MerkelMain::loadOrderBook()
{

    // instead we can directly pass the consturctor
    orders.emplace_back(45.25, 0.01, "123456789", "BTC-USD", OrderBookType::ask);
    orders.emplace_back(45.26, 0.01, "123456789", "BTC-USD", OrderBookType::ask);


    // iterating the orders Orderbook using a range based for loop -  this is bad because you have to copy the object
    for (const OrderBookEntry order : orders){
        std::cout << "Price: " << order.price << std::endl;
    }

    // const means we are only reading, we are not editing,
    for (OrderBookEntry& order : orders){
        std::cout << "Price: " << order.price << std::endl;
    }
}