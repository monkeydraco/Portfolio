## Problem: Valid Anagram (Easy)

**Link:** https://leetcode.com/problems/valid-anagram/

### Approach

I counted the frequency of each character in both strings and compared the frequencies. If every character appears the same number of times in both strings, the strings are anagrams.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The strings must have the same length. Different character frequencies mean the strings are not anagrams.