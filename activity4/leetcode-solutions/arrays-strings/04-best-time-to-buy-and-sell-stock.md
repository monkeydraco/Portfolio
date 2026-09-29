## Problem: Best Time to Buy and Sell Stock (Easy)

**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach

I tracked the lowest stock price seen so far while scanning the array. For each price, I calculated the possible profit and kept the maximum profit found.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The stock must be bought before it is sold. If no profit is possible, the answer is 0.