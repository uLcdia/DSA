## Task Description

The task is to find the maximum difference between any two numbers in an array such that the larger number appears before the smaller number in the array. Specifically, we need to find the maximum value of `array[i] - array[j]` where `i < j`.

For example, in the array `{2, 4, 1, 16, 7, 5, 11, 9}`, the maximum difference is `11`, which is obtained from `16 - 5`.

## Input Format

The input consists of two lines:
1.  The first line contains an integer *N* (N > 1), representing the number of elements in the array.
2.  The second line contains *N* integers, representing the elements of the array, separated by spaces.

```
N
a1 a2 a3 ... aN
```

## Output Format

The output should be a single line containing one integer, which is the maximum difference found.

```
max_difference
```

## Example

**Input:**

```
6
2 5 8 19 3 6
```

**Output:**

```
16
```

**Explanation:**

The possible differences `array[i] - array[j]` where `i < j` are:
*   5 - 3 = 2
*   5 - 6 = -1
*   8 - 3 = 5
*   8 - 6 = 2
*   19 - 3 = 16
*   19 - 6 = 13
*   3 - 6 = -3

The maximum difference among these is 16 (from 19 - 3).

## Grading Criteria

*   Correctly reads the input array size *N* and the array elements.
*   Correctly calculates the maximum difference `array[i] - array[j]` for all `i < j`.
*   Correctly outputs the maximum difference found.
