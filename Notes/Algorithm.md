# Order Matching Algorithm


## Steps to organize the Order Lists

1. References to the Buy orders and Sell orders of a pair are stored in two lists.

2. Those lists are sorted by the price once.
    - Buy orders are posted by buyers. The highest price is at the top. Because, the sellers want to sell at the highest price.
    - Sell orders are posted by sellers. The lowest price is at the top. Because, the buyers want to buy at the lowest price.

3. After that sorting round, the two lists are sorted again by their time stamps. If two orders have the same price, the order that was posted first is prioritized.

4. After that sorting round, the two lists are sorted again by their amount of coins. If two orders have the same price and time stamp, the order that has the smaller amount of coins is prioritized.

"To Increase liquidity"

## How matching happens

1. Buy orders and Sell orders are matched by their price. The highest price of the Buy orders is matched with the lowest price of the Sell orders.

2. If the amount of coins of the Buy order is greater than the amount of coins of the Sell order, the Buy order is partially filled. The Sell order is completely filled. The Buy order's amount is reduced. Sell Order is removed and put into the FilledBook

3. If the amount of coins of the Buy order is smaller than the amount of coins of the Sell order, the Buy order is completely filled. The Sell order is partially filled. The Sell order's amount is reduced. Buy Order is removed and put into the FilledBook

4. If the amount of coins of the Buy order is equal to the amount of coins of the Sell order, the Buy order is completely filled. The Sell order is completely filled. Both orders are removed and put into the FilledBook.


## Additional Notes

1. There are a ton other variables. Here we are using price as the main variable to match orders. But, we can use other variables like time stamp, amount of coins, etc. to match orders.

2. Real world scenario is much more complex. We have to consider the fees, taxes, etc. But, we are not considering those things here.


