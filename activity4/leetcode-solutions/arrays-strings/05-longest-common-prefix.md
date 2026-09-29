## Problem: Longest Common Prefix (Easy)

**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach

I used the first string as the initial prefix and compared it with every other string. Whenever a string did not start with the current prefix, I shortened the prefix until it matched.

### Complexity

- Time: O(S), where S is the total number of characters
- Space: O(1)

### Notes

If the strings have no common beginning, the result is an empty string. An empty input list should also return an empty string.