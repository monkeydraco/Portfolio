## Problem: Move Zeroes (Easy)

**Link:** https://leetcode.com/problems/move-zeroes/

### Approach

I used a pointer to track the position where the next non-zero value should be placed. I moved all non-zero values forward and filled the remaining positions with zeroes.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The relative order of the non-zero values must remain unchanged. The array should be modified in place.