## Problem: Valid Parentheses (Easy)

**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach

I used a stack to store opening brackets. Whenever I found a closing bracket, I checked whether it matched the most recent opening bracket on the stack.

### Complexity

- Time: O(n)
- Space: O(n)

### Notes

The brackets must close in the correct order. An input with only opening brackets or an incorrectly ordered pair is invalid.