## Problem: Binary Search (Easy)

**Link:** https://leetcode.com/problems/binary-search/

### Approach

I used two pointers to represent the current search range. I checked the middle element and removed either the left or right half depending on whether the target was smaller or larger.

### Complexity

- Time: O(log n)
- Space: O(1)

### Notes

Binary search only works correctly when the input array is sorted. If the target is not found, the result should be -1.