## Task Description

The task is to determine whether a given integer array represents the post-order traversal of a binary search tree (BST). If the array is a valid post-order traversal of a BST, the program should return `true`; otherwise, it should return `false`. The solution must avoid brute-force methods to receive credit.

## Input Format

The input is a single line containing integers separated by spaces:

```
a1 a2 a3 ... an
```

where:

*   `a1, a2, a3, ..., an` are the integers in the array.

## Output Format

The output is a single line containing either `true` or `false`:

```
true
```

or

```
false
```

## Example

**Input:**

```
5 7 6 9 11 10 8
```

**Output:**

```
true
```

**Explanation:**

1.  The input array `5 7 6 9 11 10 8` represents the post-order traversal of the following binary search tree:

```
         8
       /  \
      6    10
    / \    / \
   5   7  9   11
```

2.  Since the array corresponds to a valid post-order traversal of a BST, the output is `true`.

**Input:**

```
7 4 6 5
```

**Output:**

```
false
```

**Explanation:**

1.  The input array `7 4 6 5` does not represent the post-order traversal of any binary search tree.
2.  Therefore, the output is `false`.

## Grading Criteria

*   Correctly parses the input array of integers.
*   Implements an efficient algorithm to verify whether the array represents the post-order traversal of a BST.
*   Avoids brute-force methods.
*   Outputs `true` or `false` based on the validity of the input array.