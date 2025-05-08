## Task Description

The task is to perform a binary search on a sorted (ascending) array of integers to find the position (index) of a given key value k. The program should also output the sequence of middle values checked during the search process.

## Input Format

- The first line contains an integer N, the number of elements in the array.
- The second line contains N integers separated by commas, representing the sorted array A.
- The third line contains the integer k, the key to search for.

## Output Format

- The first line outputs the index of k in the array if found; otherwise, output `no`.
- The second line outputs the sequence of values at the middle (mid) positions checked during the binary search, separated by commas.

## Example

**Input:**
```
11
2,5,8,11,15,16,22,24,27,35,50
22
```

**Output:**
```
6
16,27,22
```

**Input:**
```
11
2,5,8,11,15,16,22,24,27,35,50
10
```

**Output:**
```
no
16,8,11
```

## Grading Criteria

* Correctly parses the input array and key value.
* Correctly implements the binary search algorithm (other methods will not receive credit).
* Outputs the correct index or `no` if the key is not found.
* Outputs the sequence of middle values checked during the search, separated by commas.
