#include <iostream>

class MerkelMain {
    public:
    MerkelMain();
    /** Call this to run the full program*/
    void init();
    void printMenu();
    int getUserOption();
    void processUserOption(int userOption);
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
};
