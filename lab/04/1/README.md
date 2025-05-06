## Task Description

The task is to perform an insertion sort on a sequence of integers and output the intermediate results after each pass of the algorithm. The input consists of an integer *n* followed by *n* integers to be sorted. The program should output the state of the array after each of the first *n-1* passes of the insertion sort.

## Input Format

The input is given in the following format:

```
n a1 a2 a3 ... an
```

where:

*   *n* is an integer representing the number of integers to be sorted.
*   *a1, a2, a3, ..., an* are the integers to be sorted.

## Output Format

The output consists of *n-1* lines, each containing the state of the array after a pass of the insertion sort. The integers in each line are separated by spaces.

```
pass_1
pass_2
...
pass_n-1
```

where *pass_i* represents the state of the array after the *i*-th pass of the insertion sort.

## Example

**Input:**

```
5 3 1 4 2 5
```

**Output:**

```
1 3 4 2 5
1 3 4 2 5
1 2 3 4 5
1 2 3 4 5
```

**Explanation:**

1.  The input `5 3 1 4 2 5` indicates that there are 5 integers to be sorted: `3`, `1`, `4`, `2`, and `5`.
2.  The insertion sort algorithm sorts the array step by step:
    *   After the 1st pass: `1 3 4 2 5`
    *   After the 2nd pass: `1 3 4 2 5`
    *   After the 3rd pass: `1 2 3 4 5`
    *   After the 4th pass: `1 2 3 4 5`
3.  The output consists of the intermediate results after each of the first 4 passes.

## Grading Criteria

*   Correctly parses the input sequence of integers.
*   Correctly implements the insertion sort algorithm.
*   Outputs the state of the array after each pass of the insertion sort, up to the *n-1*-th pass.
*   Each line of the output corresponds to the state of the array after a single pass, with integers separated by spaces.