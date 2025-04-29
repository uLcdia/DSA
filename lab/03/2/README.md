## Task Description

The task is to construct a Binary Search Tree (BST) from a given sequence of integers. After building the BST, perform an in-order traversal of the tree to obtain the integers in ascending order. The program must use a BST for sorting; other sorting algorithms will not receive credit.

## Input Format

The input consists of two lines:

1.  The first line contains a single integer *n*, representing the number of integers in the sequence.
2.  The second line contains *n* integers, separated by spaces.

```
n
d1 d2 d3 ... dn
```

where:

*   *n* is the number of integers.
*   *d1, d2, d3, ..., dn* are the integers to be inserted into the BST.

## Output Format

Output a single line containing the integers from the input sequence, sorted in ascending order, separated by spaces. This sorted sequence should be obtained by performing an in-order traversal of the constructed BST.

```
x1 x2 x3 ... xn
```

where *x1, x2, x3, ..., xn* are the input integers sorted in ascending order.

## Example

**Input:**

```
5
22 -15 4 89 30
```

**Output:**

```
-15 4 22 30 89
```

**Explanation:**

1.  The input indicates 5 integers: `22`, `-15`, `4`, `89`, `30`.
2.  These integers are inserted one by one into a Binary Search Tree.
    *   Insert 22 (root)
    *   Insert -15 (left child of 22)
    *   Insert 4 (right child of -15)
    *   Insert 89 (right child of 22)
    *   Insert 30 (left child of 89)
3.  An in-order traversal of the resulting BST visits the nodes in the order: `-15`, `4`, `22`, `30`, `89`.
4.  The output is the sequence obtained from the in-order traversal, which represents the sorted data.

## Grading Criteria

*   Correctly reads the input count and the sequence of integers.
*   Correctly implements the construction of a Binary Search Tree by inserting the input integers.
*   Correctly performs an in-order traversal of the constructed BST.
*   Outputs the integers obtained from the in-order traversal (sorted sequence) separated by spaces.
*   **Crucially, the sorting must be achieved using a Binary Search Tree and its in-order traversal. Using other sorting algorithms (like bubble sort, quicksort, `std::sort`, etc.) directly on the input data is not permitted for this specific task.**
