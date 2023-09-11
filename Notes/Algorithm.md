# Order Matching Algorithm


## Steps to organize the Order Lists

1. References to the Buy orders and Sell orders of a pair are stored in two lists.

2. Those lists are sorted by the price once.
    - Buy orders are posted by buyers. The highest price is at the top. Because, the sellers want to sell at the highest price.
    - Sell orders are posted by sellers. The lowest price is at the top. Because, the buyers want to buy at the lowest price.

3. After that sorting round, the two lists are sorted again by their time stamps. If two orders have the same price, the order that was posted first is prioritized.

4. After that sorting round, the two lists are sorted again by their amount of coins. If two orders have the same price and time stamp, the order that has the smaller amount of coins is prioritized.

"To Increase liquidity"

## How sorting happens when a new order is posted





