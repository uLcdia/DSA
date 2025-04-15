## Task Description

The task requires you to find the k-th node from the end of a singly linked list. The last node of the list is considered the 1st node from the end.

The program should first construct a singly linked list from the input sequence of integers. Then, it should determine the k-th node from the end of the list and output its value. If the k-th node does not exist, the program should output "Not Found".

## Input Format

The input is given in the following format:

```
k a1 a2 a3 ... an
```

where:

*   *k* is an integer representing the position from the end of the list.
*   *a1, a2, a3, ..., an* are the integers to be stored in the singly linked list.

## Output Format

The output should be a single line containing the value of the k-th node from the end of the list. If the k-th node does not exist, output "Not Found".

```
x
```

where *x* is the value of the k-th node from the end, or "Not Found" if the node does not exist.

## Example

**Input:**

```
3 13 45 54 32 1 4 98 2
```

**Output:**

```
4
```

**Explanation:**

1.  The input `3 13 45 54 32 1 4 98 2` indicates that the k value is 3 and the integers to be stored in the list are `13`, `45`, `54`, `32`, `1`, `4`, `98`, and `2`.
2.  A singly linked list is created with these integers.
3.  The 3rd node from the end of the list is the node containing the value `4`.
4.  The output is `4`.

## Grading Criteria

*   Correctly constructs a singly linked list from the input integers.
*   Correctly identifies the k-th node from the end of the list.
*   Outputs the value of the k-th node from the end, or "Not Found" if the node does not exist.