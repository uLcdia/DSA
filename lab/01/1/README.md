## Task Description

The task requires you to create a doubly linked circular list from a sequence of integers. The input consists of an integer *n* representing the number of integers to be stored in the list, followed by *n* integers. The integers from the second one onwards (a2, a3, ..., an) are guaranteed to be in ascending order (a2 < a3 < ... < an).

The program should first create the doubly linked circular list, storing the input integers in the nodes.  Then, it should remove the first node from the list and insert it back into the list at the appropriate position to make the entire list sorted in ascending order.

Finally, the program should output the integers stored in the nodes of the sorted doubly linked circular list, in ascending order, separated by spaces.

## Input Format

The input is given in the following format:

```
n a1 a2 a3 ... an
```

where:

*   *n* is an integer representing the number of integers.
*   *a1, a2, a3, ..., an* are the integers to be stored in the list.

## Output Format

The output should be a single line containing the integers stored in the sorted doubly linked circular list, in ascending order, separated by spaces.

```
x1 x2 x3 ... xn
```

where *x1, x2, x3, ..., xn* are the integers in ascending order.

## Example

**Input:**

```
5 3 1 2 4 5
```

**Output:**

```
1 2 3 4 5
```

**Explanation:**

1.  The input `5 3 1 2 4 5` indicates that there are 5 integers to be stored.
2.  The integers are `3`, `1`, `2`, `4`, and `5`.
3.  The initial doubly linked circular list is created with these integers.
4.  The node containing `3` (the first integer) is removed.
5.  The node containing `3` is inserted back into the list at the appropriate position to maintain the ascending order, which is between `2` and `4`.
6.  The final sorted doubly linked circular list is `1 -> 2 -> 3 -> 4 -> 5 -> 1`.
7.  The output is `1 2 3 4 5`.

## Grading Criteria

*   Correctly creates a doubly linked circular list from the input integers.
*   Correctly removes the first node from the list.
*   Correctly inserts the removed node back into the list at the appropriate position to ensure the list is sorted in ascending order.
*   Correctly outputs the integers stored in the sorted list, in ascending order, separated by spaces.

## Link

[GitHub](https://github.com/uLcdia/dsa/lab/01/1)