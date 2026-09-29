# HackerRank 3rd Semester Portfolio

## Student Details

- **Student Name:** PRAJWAL SHRIKRISHNA NAIK
- **Student ID:** R25EF189
- **Programming Language:** Java
- **HackerRank Profile:** hackerrank.com/profile/prajwaln1904
- **GitHub Repository:** https://github.com/monkeydraco/Portfolio/tree/main/activity8

## About This Repository

This repository contains my Java solutions to five mandatory HackerRank problems completed as part of Activity 8 - HackerRank and GitHub Problem-Solving Portfolio.

The problems cover matrices, dynamic arrays, strings, hash maps, and basic algorithmic problem solving. Each solution focuses on clean implementation and efficient time and space complexity.

## Repository Structure

```text
HackerRank-3rdSem-Portfolio/
├── README.md
├── 01-Diagonal-Difference/
│   └── solution.java
├── 02-Dynamic-Array/
│   └── solution.java
├── 03-Time-Conversion/
│   └── solution.java
├── 04-Compare-the-Triplets/
│   └── solution.java
└── 05-Sparse-Arrays/
    └── solution.java
```

## Problems Solved

| No. | Problem | Topic | HackerRank Link | Solution |
|---|---|---|---|---|
| 1 | Diagonal Difference | 2D Arrays and Matrices | [Open Problem](https://www.hackerrank.com/challenges/diagonal-difference/problem) | [View Code](./01-Diagonal-Difference/solution.java) |
| 2 | Dynamic Array | Data Structures | [Open Problem](https://www.hackerrank.com/challenges/dynamic-array/problem) | [View Code](./02-Dynamic-Array/solution.java) |
| 3 | Time Conversion | Strings and Logic | [Open Problem](https://www.hackerrank.com/challenges/time-conversion/problem) | [View Code](./03-Time-Conversion/solution.java) |
| 4 | Compare the Triplets | Basic Implementation | [Open Problem](https://www.hackerrank.com/challenges/compare-the-triplets/problem) | [View Code](./04-Compare-the-Triplets/solution.java) |
| 5 | Sparse Arrays | Hash Maps and Strings | [Open Problem](https://www.hackerrank.com/challenges/sparse-arrays/problem) | [View Code](./05-Sparse-Arrays/solution.java) |

## Problem Approaches

### 1. Diagonal Difference

The matrix is traversed row by row. The primary diagonal is identified using `i == j`, while the secondary diagonal is identified using `i + j == n - 1`. The absolute difference between the two diagonal sums is returned.

### 2. Dynamic Array

A list of dynamic sequences is created. Type 1 queries append values to the selected sequence using the XOR operation. Type 2 queries retrieve a value from the selected sequence and update the last answer.

### 3. Time Conversion

The input time is separated into its hour, minute, second, and AM/PM components. The hour is adjusted according to the AM or PM format and returned in 24-hour format.

### 4. Compare the Triplets

Alice's and Bob's three values are compared position by position. Alice receives one point when her value is higher, and Bob receives one point when his value is higher.

### 5. Sparse Arrays

A hash map stores the frequency of every input string. Each query string is then searched in the map and its frequency is added to the result.

## Complexity Analysis

| Problem | Time Complexity | Space Complexity |
|---|---|---|
| Diagonal Difference | O(N) | O(1) |
| Dynamic Array | O(N + Q) | O(N) |
| Time Conversion | O(1) | O(1) |
| Compare the Triplets | O(1) | O(1) |
| Sparse Arrays | O(N + Q) | O(N) |

## HackerRank Submission Evidence

All five solutions were submitted on HackerRank and tested against the available test cases.

Evidence files are available in the [evidence folder](./evidence/).

- Diagonal Difference: All test cases passed
- Dynamic Array: All test cases passed
- Time Conversion: All test cases passed
- Compare the Triplets: All test cases passed
- Sparse Arrays: All test cases passed

## HackerRank Badge

The required 3-Star HackerRank badge is shown on my public HackerRank profile:

[View HackerRank Profile](https://www.hackerrank.com/your-username)

Badge evidence is included in the evidence folder and final PDF report.

## Learning Outcome

This activity improved my understanding of matrix traversal, dynamic arrays, string manipulation, hash maps, frequency counting, and algorithmic complexity. It also helped me practise writing clean Java solutions and maintaining a structured GitHub problem-solving portfolio.
