## Problem: Two Sum (Easy)

**Link:** https://leetcode.com/problems/two-sum/

### Approach

I used a hash map to store each number and its index while traversing the array. For every number, I checked whether its required complement already existed in the hash map.

### Complexity

- Time: O(n)
- Space: O(n)

### Notes

The solution must handle duplicate values and must not use the same element twice.