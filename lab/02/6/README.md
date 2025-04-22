## Task Description

The task is to find all possible ways to represent a given integer *N* as a sum of consecutive integers. Some integers can be decomposed into sums of consecutive integers in multiple ways, while others cannot be decomposed at all.

For example:
*   15 = 1 + 2 + 3 + 4 + 5
*   15 = 4 + 5 + 6
*   15 = 7 + 8

An integer like 16 cannot be decomposed into a sum of consecutive integers.

The program should read an integer *N* and output all its consecutive integer sum decompositions.

## Input Format

The input consists of a single line containing one integer *N*.

```
N
```

where `1 <= N <= 10000`.

## Output Format

The output should list all decompositions found for *N*. Each decomposition should be printed on a separate line. The integers within each decomposition should be printed in ascending order, separated by spaces, with a trailing space at the end of the line.

The decompositions should be ordered by the number of integers in the sum, from the longest sequence to the shortest sequence.

If no such decomposition exists for *N*, the output should be a single line containing `NONE`.

## Example 1

**Input:**

```
15
```

**Output:**

```
1 2 3 4 5
4 5 6
7 8
```

## Example 2

**Input:**

```
16
```

**Output:**

```
NONE
```

## Grading Criteria

*   Correctly reads the input integer *N*.
*   Correctly finds all possible consecutive integer sum decompositions for *N*.
*   Correctly formats the output according to the specified requirements (order of decompositions, order of integers within a decomposition, spacing).
*   Correctly outputs `NONE` when no decomposition exists.
